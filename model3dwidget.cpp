#include "model3dwidget.h"
#include <QFileDialog>
#include <QFrame>

// ═══════════════════════════════════════════════════════════════
// construction
// ═══════════════════════════════════════════════════════════════

Model3DWidget::Model3DWidget(int index, QWidget *parent)
    : QGroupBox(parent)
    , m_index(index)
{
    setTitle(QString("3D Model #%1").arg(index + 1));
    buildUi();
    updateVisibility(m_comboClass->currentText());
}

Model3DWidget::~Model3DWidget() = default;

// ═══════════════════════════════════════════════════════════════
// build every sub-widget
// ═══════════════════════════════════════════════════════════════

static QFrame *hLine()
{
    auto *f = new QFrame;
    f->setFrameShape(QFrame::HLine);
    f->setFrameShadow(QFrame::Sunken);
    return f;
}

void Model3DWidget::buildUi()
{
    auto *root = new QVBoxLayout(this);

    // ── row: name + activated + class ──
    {
        auto *form = new QFormLayout;

        m_lineName = new QLineEdit(QString("Model_%1").arg(m_index + 1));
        m_lineName->setToolTip("Arbitrary key name for this 3D model. "
                               "Must be unique in the list.");
        form->addRow("Model Key:", m_lineName);

        m_valName = m_lineName->text();
        connect(m_lineName, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valName = text;
                });

        m_checkActivated = new QCheckBox("Activated");
        m_checkActivated->setChecked(true);
        m_checkActivated->setToolTip("Whether to activate this 3D model.");
        form->addRow(m_checkActivated);

        m_valActivated = m_checkActivated->isChecked();
        connect(m_checkActivated, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valActivated = checked;
                });

        auto *classLbl = new QLabel(
            "Built-in classes:\n"
            "  StructuredGridV3D — volumetric 3D model on a structured grid\n"
            "  StructuredGridG3D — geometric 3D model on a structured grid\n"
            "  StructuredGridO3D — ocean-load 3D model on a structured grid\n"
            "  Ellipticity — deform the mesh with global ellipticity");
        classLbl->setWordWrap(true);
        form->addRow(classLbl);

        m_comboClass = new QComboBox;
        m_comboClass->addItems({"StructuredGridV3D",
                                "StructuredGridG3D",
                                "StructuredGridO3D",
                                "Ellipticity"});
        form->addRow("Class:", m_comboClass);

        m_valClassName = m_comboClass->currentText();
        connect(m_comboClass, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valClassName = text;
                });

        root->addLayout(form);
    }

    root->addWidget(hLine());

    // ── nc data file ──
    {
        m_ncFileRow = new QWidget;
        auto *h = new QHBoxLayout(m_ncFileRow);
        h->setContentsMargins(0, 0, 0, 0);
        auto *lbl = new QLabel("NetCDF Data File:");
        m_btnBrowseNc = new QPushButton("Browse...");
        m_lineNcFile  = new QLineEdit;
        m_lineNcFile->setReadOnly(true);
        m_lineNcFile->setToolTip("Path to the NetCDF (.nc) data file "
                                 "containing the 3D model data.");
        h->addWidget(lbl);
        h->addWidget(m_lineNcFile, 1);
        h->addWidget(m_btnBrowseNc);
        root->addWidget(m_ncFileRow);

        connect(m_btnBrowseNc, &QPushButton::clicked, this, [this]() {
            QString f = QFileDialog::getOpenFileName(
                this, "Select NetCDF File", "",
                "NetCDF Files (*.nc);;All Files (*)");
            if (!f.isEmpty()) m_lineNcFile->setText(f);
        });

        m_valNcFile = m_lineNcFile->text();
        connect(m_lineNcFile, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valNcFile = text;
                });
    }

    // ── coordinates group ──
    {
        m_grpCoords = new QGroupBox("Coordinates");
        auto *form = new QFormLayout(m_grpCoords);

        // horizontal
        auto *horizLbl = new QLabel(
            "Type of horizontal coordinates:\n"
            "  DISTANCE_AZIMUTH — for axisymmetric setups\n"
            "  XY_CARTESIAN — for Cartesian meshes\n"
            "  LATITUDE_LONGITUDE — for global/regional spherical meshes");
        horizLbl->setWordWrap(true);
        form->addRow(horizLbl);

        m_comboHoriz = new QComboBox;
        m_comboHoriz->addItems({"LATITUDE_LONGITUDE",
                                "DISTANCE_AZIMUTH",
                                "XY_CARTESIAN"});
        form->addRow("Horizontal:", m_comboHoriz);

        m_valHoriz = m_comboHoriz->currentText();
        connect(m_comboHoriz, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valHoriz = text;
                });

        // vertical
        m_comboVert = new QComboBox;
        m_comboVert->addItems({"DEPTH", "RADIUS"});
        m_comboVert->setToolTip("Type of vertical coordinate.");
        form->addRow("Vertical:", m_comboVert);

        m_valVert = m_comboVert->currentText();
        connect(m_comboVert, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valVert = text;
                });

        // ellipticity
        m_checkEllipticity = new QCheckBox("Correct for Ellipticity");
        m_checkEllipticity->setToolTip(
            "Correct for ellipticity when locating the model. "
            "Used only when horizontal = LATITUDE_LONGITUDE.");
        form->addRow(m_checkEllipticity);

        m_valEllipticity = m_checkEllipticity->isChecked();
        connect(m_checkEllipticity, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valEllipticity = checked;
                });

        // depth below solid surface
        m_checkDepthBelowSolid = new QCheckBox("Depth Below Solid Surface");
        m_checkDepthBelowSolid->setToolTip(
            "Use solid surface as depth origin. "
            "Used only when vertical = DEPTH.");
        form->addRow(m_checkDepthBelowSolid);

        m_valDepthBelowSolid = m_checkDepthBelowSolid->isChecked();
        connect(m_checkDepthBelowSolid, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valDepthBelowSolid = checked;
                });

        // nc variables
        m_lineNcVars = new QLineEdit("[latitude, longitude, depth]");
        m_lineNcVars->setToolTip(
            "NetCDF variable names for the coordinates, as an array. "
            "e.g. [latitude, longitude, depth] or [latitude, longitude, radius].");
        form->addRow("NC Variables:", m_lineNcVars);

        m_valNcVars = m_lineNcVars->text();
        connect(m_lineNcVars, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valNcVars = text;
                });

        // data rank
        m_lineDataRank = new QLineEdit("[1, 2, 0]");
        m_lineDataRank->setToolTip(
            "Rank (dimension order) of the coordinates in the data file, "
            "as an array of integers. e.g. [1, 2, 0] or [0, 1, 2].");
        form->addRow("Data Rank:", m_lineDataRank);

        m_valDataRank = m_lineDataRank->text();
        connect(m_lineDataRank, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valDataRank = text;
                });

        // length unit
        m_comboLengthUnit = new QComboBox;
        m_comboLengthUnit->addItems({"km", "m"});
        m_comboLengthUnit->setToolTip(
            "Length unit of the coordinates. "
            "Use km or m (or a custom numeric value).");
        form->addRow("Length Unit:", m_comboLengthUnit);

        m_valLengthUnit = m_comboLengthUnit->currentText();
        connect(m_comboLengthUnit, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valLengthUnit = text;
                });

        // angle unit
        m_comboAngleUnit = new QComboBox;
        m_comboAngleUnit->addItems({"degree", "radian"});
        m_comboAngleUnit->setToolTip("Angle unit of the coordinates.");
        form->addRow("Angle Unit:", m_comboAngleUnit);

        m_valAngleUnit = m_comboAngleUnit->currentText();
        connect(m_comboAngleUnit, &QComboBox::currentTextChanged,
                this, [this](const QString &text) {
                    m_valAngleUnit = text;
                });

        // V3D-only options
        m_checkUndulatedGeom = new QCheckBox("Undulated Geometry");
        m_checkUndulatedGeom->setToolTip(
            "Use undulated (otherwise reference) geometry to determine "
            "the vertical location. Compatible only with vertical = RADIUS.");
        form->addRow(m_checkUndulatedGeom);

        m_valUndulatedGeom = m_checkUndulatedGeom->isChecked();
        connect(m_checkUndulatedGeom, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valUndulatedGeom = checked;
                });

        m_checkWholeElement = new QCheckBox("Whole Element Inplane");
        m_checkWholeElement->setToolTip(
            "Check inplane model range for the whole element. "
            "If true, the element center is used to determine whether it is "
            "within the inplane model range. If the center is in range, all "
            "its GLL points must also be in range or an exception will occur. "
            "Extend the model range slightly to allow for numerical errors. "
            "This safely realizes inplane discontinuities.");
        form->addRow(m_checkWholeElement);

        m_valWholeElement = m_checkWholeElement->isChecked();
        connect(m_checkWholeElement, &QCheckBox::toggled,
                this, [this](bool checked) {
                    m_valWholeElement = checked;
                });

        root->addWidget(m_grpCoords);
    }

    // ── properties group (V3D) ──
    {
        m_grpProps = new QGroupBox("Properties");
        auto *vbox = new QVBoxLayout(m_grpProps);

        auto *propLbl = new QLabel(
            "Material properties to perturb. Each property has:\n"
            "  Name — e.g. VP (P-wave velocity), VS (S-wave), RHO (density)\n"
            "  NC Var — NetCDF variable name in the data file\n"
            "  Factor — multiplier applied to the value read from file\n"
            "  Reference Kind:\n"
            "    ABS: X_3D = value_in_file (absolute)\n"
            "    REF1D: X_3D = (1 + value) * X_1D (perturbation w.r.t. 1D ref)\n"
            "    REF3D: X_3D = (1 + value) * X_3D (perturbation w.r.t. current 3D)\n"
            "    REF_PERTURB: X_3D = (1 + value) * (X_3D - X_1D) + X_1D");
        propLbl->setWordWrap(true);
        vbox->addWidget(propLbl);

        auto *countRow = new QHBoxLayout;
        countRow->addWidget(new QLabel("Number of Properties:"));
        m_spinPropCount = new QSpinBox;
        m_spinPropCount->setMinimum(1);
        m_spinPropCount->setMaximum(10);
        m_spinPropCount->setValue(2);
        countRow->addWidget(m_spinPropCount);
        countRow->addStretch();
        vbox->addLayout(countRow);

        m_valPropCount = m_spinPropCount->value();
        connect(m_spinPropCount, QOverload<int>::of(&QSpinBox::valueChanged),
                this, [this](int value) {
                    m_valPropCount = value;
                });

        // header row
        {
            auto *hdr = new QHBoxLayout;
            auto *lName = new QLabel("Name");   lName->setMinimumWidth(60);
            auto *lVar  = new QLabel("NC Var"); lVar->setMinimumWidth(80);
            auto *lFac  = new QLabel("Factor"); lFac->setMinimumWidth(60);
            auto *lRef  = new QLabel("Ref Kind");
            hdr->addWidget(lName);
            hdr->addWidget(lVar);
            hdr->addWidget(lFac);
            hdr->addWidget(lRef);
            vbox->addLayout(hdr);
        }

        m_propLayout = new QVBoxLayout;
        vbox->addLayout(m_propLayout);

        // start with 2 default properties
        addPropertyRow();  // VP
        addPropertyRow();  // VS
        if (!m_propRows.isEmpty()) {
            m_propRows[0].lineName->setText("VP");
            m_propRows[0].lineNcVar->setText("dvs");
            m_propRows[0].lineFactor->setText("0.005");
            m_propRows[0].comboRefKind->setCurrentText("REF1D");
        }
        if (m_propRows.size() >= 2) {
            m_propRows[1].lineName->setText("VS");
            m_propRows[1].lineNcVar->setText("dvs");
            m_propRows[1].lineFactor->setText("0.01");
            m_propRows[1].comboRefKind->setCurrentText("REF1D");
        }

        root->addWidget(m_grpProps);

        connect(m_spinPropCount, QOverload<int>::of(&QSpinBox::valueChanged),
                this, &Model3DWidget::onPropertyCountChanged);
    }

    // ── undulation group (G3D) ──
    {
        m_grpUndulation = new QGroupBox("Undulation");
        auto *form = new QFormLayout(m_grpUndulation);

        m_lineUndInterface = new QLineEdit("6371000.");
        m_lineUndInterface->setToolTip(
            "Interface location — the reference radius (in the length unit) "
            "of the discontinuity being undulated.");
        form->addRow("Interface Location:", m_lineUndInterface);

        m_valUndInterface = m_lineUndInterface->text();
        connect(m_lineUndInterface, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valUndInterface = text;
                });

        m_lineUndMinMax = new QLineEdit("[6346600., 6371000.01]");
        m_lineUndMinMax->setToolTip(
            "Undulation range [min, max] — the vertical range over which "
            "this geometric perturbation applies.");
        form->addRow("Min / Max:", m_lineUndMinMax);

        m_valUndMinMax = m_lineUndMinMax->text();
        connect(m_lineUndMinMax, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valUndMinMax = text;
                });

        m_lineUndNcVar = new QLineEdit("undulation_surf");
        m_lineUndNcVar->setToolTip(
            "NetCDF variable name containing the undulation data.");
        form->addRow("NC Variable:", m_lineUndNcVar);

        m_valUndNcVar = m_lineUndNcVar->text();
        connect(m_lineUndNcVar, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valUndNcVar = text;
                });

        m_lineUndFactor = new QLineEdit("0.5");
        m_lineUndFactor->setToolTip(
            "Factor multiplied to the undulation data read from the file.");
        form->addRow("Factor:", m_lineUndFactor);

        m_valUndFactor = m_lineUndFactor->text();
        connect(m_lineUndFactor, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valUndFactor = text;
                });

        root->addWidget(m_grpUndulation);
    }

    // ── ocean-load group (O3D) ──
    {
        m_grpOcean = new QGroupBox("Data: rho * depth (Ocean Load)");
        auto *form = new QFormLayout(m_grpOcean);

        auto *oceanLbl = new QLabel(
            "For ocean-load models, provide the NetCDF variable containing "
            "ocean depth, and the factor (typically water density, e.g. 1030 kg/m³) "
            "to compute rho * depth.");
        oceanLbl->setWordWrap(true);
        form->addRow(oceanLbl);

        m_lineOceanNcVar = new QLineEdit("ocean_depth");
        m_lineOceanNcVar->setToolTip(
            "NetCDF variable name for the ocean depth data.");
        form->addRow("NC Variable:", m_lineOceanNcVar);

        m_valOceanNcVar = m_lineOceanNcVar->text();
        connect(m_lineOceanNcVar, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valOceanNcVar = text;
                });

        m_lineOceanFactor = new QLineEdit("1030.");
        m_lineOceanFactor->setToolTip(
            "Factor multiplied to the data (typically water density "
            "in kg/m³, e.g. 1030.).");
        form->addRow("Factor:", m_lineOceanFactor);

        m_valOceanFactor = m_lineOceanFactor->text();
        connect(m_lineOceanFactor, &QLineEdit::textChanged,
                this, [this](const QString &text) {
                    m_valOceanFactor = text;
                });

        root->addWidget(m_grpOcean);
    }

    root->addWidget(hLine());

    // ── store on leaders ──
    m_checkStoreLeaders = new QCheckBox("Store Grid Data Only on Leader Processors");
    m_checkStoreLeaders->setChecked(true);
    m_checkStoreLeaders->setToolTip(
        "Turn this on if the model is large. Set mpi:nproc_per_group "
        "in inparam.advanced.yaml to the number of processors per node "
        "to minimize memory usage.");
    root->addWidget(m_checkStoreLeaders);

    m_valStoreLeaders = m_checkStoreLeaders->isChecked();
    connect(m_checkStoreLeaders, &QCheckBox::toggled,
            this, [this](bool checked) {
                m_valStoreLeaders = checked;
            });

    root->addStretch();

    // ── signals ──
    connect(m_comboClass, &QComboBox::currentTextChanged,
            this, &Model3DWidget::onClassChanged);
}

