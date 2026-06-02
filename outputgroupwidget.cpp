#include "outputgroupwidget.h"
#include <QFileDialog>
#include <QFrame>

// ═══════════════════════════════════════════════════════════════
// construction
// ═══════════════════════════════════════════════════════════════

OutputGroupWidget::OutputGroupWidget(int index, QWidget *parent)
    : QGroupBox(parent)
    , m_index(index)
{
    setTitle(QString("Station Group #%1").arg(index + 1));
    buildUi();
}

OutputGroupWidget::~OutputGroupWidget() = default;

// ═══════════════════════════════════════════════════════════════

static QFrame *hSep()
{
    auto *f = new QFrame;
    f->setFrameShape(QFrame::HLine);
    f->setFrameShadow(QFrame::Sunken);
    return f;
}

void OutputGroupWidget::buildUi()
{
    auto *root = new QVBoxLayout(this);

    // ── group name ──
    {
        auto *form = new QFormLayout;
        m_lineGroupName = new QLineEdit(
            QString("station_group_%1").arg(m_index + 1));
        m_lineGroupName->setToolTip(
            "Arbitrary unique key for this station group. "
            "Must be unique across all station groups.");
        form->addRow("Group Key:", m_lineGroupName);
        root->addLayout(form);

        m_valGroupName = m_lineGroupName->text();
        connect(m_lineGroupName, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valGroupName = text;
                });
    }

    root->addWidget(hSep());

    // ════════════════════════════════════════
    //  LOCATIONS
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("Station Locations");
        auto *form = new QFormLayout(grp);

        // station file
        auto *fileLbl = new QLabel(
            "Station location file — must be an ASCII file with five or six "
            "columns:\n  NAME  NETWORK  x1  x2  [useless]  x3\n"
            "The [useless] column is for compatibility with SPECFEM/AxiSEM. "
            "Empty lines and comment lines (led by #) are allowed.");
        fileLbl->setWordWrap(true);
        form->addRow(fileLbl);

        auto *fileRow = new QHBoxLayout;
        m_lineStationFile = new QLineEdit;
        m_lineStationFile->setReadOnly(true);
        m_btnBrowseStation = new QPushButton("Browse...");
        fileRow->addWidget(m_lineStationFile, 1);
        fileRow->addWidget(m_btnBrowseStation);
        form->addRow("Station File:", fileRow);

        connect(m_btnBrowseStation, &QPushButton::clicked, this, [this]() {
            QString f = QFileDialog::getOpenFileName(
                this, "Select Station File", "",
                "Text Files (*.txt *.dat *.csv);;All Files (*)");
            if (!f.isEmpty()) m_lineStationFile->setText(f);
        });

        m_valStationFile = m_lineStationFile->text();
        connect(m_lineStationFile, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valStationFile = text;
                });

        // horizontal coordinates
        auto *horizLbl = new QLabel(
            "Horizontal coordinates x1 and x2:\n"
            "  LATITUDE_LONGITUDE — unit is degree\n"
            "  DISTANCE_AZIMUTH — distance in radian (spherical mesh) "
            "or meter (Cartesian mesh); azimuth in radian\n"
            "  XY_CARTESIAN — unit is meter");
        horizLbl->setWordWrap(true);
        form->addRow(horizLbl);

        m_comboHorizCoord = new QComboBox;
        m_comboHorizCoord->addItems({
            "LATITUDE_LONGITUDE",
            "DISTANCE_AZIMUTH",
            "XY_CARTESIAN"});
        form->addRow("Horizontal (x1, x2):", m_comboHorizCoord);

        m_valHorizCoord = m_comboHorizCoord->currentText();
        connect(m_comboHorizCoord, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valHorizCoord = text;
                });

        // vertical coordinate
        m_comboVertCoord = new QComboBox;
        m_comboVertCoord->addItems({"DEPTH", "RADIUS"});
        m_comboVertCoord->setToolTip("Vertical coordinate x3. Unit is meter.");
        form->addRow("Vertical (x3):", m_comboVertCoord);

        m_valVertCoord = m_comboVertCoord->currentText();
        connect(m_comboVertCoord, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valVertCoord = text;
                });

        // ellipticity
        m_checkLocEllipticity = new QCheckBox(
            "Correct for Ellipticity");
        m_checkLocEllipticity->setChecked(true);
        m_checkLocEllipticity->setToolTip(
            "Correct for ellipticity when locating the stations. "
            "Used only when horizontal = LATITUDE_LONGITUDE.");
        form->addRow(m_checkLocEllipticity);

        m_valLocEllipticity = m_checkLocEllipticity->isChecked();
        connect(m_checkLocEllipticity, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valLocEllipticity = checked;
                });

        // depth below solid surface
        m_checkLocDepthBelowSolid = new QCheckBox(
            "Depth Below Solid Surface");
        m_checkLocDepthBelowSolid->setChecked(true);
        m_checkLocDepthBelowSolid->setToolTip(
            "Use solid surface as depth origin. "
            "Used only when vertical = DEPTH.");
        form->addRow(m_checkLocDepthBelowSolid);

        m_valLocDepthBelowSolid = m_checkLocDepthBelowSolid->isChecked();
        connect(m_checkLocDepthBelowSolid, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valLocDepthBelowSolid = checked;
                });

        // undulated geometry
        m_checkLocUndulatedGeom = new QCheckBox(
            "Undulated Geometry");
        m_checkLocUndulatedGeom->setChecked(true);
        m_checkLocUndulatedGeom->setToolTip(
            "Use undulated (otherwise reference) geometry to determine "
            "vertical locations. Compatible with both RADIUS and DEPTH.");
        form->addRow(m_checkLocUndulatedGeom);

        m_valLocUndulatedGeom = m_checkLocUndulatedGeom->isChecked();
        connect(m_checkLocUndulatedGeom, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valLocUndulatedGeom = checked;
                });

        root->addWidget(grp);
    }

    // ════════════════════════════════════════
    //  WAVEFIELDS
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("Wavefields");
        auto *form = new QFormLayout(grp);

        // coordinate frame
        auto *frameLbl = new QLabel(
            "Coordinate frame of recorded wavefields:\n"
            "  spz — (s, phi, z), AxiSEM3D intrinsic\n"
            "  RTZ — (radial, transverse, vertical)\n"
            "  ENZ — (east, north, vertical)\n"
            "  xyz — (x, y, z) in source-centered frame");
        frameLbl->setWordWrap(true);
        form->addRow(frameLbl);

        m_comboCoordFrame = new QComboBox;
        m_comboCoordFrame->addItems({"spz", "RTZ", "ENZ", "xyz"});
        m_comboCoordFrame->setCurrentText("RTZ");
        form->addRow("Coordinate Frame:", m_comboCoordFrame);

        m_valCoordFrame = m_comboCoordFrame->currentText();
        connect(m_comboCoordFrame, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valCoordFrame = text;
                });

        // medium
        m_comboMedium = new QComboBox;
        m_comboMedium->addItems({"SOLID", "FLUID"});
        m_comboMedium->setToolTip(
            "Type of medium. All stations in a group must be located "
            "in either the solid or the fluid domain.");
        form->addRow("Medium:", m_comboMedium);

        m_valMedium = m_comboMedium->currentText();
        connect(m_comboMedium, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valMedium = text;
                });

        // channels
        auto *chanLbl = new QLabel(
            "List of channels to record:\n"
            "  Solid displacement: U, U1, U2, U3, U_NORM (or |U|)\n"
            "  Solid gradient: G, G11..G33, Gii (or G_I1)\n"
            "  Solid strain: E, E11..E33, Eii (or E_I1), E_J2\n"
            "  Solid stress: S, S11..S33, Sii (or S_I1), S_J2\n"
            "  Solid curl: R, R1, R2, R3, R_NORM (or |R|)\n"
            "  Fluid: U, X (scalar potential), P (pressure)\n"
            "Using 'U' expands to [U1, U2, U3]; similarly for G, E, S, R. "
            "Duplicates are automatically removed.\n"
            "(1, 2, 3) are determined by the coordinate frame above.");
        chanLbl->setWordWrap(true);
        form->addRow(chanLbl);

        m_lineChannels = new QLineEdit("[U]");
        form->addRow("Channels:", m_lineChannels);

        m_valChannels = m_lineChannels->text();
        connect(m_lineChannels, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valChannels = text;
                });

        root->addWidget(grp);
    }

    // ════════════════════════════════════════
    //  TEMPORAL SAMPLING
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("Temporal Sampling");
        auto *form = new QFormLayout(grp);

        auto *sampLbl = new QLabel(
            "Sampling period of the output:\n"
            "  DT = simulation time step\n"
            "  DTx2, DTx3, ... = multiples of DT\n"
            "  Or enter a numeric value in seconds (e.g. 5.)");
        sampLbl->setWordWrap(true);
        form->addRow(sampLbl);

        m_lineSamplingPeriod = new QLineEdit("DT");
        form->addRow("Sampling Period:", m_lineSamplingPeriod);

        m_valSamplingPeriod = m_lineSamplingPeriod->text();
        connect(m_lineSamplingPeriod, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valSamplingPeriod = text;
                });

        auto *twLbl = new QLabel(
            "Time window for recording:\n"
            "  FULL = record the whole simulation\n"
            "  Or specify [t0, t1] in seconds");
        twLbl->setWordWrap(true);
        form->addRow(twLbl);

        m_lineTimeWindow = new QLineEdit("FULL");
        form->addRow("Time Window:", m_lineTimeWindow);

        m_valTimeWindow = m_lineTimeWindow->text();
        connect(m_lineTimeWindow, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valTimeWindow = text;
                });

        root->addWidget(grp);
    }

    // ════════════════════════════════════════
    //  FILE OPTIONS
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("File Options");
        auto *form = new QFormLayout(grp);

        auto *fmtLbl = new QLabel(
            "Output file format:\n"
            "  ASCII_STATION — one file per station with all channels "
            "(best for a small number of stations)\n"
            "  ASCII_CHANNEL — one file per channel with all stations "
            "(available for many stations)\n"
            "  NETCDF — much more efficient than ASCII, available for many "
            "stations; parallel NetCDF can be activated in CMakeLists.txt");
        fmtLbl->setWordWrap(true);
        form->addRow(fmtLbl);

        m_comboFormat = new QComboBox;
        m_comboFormat->addItems({
            "ASCII_STATION",
            "ASCII_CHANNEL",
            "NETCDF"});
        form->addRow("Format:", m_comboFormat);

        m_valFormat = m_comboFormat->currentText();
        connect(m_comboFormat, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valFormat = text;
                });

        auto *bufLbl = new QLabel(
            "Number of sampled time steps to be buffered before writing. "
            "Increase this to save writing time; decrease to save memory "
            "(useful for a large number of stations). "
            "Does not affect the final results.");
        bufLbl->setWordWrap(true);
        form->addRow(bufLbl);

        m_spinBufferSize = new QSpinBox;
        m_spinBufferSize->setMinimum(1);
        m_spinBufferSize->setMaximum(100000);
        m_spinBufferSize->setValue(1000);
        form->addRow("Buffer Size:", m_spinBufferSize);

        m_valBufferSize = m_spinBufferSize->value();
        connect(m_spinBufferSize, QOverload<int>::of(&QSpinBox::valueChanged),
                this, [this](int value) {
                    m_valBufferSize = value;
                });

        m_checkFlush = new QCheckBox("Flush After Write");
        m_checkFlush->setChecked(true);
        m_checkFlush->setToolTip(
            "Flush file after writing a buffer to it.\n"
            "Pro: minimizes data loss in case of abnormal termination.\n"
            "Con: hits output performance if buffer_size is small.\n"
            "Does not affect the final results.");
        form->addRow(m_checkFlush);

        m_valFlush = m_checkFlush->isChecked();
        connect(m_checkFlush, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valFlush = checked;
                });

        root->addWidget(grp);
    }

    root->addStretch();
}

