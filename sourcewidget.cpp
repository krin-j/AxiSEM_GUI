#include "sourcewidget.h"
#include <QFileDialog>
#include <QFrame>

// ═══════════════════════════════════════════════════════════════
// construction
// ═══════════════════════════════════════════════════════════════

SourceWidget::SourceWidget(int index, QWidget *parent)
    : QGroupBox(parent)
    , m_index(index)
{
    setTitle(QString("Source #%1").arg(index + 1));
    buildUi();
    updateMechVisibility(m_comboMechType->currentText());
    updateStfVisibility(m_comboStfClass->currentText());
}

SourceWidget::~SourceWidget() = default;

// ═══════════════════════════════════════════════════════════════

static QFrame *hSep()
{
    auto *f = new QFrame;
    f->setFrameShape(QFrame::HLine);
    f->setFrameShadow(QFrame::Sunken);
    return f;
}

void SourceWidget::buildUi()
{
    auto *root = new QVBoxLayout(this);

    // ── source key name ──
    {
        auto *form = new QFormLayout;
        m_lineName = new QLineEdit(
            QString("source_%1").arg(m_index + 1));
        m_lineName->setToolTip("Arbitrary unique key for this source.");
        form->addRow("Source Key:", m_lineName);
        root->addLayout(form);

        m_valName = m_lineName->text();
        connect(m_lineName, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valName = text;
                });
    }

    root->addWidget(hSep());

    // ════════════════════════════════════════
    //  LOCATION
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("Source Location");
        auto *form = new QFormLayout(grp);

        // horizontal type
        auto *horizLbl = new QLabel(
            "Horizontal location type:\n"
            "  latitude_longitude — unit is degree; if geodesy "
            "lat_lon_north_pole_mesh = SOURCE in inparam.model.yaml "
            "and this is the FIRST source, this key must be used\n"
            "  distance_azimuth — distance in radian (spherical) or "
            "meter (Cartesian); azimuth in radian\n"
            "  ON_AXIS — place the source on the mesh axis");
        horizLbl->setWordWrap(true);
        form->addRow(horizLbl);

        m_comboHorizType = new QComboBox;
        m_comboHorizType->addItems({
            "latitude_longitude",
            "distance_azimuth",
            "ON_AXIS"});
        form->addRow("Horizontal Type:", m_comboHorizType);

        m_valHorizType = m_comboHorizType->currentText();
        connect(m_comboHorizType, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valHorizType = text;
                });

        // horizontal coords
        m_lineHorizCoords = new QLineEdit("[37.91, -77.93]");
        m_lineHorizCoords->setToolTip(
            "Horizontal coordinates as an array, e.g. [lat, lon] in degrees "
            "or [distance, azimuth] in radian. Leave empty if ON_AXIS.");
        form->addRow("Coordinates:", m_lineHorizCoords);

        m_valHorizCoords = m_lineHorizCoords->text();
        connect(m_lineHorizCoords, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valHorizCoords = text;
                });

        // vertical type
        m_comboVertType = new QComboBox;
        m_comboVertType->addItems({"depth", "radius"});
        m_comboVertType->setToolTip(
            "Vertical location key — 'depth' or 'radius'. Unit is meter.");
        form->addRow("Vertical Type:", m_comboVertType);

        m_valVertType = m_comboVertType->currentText();
        connect(m_comboVertType, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valVertType = text;
                });

        // vertical value
        m_lineVertValue = new QLineEdit("12e3");
        m_lineVertValue->setToolTip(
            "Vertical location value in meters. "
            "e.g. 12e3 for 12 km depth.");
        form->addRow("Vertical Value (m):", m_lineVertValue);

        m_valVertValue = m_lineVertValue->text();
        connect(m_lineVertValue, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valVertValue = text;
                });

        // ellipticity
        m_checkLocEllipticity = new QCheckBox("Correct for Ellipticity");
        m_checkLocEllipticity->setChecked(true);
        m_checkLocEllipticity->setToolTip(
            "Correct for ellipticity when locating the source. "
            "Used only when horizontal type = latitude_longitude.");
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
            "Used only when vertical type = depth.");
        form->addRow(m_checkLocDepthBelowSolid);

        m_valLocDepthBelowSolid = m_checkLocDepthBelowSolid->isChecked();
        connect(m_checkLocDepthBelowSolid, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valLocDepthBelowSolid = checked;
                });

        // undulated geometry
        m_checkLocUndulatedGeom = new QCheckBox("Undulated Geometry");
        m_checkLocUndulatedGeom->setChecked(true);
        m_checkLocUndulatedGeom->setToolTip(
            "Use undulated (otherwise reference) geometry to determine "
            "the vertical location. Compatible with both depth and radius.");
        form->addRow(m_checkLocUndulatedGeom);

        m_valLocUndulatedGeom = m_checkLocUndulatedGeom->isChecked();
        connect(m_checkLocUndulatedGeom, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valLocUndulatedGeom = checked;
                });

        root->addWidget(grp);
    }

    // ════════════════════════════════════════
    //  MECHANISM
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("Source Mechanism");
        auto *form = new QFormLayout(grp);

        // type
        auto *typeLbl = new QLabel(
            "Source mechanism type:\n"
            "  MOMENT_TENSOR — data = [M11, M22, M33, M12, M13, M23]\n"
            "    where 123 = ZRT (vertical, radial, transpose);\n"
            "    for latitude_longitude, RT-axes are w.r.t. the north pole "
            "and follow the CMTSOLUTION format (globalcmt.org)\n"
            "  FORCE_VECTOR — data = [F1, F2, F3]\n"
            "  FLUID_PRESSURE — data = [P]");
        typeLbl->setWordWrap(true);
        form->addRow(typeLbl);

        m_comboMechType = new QComboBox;
        m_comboMechType->addItems({
            "MOMENT_TENSOR",
            "FORCE_VECTOR",
            "FLUID_PRESSURE"});
        form->addRow("Type:", m_comboMechType);

        m_valMechType = m_comboMechType->currentText();
        connect(m_comboMechType, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valMechType = text;
                });

        // data hint label (updates dynamically)
        m_lblMechDataHint = new QLabel(
            "Enter [M11, M22, M33, M12, M13, M23] for MOMENT_TENSOR");
        m_lblMechDataHint->setWordWrap(true);
        form->addRow(m_lblMechDataHint);

        m_lineMechData = new QLineEdit(
            "[4.71e24, 3.81e22, -4.74e24, 3.99e23, -8.05e23, -1.23e24]");
        m_lineMechData->setToolTip(
            "Source mechanism data array. Format depends on type above.");
        form->addRow("Data:", m_lineMechData);

        m_valMechData = m_lineMechData->text();
        connect(m_lineMechData, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valMechData = text;
                });

        // unit
        m_lineMechUnit = new QLineEdit("1e-7");
        m_lineMechUnit->setToolTip(
            "Unit multiplier for the data values. "
            "Use 1e-7 to convert dyn*cm (CMTSOLUTION format) to N*m.");
        form->addRow("Unit:", m_lineMechUnit);

        m_valMechUnit = m_lineMechUnit->text();
        connect(m_lineMechUnit, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valMechUnit = text;
                });

        root->addWidget(grp);

        connect(m_comboMechType, &QComboBox::currentTextChanged,
                this, &SourceWidget::onMechTypeChanged);
    }

    // ════════════════════════════════════════
    //  SOURCE TIME FUNCTION
    // ════════════════════════════════════════
    {
        auto *grp = new QGroupBox("Source Time Function");
        auto *vbox = new QVBoxLayout(grp);

        auto *classForm = new QFormLayout;
        auto *stfLbl = new QLabel(
            "Source time function class:\n"
            "  GaussianSTF — parameterized Gaussian bell and its "
            "derivatives/integrals\n"
            "  StreamSTF — user-provided time series from an ASCII file\n"
            "  NetCDF_STF — user-provided time series from a NetCDF file");
        stfLbl->setWordWrap(true);
        classForm->addRow(stfLbl);

        m_comboStfClass = new QComboBox;
        m_comboStfClass->addItems({
            "GaussianSTF",
            "StreamSTF",
            "NetCDF_STF"});
        classForm->addRow("Class:", m_comboStfClass);
        vbox->addLayout(classForm);

        m_valStfClass = m_comboStfClass->currentText();
        connect(m_comboStfClass, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valStfClass = text;
                });

        // ── GaussianSTF parameters ──
        m_gaussianGroup = new QWidget;
        {
            auto *form = new QFormLayout(m_gaussianGroup);
            form->setContentsMargins(0, 0, 0, 0);

            m_lineHalfDuration = new QLineEdit("50.");
            m_lineHalfDuration->setToolTip(
                "Half duration of the Gaussian bell (seconds). "
                "Use 0 for a Dirac-delta to compute Green's functions.");
            form->addRow("Half Duration:", m_lineHalfDuration);

            m_valHalfDuration = m_lineHalfDuration->text();
            connect(m_lineHalfDuration, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valHalfDuration = text;
                    });

            m_lineDecayFactor = new QLineEdit("1.628");
            m_lineDecayFactor->setToolTip(
                "Decay factor controlling the bell shape. "
                "SPECFEM3D_GLOBE uses 1.628; AxiSEM uses 3.5.");
            form->addRow("Decay Factor:", m_lineDecayFactor);

            m_valDecayFactor = m_lineDecayFactor->text();
            connect(m_lineDecayFactor, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valDecayFactor = text;
                    });

            m_lineTimeShift = new QLineEdit("0.");
            m_lineTimeShift->setToolTip(
                "Time shift in seconds. The bell is centered at t=0 when "
                "time_shift=0. A positive value moves the bell to the right.");
            form->addRow("Time Shift:", m_lineTimeShift);

            m_valTimeShift = m_lineTimeShift->text();
            connect(m_lineTimeShift, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valTimeShift = text;
                    });

            auto *derivLbl = new QLabel(
                "Derivative/integral of Gaussian to use:\n"
                "  ERF — error function (integral of Gaussian)\n"
                "  GAUSSIAN — Gaussian itself\n"
                "  FIRST_DERIVATIVE — first derivative of Gaussian\n"
                "  RICKER — second derivative of Gaussian (Ricker wavelet)");
            derivLbl->setWordWrap(true);
            form->addRow(derivLbl);

            m_comboDerivIntegral = new QComboBox;
            m_comboDerivIntegral->addItems({
                "ERF",
                "GAUSSIAN",
                "FIRST_DERIVATIVE",
                "RICKER"});
            form->addRow("Type:", m_comboDerivIntegral);

            m_valDerivIntegral = m_comboDerivIntegral->currentText();
            connect(m_comboDerivIntegral, &QComboBox::currentTextChanged,
                    this, [this](const QString &text) {
                        m_valDerivIntegral = text;
                    });
        }
        vbox->addWidget(m_gaussianGroup);

        // ── StreamSTF parameters ──
        m_streamGroup = new QWidget;
        {
            auto *form = new QFormLayout(m_streamGroup);
            form->setContentsMargins(0, 0, 0, 0);

            auto *ascLbl = new QLabel(
                "ASCII data file with two columns (time, value) and "
                "at least two rows. Empty lines and comment lines "
                "(led by #) are allowed.");
            ascLbl->setWordWrap(true);
            form->addRow(ascLbl);

            auto *fileRow = new QHBoxLayout;
            m_lineAsciiFile = new QLineEdit;
            m_lineAsciiFile->setReadOnly(true);
            m_btnBrowseAscii = new QPushButton("Browse...");
            fileRow->addWidget(m_lineAsciiFile, 1);
            fileRow->addWidget(m_btnBrowseAscii);
            form->addRow("ASCII File:", fileRow);

            connect(m_btnBrowseAscii, &QPushButton::clicked, this, [this]() {
                QString f = QFileDialog::getOpenFileName(
                    this, "Select STF ASCII File", "",
                    "Text Files (*.txt *.dat);;All Files (*)");
                if (!f.isEmpty()) m_lineAsciiFile->setText(f);
            });

            m_valAsciiFile = m_lineAsciiFile->text();
            connect(m_lineAsciiFile, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valAsciiFile = text;
                    });

            m_lineStreamPadding = new QLineEdit("FIRST_LAST");
            m_lineStreamPadding->setToolTip(
                "Padding when time is out of range:\n"
                "  NONE — throw an error\n"
                "  FIRST_LAST — use first and last values in file\n"
                "  [left, right] — specified padding values");
            form->addRow("Padding:", m_lineStreamPadding);

            m_valStreamPadding = m_lineStreamPadding->text();
            connect(m_lineStreamPadding, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valStreamPadding = text;
                    });
        }
        vbox->addWidget(m_streamGroup);

        // ── NetCDF_STF parameters ──
        m_netcdfGroup = new QWidget;
        {
            auto *form = new QFormLayout(m_netcdfGroup);
            form->setContentsMargins(0, 0, 0, 0);

            auto *ncFileRow = new QHBoxLayout;
            m_lineNcStfFile = new QLineEdit;
            m_lineNcStfFile->setReadOnly(true);
            m_lineNcStfFile->setToolTip(
                "NetCDF data file containing the source time function.");
            m_btnBrowseNcStf = new QPushButton("Browse...");
            ncFileRow->addWidget(m_lineNcStfFile, 1);
            ncFileRow->addWidget(m_btnBrowseNcStf);
            form->addRow("NetCDF File:", ncFileRow);

            connect(m_btnBrowseNcStf, &QPushButton::clicked, this, [this]() {
                QString f = QFileDialog::getOpenFileName(
                    this, "Select STF NetCDF File", "",
                    "NetCDF Files (*.nc);;All Files (*)");
                if (!f.isEmpty()) m_lineNcStfFile->setText(f);
            });

            m_valNcStfFile = m_lineNcStfFile->text();
            connect(m_lineNcStfFile, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valNcStfFile = text;
                    });

            m_lineNcVarTimes = new QLineEdit("stf_times");
            m_lineNcVarTimes->setToolTip(
                "NetCDF variable name for times. "
                "Must be double precision with shape (X,), X >= 2.");
            form->addRow("NC Var Times:", m_lineNcVarTimes);

            m_valNcVarTimes = m_lineNcVarTimes->text();
            connect(m_lineNcVarTimes, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valNcVarTimes = text;
                    });

            m_lineNcVarData = new QLineEdit("stf_data");
            m_lineNcVarData->setToolTip(
                "NetCDF variable name for data values. "
                "Must have the same shape as nc_var_times. "
                "Datatype must match solver precision "
                "(see USE_DOUBLE in CMakeLists.txt).");
            form->addRow("NC Var Data:", m_lineNcVarData);

            m_valNcVarData = m_lineNcVarData->text();
            connect(m_lineNcVarData, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valNcVarData = text;
                    });

            m_lineNcPadding = new QLineEdit("FIRST_LAST");
            m_lineNcPadding->setToolTip(
                "Padding when time is out of range:\n"
                "  NONE — throw an error\n"
                "  FIRST_LAST — use first and last values in file\n"
                "  [left, right] — specified padding values");
            form->addRow("Padding:", m_lineNcPadding);

            m_valNcPadding = m_lineNcPadding->text();
            connect(m_lineNcPadding, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valNcPadding = text;
                    });

            m_lineNcChunkSize = new QLineEdit("NONE");
            m_lineNcChunkSize->setToolTip(
                "Chunk size — how many time steps per chunk for buffered "
                "reading during the time loop. Must be > 2.\n"
                "Increase to save reading time; decrease to save memory "
                "(useful for many sources).\n"
                "Use NONE to disable buffering (chunk size = file size).");
            form->addRow("Chunk Size:", m_lineNcChunkSize);

            m_valNcChunkSize = m_lineNcChunkSize->text();
            connect(m_lineNcChunkSize, &QLineEdit::textChanged,
                    this, [this](const QString &text) {
                        m_valNcChunkSize = text;
                    });
        }
        vbox->addWidget(m_netcdfGroup);

        root->addWidget(grp);

        connect(m_comboStfClass, &QComboBox::currentTextChanged,
                this, &SourceWidget::onStfClassChanged);
    }

    root->addStretch();
}

