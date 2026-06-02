#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QFileInfo>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // for editing nr code ID
    connect(ui->lineEditCodeID, &QLineEdit::textChanged,
            this, &MainWindow::onCodeIDChanged);

    // 1. Ensure we start on the home page
    ui->stackedWidget->setCurrentWidget(ui->page_home);

    // 2. Home page navigation: Local mode
    connect(ui->btnLocal, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_local);
    });

    // 3. Home page navigation: Remote mode (SSH)
    connect(ui->btnRemote, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_remote);
    });

    // mesh selector logic
    connect(ui->btnBrowseMesh, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Select Mesh File",
            "",
            "Mesh Files (*.e *.msh *.mesh *.vtk);;All Files (*)"
            );

        if (!fileName.isEmpty()) {
            ui->lineMeshPath->setText(fileName);
        }
    });
    ui->lineMeshPath->setReadOnly(true);
    connect(ui->lineMeshPath, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                meshFile = text;
            });


    // stations selector logic
    connect(ui->btnBrowseStations, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Select Stations File",
            "",
            "Data Files (*.txt *.dat *.csv);;All Files (*)"
            );

        if (!fileName.isEmpty()) {
            ui->lineStationsPath->setText(fileName);
        }
    });
    ui->lineStationsPath->setReadOnly(true);
    connect(ui->lineStationsPath, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                stationsFile = text;
            });

    // buttons for settings on local page
    connect(ui->btnAdvanced, &QPushButton::clicked, this, [=]() {
        ui->stackedLocalSections->setCurrentWidget(ui->page_advanced);
    });

    connect(ui->btnModel, &QPushButton::clicked, this, [=]() {
        ui->stackedLocalSections->setCurrentWidget(ui->page_model);
    });

    connect(ui->btnNr, &QPushButton::clicked, this, [=]() {
        ui->stackedLocalSections->setCurrentWidget(ui->page_nr);
    });

    connect(ui->btnOutput, &QPushButton::clicked, this, [=]() {
        ui->stackedLocalSections->setCurrentWidget(ui->page_output);
    });

    connect(ui->btnSource, &QPushButton::clicked, this, [=]() {
        ui->stackedLocalSections->setCurrentWidget(ui->page_source);
    });

    connect(ui->btnModel3D, &QPushButton::clicked, this, [=]() {
        ui->stackedLocalSections->setCurrentWidget(ui->page_3d);
    });

    connect(ui->btnBackL, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_home);
    });

    connect(ui->btnBackR, &QPushButton::clicked, this, [=]() {
        m_isRemoteMode = false;
        ui->labelSSHStatus->clear();
        ui->stackedWidget->setCurrentWidget(ui->page_home);
    });

    // SSH connect button
    connect(ui->btnSSHConnect, &QPushButton::clicked,
            this, &MainWindow::onSSHConnect);

    // all settings are defaulted to example 02

    // for advanced file
    ui->comboVerboseChannel->setCurrentText("STDOUT");
    connect(ui->comboVerboseChannel, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                adv_verboseChannelType = text;
            });

    connect(ui->btnBrowseVerboseChannel, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Select Verbose Channel File",
            "",
            "All Files (*)"
            );

        if (!fileName.isEmpty()) {
            ui->lineVerboseChannelPath->setText(fileName);
        }
    });
    ui->lineVerboseChannelPath->setReadOnly(true);
    connect(ui->lineVerboseChannelPath, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                adv_verboseFile = text;
            });

    ui->comboVerboseLevel->setCurrentText("ESSENTIAL");
    connect(ui->comboVerboseLevel, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                adv_verboseLevel = text;
            });

    ui->checkVerboseWarnings->setChecked(true);
    connect(ui->checkVerboseWarnings, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                adv_verboseWarnings = checked;
            });

    ui->lineLoopInterval->setText("1000");
    connect(ui->lineLoopInterval, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                adv_loopInterval = text;
            });

    ui->lineStabilityInterval->setText("1");
    connect(ui->lineStabilityInterval, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                adv_stabilityInterval = text;
            });

    ui->lineNumProcessorsPerGroup->setText("1");
    connect(ui->lineNumProcessorsPerGroup, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                adv_numProcessors = text;
            });

    ui->loadBalancingBox->setCurrentText("ELEMENT_POINT");
    connect(ui->loadBalancingBox, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                adv_loadBalancing = text;
            });

    ui->checkBoxPlotDomainDecomp->setChecked(false);
    connect(ui->checkBoxPlotDomainDecomp, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                adv_plotDomainDecomp = checked;
            });

    ui->checkBoxDiagnosePreloop->setChecked(true);
    connect(ui->checkBoxDiagnosePreloop, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                adv_diagnosePreloop = checked;
            });

    ui->lineMaxNumTimeSteps->setText("0");
    connect(ui->lineMaxNumTimeSteps, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                adv_maxTimeSteps = text;
            });

    ui->lineTimeLimitFFTW->setText("60");
    connect(ui->lineTimeLimitFFTW, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                adv_timeLimitFFTW = text;
            });

    ui->checkBoxFFTWLuckyNum->setChecked(true);
    connect(ui->checkBoxFFTWLuckyNum, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                adv_FFTWLuckyNum = checked;
            });


    // for model file
    ui->comboBoxLatLongNP->setCurrentText("Array (Type Under)");
    connect(ui->comboBoxLatLongNP, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                model_latLongNP = text;
            });

    ui->lineEditNP->setText("[90., 0.]");
    connect(ui->lineEditNP, &QLineEdit::textChanged,
            this, [&](const QString &text) {
               model_NP = text;
            });

    ui->comboBoxFlatteningSurface->setCurrentText("Custom Number");
    connect(ui->comboBoxFlatteningSurface, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                model_flatteningSurface = text;
            });

    ui->lineFlatteningCustomNum->setText("0.0033");
    connect(ui->lineFlatteningCustomNum, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                model_flatteningNum = text;
            });

    ui->lineBoundaries->setText("[RIGHT, BOTTOM]");
    connect(ui->lineBoundaries, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                model_boundaries = text;
            });

    ui->checkBoxClayton->setChecked(true);
    connect(ui->checkBoxClayton, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                model_clayton = checked;
            });

    ui->checkBoxKosloff->setChecked(true);
    connect(ui->checkBoxKosloff, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                model_Kosloff = checked;
            });

    ui->lineRelativeSpans->setText("[.05, .05]");
    connect(ui->lineRelativeSpans, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                model_relativeSpans = text;
            });

    ui->lineGammaSolid->setText("1.1 / T0 * (VS / VP)^2 * exp(-0.04 * SPAN / (VP * T0))");
    connect(ui->lineGammaSolid, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                model_gammaSolid = text;
            });

    ui->lineGammaFluid->setText("0.88 / T0 * exp(-0.04 * SPAN / (VP * T0))");
    connect(ui->lineGammaFluid, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                model_gammaFluid = text;
            });

    ui->attenuationBox->setCurrentText("CG4");
    connect(ui->attenuationBox, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                model_attenuation = text;
            });


    // for 3D model file
    ui->boxHowMany3D->setValue(1);
    ui->boxHowMany3D->setMinimum(1);
    ui->boxHowMany3D->setMaximum(6);

    connect(ui->boxHowMany3D, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::onModelCountChanged);

    // create the first model widget to match the initial spinbox value
    onModelCountChanged(1);


    // for output file
    connect(ui->spinStationGroupCount, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::onStationGroupCountChanged);

    // create the first station group to match the initial spinbox value
    onStationGroupCountChanged(ui->spinStationGroupCount->value());


    // for source file — time axis
    ui->lineRecordLength->setText("1800.");
    connect(ui->lineRecordLength, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                src_recordLength = text;
            });

    ui->lineEnforcedDt->setText("NONE");
    connect(ui->lineEnforcedDt, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                src_enforcedDt = text;
            });

    ui->lineCourantNumber->setText("0.6");
    connect(ui->lineCourantNumber, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                src_courantNumber = text;
            });

    ui->comboIntegrator->setCurrentText("NEWMARK");
    connect(ui->comboIntegrator, &QComboBox::currentTextChanged,
            this, [&](const QString &text) {
                src_integrator = text;
            });

    // for source file — source list
    connect(ui->spinSourceCount, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::onSourceCountChanged);

    // create the first source to match the initial spinbox value
    onSourceCountChanged(ui->spinSourceCount->value());


    // for nr file
    ui->comboBoxNrType->setCurrentText("CONSTANT");
    connect(ui->comboBoxNrType, &QComboBox::currentTextChanged,
            this, [&](const QString &text)
            {
                nr_nrType = text;
            });

    ui->checkBoxNrInplane->setChecked(true);
    connect(ui->checkBoxNrInplane, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                nr_inplane = checked;
            });

    ui->lineConstNr->setText("100");
    connect(ui->lineConstNr, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_constNr = text;
            });

    ui->lineEditCodeID->setText("depth-dependent (AxiSEM3D default)");
    connect(ui->lineEditCodeID, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_codeID = text;
            });

    ui->lineNrControlDepths->setText("[0., 50e3, 100e3, 6371e3]");
    connect(ui->lineNrControlDepths, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_controlDepths = text;
            });

    ui->lineNrAtControlDepths->setText("[100, 100, 50, 50]");
    connect(ui->lineNrAtControlDepths, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_controlAtDepths = text;
            });

    connect(ui->btnBrowsePointwise, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Select netcdf Data File",
            "",
            "Data Files (*.nc);;All Files (*)"
            );

        if (!fileName.isEmpty()) {
            ui->linePointwisePath->setText(fileName);
        }
    });
    ui->linePointwisePath->setReadOnly(true);
    connect(ui->linePointwisePath, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_pointwiseFile = text;
            });

    ui->lineNrFactor->setText("1.");
    connect(ui->lineNrFactor, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_pointwiseNrFactor = text;
            });

    connect(ui->pushBrowseStructured, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Select netcdf Data File",
            "",
            "netcdf Files (*.nc);;All Files (*)"
            );

        if (!fileName.isEmpty()) {
            ui->lineStructuredPath->setText(fileName);
        }
    });
    ui->lineStructuredPath->setReadOnly(true);
    connect(ui->lineStructuredPath, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_structuredFile = text;
            });

    ui->lineStructuredOutOfRange->setText("5");
    connect(ui->lineStructuredOutOfRange, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_structuredOutOfRange = text;
            });

    ui->checkWavefieldScanningOn->setChecked(false);
    connect(ui->checkWavefieldScanningOn, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                nr_wavefieldScanning = checked;
            });

    ui->lineWavefieldOutputFile->setText("");
    connect(ui->lineWavefieldOutputFile, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_wavefieldOutputFile = text;
            });

    ui->lineThresholdFourierConv->setText("0.01");
    connect(ui->lineThresholdFourierConv, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_thresholdFourierConv = text;
            });

    ui->lineRelativeAmpSkip->setText("0.1");
    connect(ui->lineRelativeAmpSkip, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_relativeAmpSkip = text;
            });

    ui->lineAbsAmpSkip->setText("1e-12");
    connect(ui->lineAbsAmpSkip, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_absAmpSkip = text;
            });

    ui->lineMaxNumPeaks->setText("10000");
    connect(ui->lineMaxNumPeaks, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_maxNumPeaks = text;
            });

    ui->checkScanOnlyVertexGLL->setChecked(true);
    connect(ui->checkScanOnlyVertexGLL, &QCheckBox::toggled,
            this, [&](bool checked)
            {
                nr_scanOnlyVertexGLL = checked;
            });

    ui->lineNumStepsPerMeshPeriod->setText("12");
    connect(ui->lineNumStepsPerMeshPeriod, &QLineEdit::textChanged,
            this, [&](const QString &text) {
                nr_numStepsPerMeshPeriod = text;
            });


    // ── Run page wiring ──
    connect(ui->btnBrowseExe, &QPushButton::clicked, this, [=]() {
        QString fileName = QFileDialog::getOpenFileName(
            this, "Locate AxiSEM3D Executable", "",
#ifdef Q_OS_WIN
            "Executables (*.exe);;All Files (*)"
#else
            "All Files (*)"
#endif
            );
        if (!fileName.isEmpty())
            ui->lineExePath->setText(fileName);
    });

    // show/hide batch job section based on remote mode and checkbox
    auto updateBatchVisibility = [=]() {
        bool show = m_isRemoteMode && ui->checkBatchJob->isChecked();
        ui->lblBatchFilename->setVisible(show);
        ui->lineBatchFilename->setVisible(show);
        ui->editBatchScript->setVisible(show);
        ui->grpBatchJob->setVisible(m_isRemoteMode);
        ui->lblMpiProcs->setVisible(!m_isRemoteMode || !ui->checkBatchJob->isChecked());
        ui->spinMpiProcs->setVisible(!m_isRemoteMode || !ui->checkBatchJob->isChecked());
    };

    connect(ui->checkBatchJob, &QCheckBox::toggled, this, updateBatchVisibility);

    // initial visibility (local mode by default)
    ui->grpBatchJob->setVisible(false);

    connect(ui->btnRunSim, &QPushButton::clicked,
            this, &MainWindow::onRunSimulation);
    connect(ui->btnStopSim, &QPushButton::clicked,
            this, &MainWindow::onStopSimulation);

    connect(ui->btnBackRun, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_local);
    });

    // when navigating to run page, update batch visibility
    connect(ui->btnRun, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentWidget(ui->page_run);
        // update batch job visibility based on current mode
        bool show = m_isRemoteMode && ui->checkBatchJob->isChecked();
        ui->lblBatchFilename->setVisible(show);
        ui->lineBatchFilename->setVisible(show);
        ui->editBatchScript->setVisible(show);
        ui->grpBatchJob->setVisible(m_isRemoteMode);
        ui->lblMpiProcs->setVisible(!m_isRemoteMode || !ui->checkBatchJob->isChecked());
        ui->spinMpiProcs->setVisible(!m_isRemoteMode || !ui->checkBatchJob->isChecked());
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onCodeIDChanged(const QString &text)
{
    QString result = text;

    result.replace(" ", "_");
    result.replace("-", "_");
    result.remove("(");
    result.remove(")");

    if (!result.isEmpty() && !result.endsWith(":"))
    {
        result.append(":");
    }

    ui->labelCodeID->setText(result);
}

void MainWindow::onModelCountChanged(int count)
{
    // add widgets until we have enough
    while (m_modelWidgets.size() < count) {
        int idx = m_modelWidgets.size();
        auto *w = new Model3DWidget(idx, ui->scrollAreaContents3D);
        // insert before the trailing spacer
        ui->layout3DModels->insertWidget(idx, w);
        m_modelWidgets.push_back(w);
    }

    // remove widgets from the end if we have too many
    while (m_modelWidgets.size() > count) {
        Model3DWidget *w = m_modelWidgets.takeLast();
        ui->layout3DModels->removeWidget(w);
        delete w;
    }
}

void MainWindow::onSSHConnect()
{
    QString host = ui->lineSSHHost->text().trimmed();
    QString port = ui->lineSSHPort->text().trimmed();
    QString user = ui->lineSSHUser->text().trimmed();

    // ── basic validation ──
    if (host.isEmpty() || user.isEmpty()) {
        ui->labelSSHStatus->setStyleSheet("color: red;");
        ui->labelSSHStatus->setText("Host and username are required.");
        return;
    }

    // ── show "connecting..." feedback ──
    ui->labelSSHStatus->setStyleSheet("color: black;");
    ui->labelSSHStatus->setText("Connecting...");
    ui->btnSSHConnect->setEnabled(false);
    // force the UI to repaint before blocking on the process
    QCoreApplication::processEvents();

    // ── build the ssh test command ──
    // We run:  ssh -o BatchMode=yes -o ConnectTimeout=8
    //              -p <port> user@host "echo __AXISEM_OK__"
    //
    // BatchMode=yes prevents interactive password prompts so the
    // process returns quickly on auth failure.  If the user's key is
    // already in the agent / authorized_keys this will succeed.
    // For password auth the user needs sshpass on PATH (see below).

    QStringList sshArgs;
    sshArgs << "-o" << "BatchMode=yes"
            << "-o" << "ConnectTimeout=8"
            << "-o" << "StrictHostKeyChecking=accept-new"
            << "-p" << (port.isEmpty() ? "22" : port)
            << (user + "@" + host)
            << "echo __AXISEM_OK__";

    QString password = ui->lineSSHPass->text();

    QProcess proc;
    proc.setProcessChannelMode(QProcess::MergedChannels);

    if (!password.isEmpty()) {
        // If a password was entered, try using sshpass
        // (must be on PATH; common on Linux, available via brew/choco)
        proc.start("sshpass",
                    QStringList() << "-p" << password << "ssh" << sshArgs);
    } else {
        proc.start("ssh", sshArgs);
    }

    // wait up to 15 seconds for the whole thing to finish
    bool finished = proc.waitForFinished(15000);
    QString output = QString::fromUtf8(proc.readAll()).trimmed();

    ui->btnSSHConnect->setEnabled(true);

    if (!finished || proc.exitCode() != 0 || !output.contains("__AXISEM_OK__")) {
        // ── failure ──
        QString errMsg = "Connection failed.";
        if (!output.isEmpty())
            errMsg += "\n" + output;
        if (!finished)
            errMsg = "Connection timed out.";

        ui->labelSSHStatus->setStyleSheet("color: red;");
        ui->labelSSHStatus->setText(errMsg);

        QMessageBox::warning(this, "SSH Connection Failed",
                             errMsg + "\n\nPlease check your credentials and try again.");
        return;
    }

    // ── success: go to the config page (same as local) ──
    m_isRemoteMode = true;
    ui->labelSSHStatus->setStyleSheet("color: green;");
    ui->labelSSHStatus->setText("Connected!");

    ui->stackedWidget->setCurrentWidget(ui->page_local);
}

void MainWindow::onStationGroupCountChanged(int count)
{
    // add widgets until we have enough
    while (m_outputGroupWidgets.size() < count) {
        int idx = m_outputGroupWidgets.size();
        auto *w = new OutputGroupWidget(idx, ui->scrollAreaContentsOutput);
        // insert before the trailing spacer
        ui->layoutOutputGroups->insertWidget(idx, w);
        m_outputGroupWidgets.push_back(w);
    }

    // remove widgets from the end if we have too many
    while (m_outputGroupWidgets.size() > count) {
        OutputGroupWidget *w = m_outputGroupWidgets.takeLast();
        ui->layoutOutputGroups->removeWidget(w);
        delete w;
    }
}

void MainWindow::onSourceCountChanged(int count)
{
    // add widgets until we have enough
    while (m_sourceWidgets.size() < count) {
        int idx = m_sourceWidgets.size();
        auto *w = new SourceWidget(idx, ui->scrollAreaContentsSource);
        // insert before the trailing spacer
        ui->layoutSources->insertWidget(idx, w);
        m_sourceWidgets.push_back(w);
    }

    // remove widgets from the end if we have too many
    while (m_sourceWidgets.size() > count) {
        SourceWidget *w = m_sourceWidgets.takeLast();
        ui->layoutSources->removeWidget(w);
        delete w;
    }
}

// ── helper: copy a file into the input directory ──
void MainWindow::copyFileToInput(const QString &srcPath, const QString &inputDir)
{
    if (srcPath.isEmpty()) return;
    QFileInfo fi(srcPath);
    QString dest = inputDir + "/" + fi.fileName();
    if (QFile::exists(dest))
        QFile::remove(dest);
    QFile::copy(srcPath, dest);
}

// ── generate all 5 YAML input files ──
void MainWindow::generateYamlFiles(const QString &inputDir)
{
    // --- inparam.advanced.yaml ---
    {
        QFile f(inputDir + "/inparam.advanced.yaml");
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream s(&f);
        s << "# inparam.advanced.yaml\n\n";
        s << "verbose:\n";
        s << "    channel: " << adv_verboseChannelType << "\n";
        if (adv_verboseChannelType == "File")
            s << "    channel_file: " << QFileInfo(adv_verboseFile).fileName() << "\n";
        s << "    level: " << adv_verboseLevel << "\n";
        s << "    warnings: " << (adv_verboseWarnings ? "true" : "false") << "\n";
        s << "    loop_info_interval: " << adv_loopInterval << "\n";
        s << "    stability_interval: " << adv_stabilityInterval << "\n";
        s << "\n";
        s << "mpi:\n";
        s << "    nproc_per_group: " << adv_numProcessors << "\n";
        s << "    weight: " << adv_loadBalancing << "\n";
        s << "    plot_domain_decomposition: " << (adv_plotDomainDecomp ? "true" : "false") << "\n";
        s << "\n";
        s << "develop:\n";
        s << "    diagnose_preloop: " << (adv_diagnosePreloop ? "true" : "false") << "\n";
        s << "    max_num_time_steps: " << adv_maxTimeSteps << "\n";
        s << "    time_limit_for_fftw_planning: " << adv_timeLimitFFTW << "\n";
        s << "    fftw_lucky_numbers: " << (adv_FFTWLuckyNum ? "true" : "false") << "\n";
    }

    // --- inparam.model.yaml ---
    {
        QFile f(inputDir + "/inparam.model.yaml");
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream s(&f);
        s << "# inparam.model.yaml\n\n";
        s << "geodesy:\n";
        s << "    lat_lon_north_pole_mesh: " << model_latLongNP << "\n";
        if (model_latLongNP == "Array (Type Under)")
            s << "    lat_lon_north_pole_value: " << model_NP << "\n";
        s << "    flattening_on_surface: " << model_flatteningSurface << "\n";
        if (model_flatteningSurface == "Custom Number")
            s << "    flattening_custom: " << model_flatteningNum << "\n";
        s << "\n";
        s << "absorbing_boundary:\n";
        s << "    boundaries: " << model_boundaries << "\n";
        s << "    enable_Clayton_Enquist: " << (model_clayton ? "true" : "false") << "\n";
        s << "    Kosloff_Kosloff:\n";
        s << "        enable: " << (model_Kosloff ? "true" : "false") << "\n";
        s << "        relative_spans: " << model_relativeSpans << "\n";
        s << "        gamma_expr_solid: " << model_gammaSolid << "\n";
        s << "        gamma_expr_fluid: " << model_gammaFluid << "\n";
        s << "\n";
        s << "attenuation: " << model_attenuation << "\n";
        s << "\n";

        // 3D models
        s << "list_of_3D_models:\n";
        for (auto *mw : m_modelWidgets) {
            s << "    - name: " << mw->modelName() << "\n";
            s << "      activated: " << (mw->activated() ? "true" : "false") << "\n";
            s << "      class_name: " << mw->className() << "\n";
            s << "      nc_data_file: " << QFileInfo(mw->ncDataFile()).fileName() << "\n";
            QString cls = mw->className();
            if (cls == "StructuredGridV3D" || cls == "StructuredGridG3D" || cls == "StructuredGridO3D") {
                s << "      coordinates:\n";
                s << "          horizontal: " << mw->coordHorizontal() << "\n";
                s << "          vertical: " << mw->coordVertical() << "\n";
                s << "          ellipticity: " << (mw->coordEllipticity() ? "true" : "false") << "\n";
                s << "          depth_below_solid_surface: " << (mw->coordDepthBelowSolid() ? "true" : "false") << "\n";
                s << "          nc_variables: " << mw->coordNcVariables() << "\n";
                s << "          data_rank: " << mw->coordDataRank() << "\n";
                s << "          length_unit: " << mw->coordLengthUnit() << "\n";
                s << "          angle_unit: " << mw->coordAngleUnit() << "\n";
                s << "          undulated_geometry: " << (mw->coordUndulatedGeometry() ? "true" : "false") << "\n";
                s << "          whole_element_inplane: " << (mw->coordWholeElementInplane() ? "true" : "false") << "\n";
            }
            if (cls == "StructuredGridV3D") {
                s << "      properties:\n";
                for (const auto &pr : mw->propertyRows()) {
                    s << "          - name: " << pr.lineName->text() << "\n";
                    s << "            nc_var: " << pr.lineNcVar->text() << "\n";
                    s << "            factor: " << pr.lineFactor->text() << "\n";
                    s << "            reference_kind: " << pr.comboRefKind->currentText() << "\n";
                }
            }
            if (cls == "StructuredGridG3D") {
                s << "      undulation:\n";
                s << "          interface: " << mw->undulationInterface() << "\n";
                s << "          min_max: " << mw->undulationMinMax() << "\n";
                s << "          nc_var: " << mw->undulationNcVar() << "\n";
                s << "          factor: " << mw->undulationFactor() << "\n";
            }
            if (cls == "StructuredGridO3D") {
                s << "      ocean_load:\n";
                s << "          nc_var: " << mw->oceanNcVar() << "\n";
                s << "          factor: " << mw->oceanFactor() << "\n";
            }
            s << "      store_grid_on_leaders: " << (mw->storeOnLeaders() ? "true" : "false") << "\n";
        }
    }

    // --- inparam.nr.yaml ---
    {
        QFile f(inputDir + "/inparam.nr.yaml");
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream s(&f);
        s << "# inparam.nr.yaml\n\n";
        s << "type_Nr: " << nr_nrType << "\n";
        s << "bound_Nr_by_inplane: " << (nr_inplane ? "true" : "false") << "\n";
        s << "\n";
        s << "constant:\n";
        s << "    value: " << nr_constNr << "\n";
        s << "\n";
        s << "analytical:\n";
        s << "    code_ID: " << nr_codeID << "\n";
        s << "    control_depths: " << nr_controlDepths << "\n";
        s << "    Nr_at_control_depths: " << nr_controlAtDepths << "\n";
        // UDP fields from udpWidget would go here
        s << "\n";
        s << "pointwise:\n";
        s << "    nc_data_file: " << QFileInfo(nr_pointwiseFile).fileName() << "\n";
        s << "    factor: " << nr_pointwiseNrFactor << "\n";
        s << "\n";
        s << "structured:\n";
        s << "    nc_data_file: " << QFileInfo(nr_structuredFile).fileName() << "\n";
        s << "    Nr_out_of_range: " << nr_structuredOutOfRange << "\n";
        s << "\n";
        s << "wavefield_scanning:\n";
        s << "    enable_scanning: " << (nr_wavefieldScanning ? "true" : "false") << "\n";
        s << "    output_file: " << nr_wavefieldOutputFile << "\n";
        s << "    threshold_Fourier_convergence: " << nr_thresholdFourierConv << "\n";
        s << "    relative_amplitude_skipped: " << nr_relativeAmpSkip << "\n";
        s << "    absolute_amplitude_skipped: " << nr_absAmpSkip << "\n";
        s << "    max_num_peaks: " << nr_maxNumPeaks << "\n";
        s << "    scan_only_vertex_GLL: " << (nr_scanOnlyVertexGLL ? "true" : "false") << "\n";
        s << "    num_steps_per_mesh_period: " << nr_numStepsPerMeshPeriod << "\n";
    }

    // --- inparam.source.yaml ---
    {
        QFile f(inputDir + "/inparam.source.yaml");
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream s(&f);
        s << "# inparam.source.yaml\n\n";
        s << "time_axis:\n";
        s << "    record_length: " << src_recordLength << "\n";
        s << "    enforced_dt: " << src_enforcedDt << "\n";
        s << "    Courant_number: " << src_courantNumber << "\n";
        s << "    integrator: " << src_integrator << "\n";
        s << "\n";
        s << "list_of_sources:\n";
        for (auto *sw : m_sourceWidgets) {
            s << "    - location:\n";
            s << "        horizontal_type: " << sw->locHorizType() << "\n";
            s << "        horizontal: " << sw->locHorizCoords() << "\n";
            s << "        vertical_type: " << sw->locVertType() << "\n";
            s << "        vertical: " << sw->locVertValue() << "\n";
            s << "        ellipticity: " << (sw->locEllipticity() ? "true" : "false") << "\n";
            s << "        depth_below_solid_surface: " << (sw->locDepthBelowSolid() ? "true" : "false") << "\n";
            s << "        undulated_geometry: " << (sw->locUndulatedGeom() ? "true" : "false") << "\n";
            s << "      mechanism:\n";
            s << "        type: " << sw->mechType() << "\n";
            s << "        data: " << sw->mechData() << "\n";
            s << "        unit: " << sw->mechUnit() << "\n";
            s << "      source_time_function:\n";
            s << "        class_name: " << sw->stfClassName() << "\n";
            QString stfCls = sw->stfClassName();
            if (stfCls == "GaussianSTF") {
                s << "        half_duration: " << sw->stfHalfDuration() << "\n";
                s << "        decay_factor: " << sw->stfDecayFactor() << "\n";
                s << "        time_shift: " << sw->stfTimeShift() << "\n";
                s << "        use_derivative_integral: " << sw->stfDerivIntegral() << "\n";
            } else if (stfCls == "StreamSTF") {
                s << "        ascii_data_file: " << QFileInfo(sw->stfAsciiFile()).fileName() << "\n";
                s << "        padding: " << sw->stfStreamPadding() << "\n";
            } else if (stfCls == "NetCDF_STF") {
                s << "        nc_data_file: " << QFileInfo(sw->stfNcFile()).fileName() << "\n";
                s << "        nc_var_times: " << sw->stfNcVarTimes() << "\n";
                s << "        nc_var_data: " << sw->stfNcVarData() << "\n";
                s << "        padding: " << sw->stfNcPadding() << "\n";
                s << "        chunk_size: " << sw->stfNcChunkSize() << "\n";
            }
        }
    }

    // --- inparam.output.yaml ---
    {
        QFile f(inputDir + "/inparam.output.yaml");
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream s(&f);
        s << "# inparam.output.yaml\n\n";
        s << "list_of_station_groups:\n";
        for (auto *ow : m_outputGroupWidgets) {
            s << "    - group_name: " << ow->groupName() << "\n";
            s << "      station_file: " << QFileInfo(ow->stationFile()).fileName() << "\n";
            s << "      horizontal_coordinate: " << ow->horizontalCoord() << "\n";
            s << "      vertical_coordinate: " << ow->verticalCoord() << "\n";
            s << "      ellipticity: " << (ow->locEllipticity() ? "true" : "false") << "\n";
            s << "      depth_below_solid_surface: " << (ow->locDepthBelowSolid() ? "true" : "false") << "\n";
            s << "      undulated_geometry: " << (ow->locUndulatedGeom() ? "true" : "false") << "\n";
            s << "      wavefields:\n";
            s << "        coordinate_frame: " << ow->coordFrame() << "\n";
            s << "        medium: " << ow->medium() << "\n";
            s << "        channels: " << ow->channels() << "\n";
            s << "      temporal_sampling:\n";
            s << "        sampling_period: " << ow->samplingPeriod() << "\n";
            s << "        time_window: " << ow->timeWindow() << "\n";
            s << "      file_options:\n";
            s << "        format: " << ow->fileFormat() << "\n";
            s << "        buffer_size: " << ow->bufferSize() << "\n";
            s << "        flush: " << (ow->flush() ? "true" : "false") << "\n";
        }
    }
}

// ── Run simulation ──
void MainWindow::onRunSimulation()
{
    QString exePath = ui->lineExePath->text().trimmed();
    if (exePath.isEmpty()) {
        QMessageBox::warning(this, "No Executable",
                             "Please locate the AxiSEM3D executable first.");
        return;
    }

    // determine the working directory (where the exe lives)
    QFileInfo exeInfo(exePath);
    QString exeDir = exeInfo.absolutePath();
    QString inputDir = exeDir + "/input";

    // create input/ folder
    QDir().mkpath(inputDir);

    ui->editRunLog->clear();
    ui->editRunLog->appendPlainText("Generating input files...");

    // generate YAML files
    generateYamlFiles(inputDir);

    // copy mesh file
    copyFileToInput(meshFile, inputDir);

    // copy stations files from output groups
    for (auto *ow : m_outputGroupWidgets)
        copyFileToInput(ow->stationFile(), inputDir);

    // copy NC data files from Nr
    copyFileToInput(nr_pointwiseFile, inputDir);
    copyFileToInput(nr_structuredFile, inputDir);

    // copy NC data files from 3D models
    for (auto *mw : m_modelWidgets)
        copyFileToInput(mw->ncDataFile(), inputDir);

    // copy STF data files from sources
    for (auto *sw : m_sourceWidgets) {
        if (sw->stfClassName() == "StreamSTF")
            copyFileToInput(sw->stfAsciiFile(), inputDir);
        else if (sw->stfClassName() == "NetCDF_STF")
            copyFileToInput(sw->stfNcFile(), inputDir);
    }

    ui->editRunLog->appendPlainText("Input files written to: " + inputDir);

    // ── remote mode with batch job ──
    if (m_isRemoteMode && ui->checkBatchJob->isChecked()) {
        QString batchFilename = ui->lineBatchFilename->text().trimmed();
        if (batchFilename.isEmpty()) {
            QMessageBox::warning(this, "No Filename",
                                 "Please enter a filename for the batch job script.");
            return;
        }
        QString batchPath = exeDir + "/" + batchFilename;
        QFile bf(batchPath);
        if (bf.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream bs(&bf);
            bs << ui->editBatchScript->toPlainText();
            bf.close();
            ui->editRunLog->appendPlainText("Batch script written to: " + batchPath);
        }

        // submit via SSH
        QString host = ui->lineSSHHost->text().trimmed();
        QString port = ui->lineSSHPort->text().trimmed();
        QString user = ui->lineSSHUser->text().trimmed();
        QString password = ui->lineSSHPass->text();

        // make batch script executable and submit
        QString remoteCmd = QString("chmod +x %1 && cd %2 && ./%1")
                                .arg(batchFilename, exeDir);

        QStringList sshArgs;
        sshArgs << "-o" << "StrictHostKeyChecking=accept-new"
                << "-p" << (port.isEmpty() ? "22" : port)
                << (user + "@" + host)
                << remoteCmd;

        m_simProcess = new QProcess(this);
        m_simProcess->setProcessChannelMode(QProcess::MergedChannels);

        connect(m_simProcess, &QProcess::readyRead, this, [=]() {
            ui->editRunLog->appendPlainText(
                QString::fromUtf8(m_simProcess->readAll()));
        });
        connect(m_simProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                this, [=](int exitCode, QProcess::ExitStatus) {
                    ui->editRunLog->appendPlainText(
                        QString("\n── Process finished (exit code %1) ──").arg(exitCode));
                    ui->btnRunSim->setEnabled(true);
                    ui->btnStopSim->setEnabled(false);
                    m_simProcess->deleteLater();
                    m_simProcess = nullptr;
                });

        ui->btnRunSim->setEnabled(false);
        ui->btnStopSim->setEnabled(true);
        ui->editRunLog->appendPlainText("Submitting batch job via SSH...");

        if (!password.isEmpty())
            m_simProcess->start("sshpass",
                                QStringList() << "-p" << password << "ssh" << sshArgs);
        else
            m_simProcess->start("ssh", sshArgs);
        return;
    }

    // ── remote mode without batch job: direct run via SSH ──
    if (m_isRemoteMode) {
        QString host = ui->lineSSHHost->text().trimmed();
        QString port = ui->lineSSHPort->text().trimmed();
        QString user = ui->lineSSHUser->text().trimmed();
        QString password = ui->lineSSHPass->text();
        int nprocs = ui->spinMpiProcs->value();

        QString remoteCmd = QString("cd %1 && mpirun -np %2 %3")
                                .arg(exeDir).arg(nprocs).arg(exePath);

        QStringList sshArgs;
        sshArgs << "-o" << "StrictHostKeyChecking=accept-new"
                << "-p" << (port.isEmpty() ? "22" : port)
                << (user + "@" + host)
                << remoteCmd;

        m_simProcess = new QProcess(this);
        m_simProcess->setProcessChannelMode(QProcess::MergedChannels);

        connect(m_simProcess, &QProcess::readyRead, this, [=]() {
            ui->editRunLog->appendPlainText(
                QString::fromUtf8(m_simProcess->readAll()));
        });
        connect(m_simProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
                this, [=](int exitCode, QProcess::ExitStatus) {
                    ui->editRunLog->appendPlainText(
                        QString("\n── Process finished (exit code %1) ──").arg(exitCode));
                    ui->btnRunSim->setEnabled(true);
                    ui->btnStopSim->setEnabled(false);
                    m_simProcess->deleteLater();
                    m_simProcess = nullptr;
                });

        ui->btnRunSim->setEnabled(false);
        ui->btnStopSim->setEnabled(true);
        ui->editRunLog->appendPlainText("Running AxiSEM3D via SSH...");

        if (!password.isEmpty())
            m_simProcess->start("sshpass",
                                QStringList() << "-p" << password << "ssh" << sshArgs);
        else
            m_simProcess->start("ssh", sshArgs);
        return;
    }

    // ── local mode ──
    int nprocs = ui->spinMpiProcs->value();
    m_simProcess = new QProcess(this);
    m_simProcess->setWorkingDirectory(exeDir);
    m_simProcess->setProcessChannelMode(QProcess::MergedChannels);

    connect(m_simProcess, &QProcess::readyRead, this, [=]() {
        ui->editRunLog->appendPlainText(
            QString::fromUtf8(m_simProcess->readAll()));
    });
    connect(m_simProcess, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [=](int exitCode, QProcess::ExitStatus) {
                ui->editRunLog->appendPlainText(
                    QString("\n── Process finished (exit code %1) ──").arg(exitCode));
                ui->btnRunSim->setEnabled(true);
                ui->btnStopSim->setEnabled(false);
                m_simProcess->deleteLater();
                m_simProcess = nullptr;
            });

    ui->btnRunSim->setEnabled(false);
    ui->btnStopSim->setEnabled(true);
    ui->editRunLog->appendPlainText(
        QString("Running: mpirun -np %1 %2").arg(nprocs).arg(exePath));

    m_simProcess->start("mpirun",
                         QStringList() << "-np" << QString::number(nprocs) << exePath);
}

// ── Stop simulation ──
void MainWindow::onStopSimulation()
{
    if (m_simProcess && m_simProcess->state() != QProcess::NotRunning) {
        m_simProcess->kill();
        ui->editRunLog->appendPlainText("\n── Simulation stopped by user ──");
        ui->btnRunSim->setEnabled(true);
        ui->btnStopSim->setEnabled(false);
    }
}
