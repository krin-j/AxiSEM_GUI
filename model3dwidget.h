#ifndef MODEL3DWIDGET_H
#define MODEL3DWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QVector>

// ── one row in the properties table ──
struct PropertyRow {
    QWidget   *container;
    QLineEdit *lineName;     // e.g. VP, VS, RHO
    QLineEdit *lineNcVar;
    QLineEdit *lineFactor;
    QComboBox *comboRefKind;
};

class Model3DWidget : public QGroupBox
{
    Q_OBJECT

public:
    explicit Model3DWidget(int index, QWidget *parent = nullptr);
    ~Model3DWidget() override;

    // ── accessors (for YAML generation later) ──
    QString  modelName()   const;
    bool     activated()   const;
    QString  className()   const;
    QString  ncDataFile()  const;

    // coordinates
    QString  coordHorizontal()         const;
    QString  coordVertical()           const;
    bool     coordEllipticity()        const;
    bool     coordDepthBelowSolid()    const;
    QString  coordNcVariables()        const;
    QString  coordDataRank()           const;
    QString  coordLengthUnit()         const;
    QString  coordAngleUnit()          const;
    bool     coordUndulatedGeometry()  const;
    bool     coordWholeElementInplane() const;

    // properties (V3D)
    int                       propertyCount() const;
    QVector<PropertyRow>      propertyRows()  const;

    // undulation (G3D)
    QString undulationInterface() const;
    QString undulationMinMax()    const;
    QString undulationNcVar()     const;
    QString undulationFactor()    const;

    // ocean-load (O3D)
    QString oceanNcVar()    const;
    QString oceanFactor()   const;

    bool    storeOnLeaders() const;

private slots:
    void onClassChanged(const QString &cls);
    void onPropertyCountChanged(int count);

private:
    void buildUi();
    void addPropertyRow();
    void removePropertyRow();
    void updateVisibility(const QString &cls);

    int m_index;

    // ── widgets ──
    // top-level
    QLineEdit *m_lineName;
    QCheckBox *m_checkActivated;
    QComboBox *m_comboClass;

    // nc data file
    QWidget    *m_ncFileRow;
    QPushButton *m_btnBrowseNc;
    QLineEdit  *m_lineNcFile;

    // coordinates group
    QGroupBox  *m_grpCoords;
    QComboBox  *m_comboHoriz;
    QComboBox  *m_comboVert;
    QCheckBox  *m_checkEllipticity;
    QCheckBox  *m_checkDepthBelowSolid;
    QLineEdit  *m_lineNcVars;
    QLineEdit  *m_lineDataRank;
    QComboBox  *m_comboLengthUnit;
    QComboBox  *m_comboAngleUnit;
    QCheckBox  *m_checkUndulatedGeom;
    QCheckBox  *m_checkWholeElement;

    // properties group (V3D)
    QGroupBox              *m_grpProps;
    QSpinBox               *m_spinPropCount;
    QVBoxLayout            *m_propLayout;
    QVector<PropertyRow>    m_propRows;

    // undulation group (G3D)
    QGroupBox  *m_grpUndulation;
    QLineEdit  *m_lineUndInterface;
    QLineEdit  *m_lineUndMinMax;
    QLineEdit  *m_lineUndNcVar;
    QLineEdit  *m_lineUndFactor;

    // ocean-load group (O3D)
    QGroupBox  *m_grpOcean;
    QLineEdit  *m_lineOceanNcVar;
    QLineEdit  *m_lineOceanFactor;

    // store on leaders
    QCheckBox  *m_checkStoreLeaders;

    // ── stored values (updated on every change) ──
    QString m_valName;
    bool    m_valActivated              = true;
    QString m_valClassName;
    QString m_valNcFile;
    QString m_valHoriz;
    QString m_valVert;
    bool    m_valEllipticity            = false;
    bool    m_valDepthBelowSolid        = false;
    QString m_valNcVars;
    QString m_valDataRank;
    QString m_valLengthUnit;
    QString m_valAngleUnit;
    bool    m_valUndulatedGeom          = false;
    bool    m_valWholeElement           = false;
    int     m_valPropCount              = 2;
    QString m_valUndInterface;
    QString m_valUndMinMax;
    QString m_valUndNcVar;
    QString m_valUndFactor;
    QString m_valOceanNcVar;
    QString m_valOceanFactor;
    bool    m_valStoreLeaders           = true;
};

#endif // MODEL3DWIDGET_H