// ═══════════════════════════════════════════════════════════════
// visibility
// ═══════════════════════════════════════════════════════════════

void SourceWidget::onMechTypeChanged(const QString &text)
{
    updateMechVisibility(text);
}

void SourceWidget::updateMechVisibility(const QString &type)
{
    if (type == "MOMENT_TENSOR") {
        m_lblMechDataHint->setText(
            "Enter [M11, M22, M33, M12, M13, M23] — "
            "where 123 = ZRT (vertical, radial, transpose)");
    } else if (type == "FORCE_VECTOR") {
        m_lblMechDataHint->setText(
            "Enter [F1, F2, F3] — where 123 = ZRT");
    } else {
        m_lblMechDataHint->setText(
            "Enter [P] — scalar fluid pressure");
    }
}

void SourceWidget::onStfClassChanged(const QString &cls)
{
    updateStfVisibility(cls);
}

void SourceWidget::updateStfVisibility(const QString &cls)
{
    m_gaussianGroup->setVisible(cls == "GaussianSTF");
    m_streamGroup->setVisible(cls == "StreamSTF");
    m_netcdfGroup->setVisible(cls == "NetCDF_STF");
}

// ═══════════════════════════════════════════════════════════════
// accessors
// ═══════════════════════════════════════════════════════════════