// ═══════════════════════════════════════════════════════════════
// accessors
// ═══════════════════════════════════════════════════════════════

QString OutputGroupWidget::groupName()        const { return m_valGroupName; }

QString OutputGroupWidget::stationFile()      const { return m_valStationFile; }
QString OutputGroupWidget::horizontalCoord()  const { return m_valHorizCoord; }
QString OutputGroupWidget::verticalCoord()    const { return m_valVertCoord; }
bool    OutputGroupWidget::locEllipticity()   const { return m_valLocEllipticity; }
bool    OutputGroupWidget::locDepthBelowSolid() const { return m_valLocDepthBelowSolid; }
bool    OutputGroupWidget::locUndulatedGeom() const { return m_valLocUndulatedGeom; }

QString OutputGroupWidget::coordFrame()       const { return m_valCoordFrame; }
QString OutputGroupWidget::medium()           const { return m_valMedium; }
QString OutputGroupWidget::channels()         const { return m_valChannels; }

QString OutputGroupWidget::samplingPeriod()   const { return m_valSamplingPeriod; }
QString OutputGroupWidget::timeWindow()       const { return m_valTimeWindow; }

QString OutputGroupWidget::fileFormat()       const { return m_valFormat; }
int     OutputGroupWidget::bufferSize()       const { return m_valBufferSize; }
bool    OutputGroupWidget::flush()            const { return m_valFlush; }
