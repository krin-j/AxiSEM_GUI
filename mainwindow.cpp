#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
            "Mesh Files (*.msh *.mesh *.vtk);;All Files (*)"
            );

        if (!fileName.isEmpty()) {
            ui->lineMeshPath->setText(fileName);
        }
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

    // for advanced file
    ui->comboVerboseChannel->setCurrentText("STDOUT");
    ui->comboVerboseLevel->setCurrentText("ESSENTIAL");
    ui->checkVerboseWarnings->setChecked(true);
    ui->lineLoopInterval->setText("1000");
    ui->lineStabilityInterval->setText("1");
    ui->lineNumProcessorsPerGroup->setText("1");
    ui->loadBalancingBox->setCurrentText("ELEMENT_POINT");
    ui->checkBoxPlotDomainDecomp->setChecked(false);
    ui->checkBoxDiagnosePreloop->setChecked(true);
    ui->lineMaxNumTimeSteps->setText("0");
    ui->lineTimeLimitFFTW->setText("60");
    ui->checkBoxFFTWLuckyNum->setChecked(true);

    // for model file
    ui->comboBoxLatLongNP->setCurrentText("Array (Type Under)");
    ui->lineEditNP->setText("[90., 0.]");
    ui->comboBoxFlatteningSurface->setCurrectText("Custom Number");
    ui->lineFlatteningCustomNum->setText("0.0033");
    ui->lineBoundaries->setText("[RIGHT, BOTTOM]");
}

MainWindow::~MainWindow()
{
    delete ui;
}