// ═══════════════════════════════════════════════════════════════
// show / hide sections based on class name
// ═══════════════════════════════════════════════════════════════

void Model3DWidget::onClassChanged(const QString &cls)
{
    updateVisibility(cls);
}

void Model3DWidget::updateVisibility(const QString &cls)
{
    bool isV3D  = (cls == "StructuredGridV3D");
    bool isG3D  = (cls == "StructuredGridG3D");
    bool isO3D  = (cls == "StructuredGridO3D");
    bool isEll  = (cls == "Ellipticity");

    bool hasFile   = !isEll;
    bool hasCoords = !isEll;

    m_ncFileRow->setVisible(hasFile);
    m_grpCoords->setVisible(hasCoords);

    // V3D-only coordinate fields
    m_checkUndulatedGeom->setVisible(isV3D);
    m_checkWholeElement->setVisible(isV3D);

    m_grpProps->setVisible(isV3D);
    m_grpUndulation->setVisible(isG3D);
    m_grpOcean->setVisible(isO3D);
    m_checkStoreLeaders->setVisible(!isEll);
}

// ═══════════════════════════════════════════════════════════════
// dynamic property rows (V3D)
// ═══════════════════════════════════════════════════════════════

void Model3DWidget::addPropertyRow()
{
    PropertyRow row;
    row.container = new QWidget;
    auto *h = new QHBoxLayout(row.container);
    h->setContentsMargins(0, 0, 0, 0);

    row.lineName = new QLineEdit;
    row.lineName->setPlaceholderText("e.g. VP");
    row.lineName->setMinimumWidth(60);

    row.lineNcVar = new QLineEdit;
    row.lineNcVar->setPlaceholderText("nc_var");
    row.lineNcVar->setMinimumWidth(80);

    row.lineFactor = new QLineEdit("1.");
    row.lineFactor->setMinimumWidth(60);

    row.comboRefKind = new QComboBox;
    row.comboRefKind->addItems({"ABS", "REF1D", "REF3D", "REF_PERTURB"});

    h->addWidget(row.lineName);
    h->addWidget(row.lineNcVar);
    h->addWidget(row.lineFactor);
    h->addWidget(row.comboRefKind);

    m_propLayout->addWidget(row.container);
    m_propRows.push_back(row);
}