QString SourceWidget::sourceName()        const { return m_valName; }

QString SourceWidget::locHorizType()      const { return m_valHorizType; }
QString SourceWidget::locHorizCoords()    const { return m_valHorizCoords; }
QString SourceWidget::locVertType()       const { return m_valVertType; }
QString SourceWidget::locVertValue()      const { return m_valVertValue; }
bool    SourceWidget::locEllipticity()    const { return m_valLocEllipticity; }
bool    SourceWidget::locDepthBelowSolid() const { return m_valLocDepthBelowSolid; }
bool    SourceWidget::locUndulatedGeom()  const { return m_valLocUndulatedGeom; }

QString SourceWidget::mechType()  const { return m_valMechType; }
QString SourceWidget::mechData()  const { return m_valMechData; }
QString SourceWidget::mechUnit()  const { return m_valMechUnit; }

QString SourceWidget::stfClassName()      const { return m_valStfClass; }

QString SourceWidget::stfHalfDuration()   const { return m_valHalfDuration; }
QString SourceWidget::stfDecayFactor()    const { return m_valDecayFactor; }
QString SourceWidget::stfTimeShift()      const { return m_valTimeShift; }
QString SourceWidget::stfDerivIntegral()  const { return m_valDerivIntegral; }

QString SourceWidget::stfAsciiFile()      const { return m_valAsciiFile; }
QString SourceWidget::stfStreamPadding()  const { return m_valStreamPadding; }

QString SourceWidget::stfNcFile()         const { return m_valNcStfFile; }
QString SourceWidget::stfNcVarTimes()     const { return m_valNcVarTimes; }
QString SourceWidget::stfNcVarData()      const { return m_valNcVarData; }
QString SourceWidget::stfNcPadding()      const { return m_valNcPadding; }
QString SourceWidget::stfNcChunkSize()    const { return m_valNcChunkSize; }