void Model3DWidget::removePropertyRow()
{
    if (m_propRows.isEmpty()) return;
    PropertyRow row = m_propRows.takeLast();
    delete row.container;
}

void Model3DWidget::onPropertyCountChanged(int count)
{
    while (m_propRows.size() < count)
        addPropertyRow();
    while (m_propRows.size() > count)
        removePropertyRow();
}

// ═══════════════════════════════════════════════════════════════
// accessors — return the stored member variables
// ═══════════════════════════════════════════════════════════════

QString  Model3DWidget::modelName()   const { return m_valName; }
bool     Model3DWidget::activated()   const { return m_valActivated; }
QString  Model3DWidget::className()   const { return m_valClassName; }
QString  Model3DWidget::ncDataFile()  const { return m_valNcFile; }

QString  Model3DWidget::coordHorizontal()         const { return m_valHoriz; }
QString  Model3DWidget::coordVertical()           const { return m_valVert; }
bool     Model3DWidget::coordEllipticity()        const { return m_valEllipticity; }
bool     Model3DWidget::coordDepthBelowSolid()    const { return m_valDepthBelowSolid; }
QString  Model3DWidget::coordNcVariables()        const { return m_valNcVars; }
QString  Model3DWidget::coordDataRank()           const { return m_valDataRank; }
QString  Model3DWidget::coordLengthUnit()         const { return m_valLengthUnit; }
QString  Model3DWidget::coordAngleUnit()          const { return m_valAngleUnit; }
bool     Model3DWidget::coordUndulatedGeometry()  const { return m_valUndulatedGeom; }
bool     Model3DWidget::coordWholeElementInplane() const { return m_valWholeElement; }

int                    Model3DWidget::propertyCount() const { return m_propRows.size(); }
QVector<PropertyRow>   Model3DWidget::propertyRows()  const { return m_propRows; }

QString Model3DWidget::undulationInterface() const { return m_valUndInterface; }
QString Model3DWidget::undulationMinMax()    const { return m_valUndMinMax; }
QString Model3DWidget::undulationNcVar()     const { return m_valUndNcVar; }
QString Model3DWidget::undulationFactor()    const { return m_valUndFactor; }

QString Model3DWidget::oceanNcVar()    const { return m_valOceanNcVar; }
QString Model3DWidget::oceanFactor()   const { return m_valOceanFactor; }

bool    Model3DWidget::storeOnLeaders() const { return m_valStoreLeaders; }
