#ifndef SOURCEWIDGET_H
#define SOURCEWIDGET_H

#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>

class SourceWidget : public QGroupBox
{
    Q_OBJECT

public:
    explicit SourceWidget(int index, QWidget *parent = nullptr);
    ~SourceWidget() override;

    // ── accessors ──
    QString sourceName() const;

    // location
    QString locHorizType()       const;
    QString locHorizCoords()     const;
    QString locVertType()        const;
    QString locVertValue()       const;
    bool    locEllipticity()     const;
    bool    locDepthBelowSolid() const;
    bool    locUndulatedGeom()   const;

    // mechanism
    QString mechType()  const;
    QString mechData()  const;
    QString mechUnit()  const;

    // source time function
    QString stfClassName() const;

    // GaussianSTF
    QString stfHalfDuration()     const;
    QString stfDecayFactor()      const;
    QString stfTimeShift()        const;
    QString stfDerivIntegral()    const;

    // StreamSTF
    QString stfAsciiFile()        const;
    QString stfStreamPadding()    const;

    // NetCDF_STF
    QString stfNcFile()           const;
    QString stfNcVarTimes()       const;
    QString stfNcVarData()        const;
    QString stfNcPadding()        const;
    QString stfNcChunkSize()      const;

private slots:
    void onMechTypeChanged(const QString &text);
    void onStfClassChanged(const QString &text);

private:
    void buildUi();
    void updateMechVisibility(const QString &type);
    void updateStfVisibility(const QString &cls);

    int m_index;

    // ── widgets ──
    QLineEdit *m_lineName;

    // location
    QComboBox *m_comboHorizType;
    QLineEdit *m_lineHorizCoords;
    QComboBox *m_comboVertType;
    QLineEdit *m_lineVertValue;
    QCheckBox *m_checkLocEllipticity;
    QCheckBox *m_checkLocDepthBelowSolid;
    QCheckBox *m_checkLocUndulatedGeom;

    // mechanism
    QComboBox *m_comboMechType;
    QLabel    *m_lblMechDataHint;
    QLineEdit *m_lineMechData;
    QLineEdit *m_lineMechUnit;

    // STF
    QComboBox *m_comboStfClass;

    // GaussianSTF widgets
    QWidget   *m_gaussianGroup;
    QLineEdit *m_lineHalfDuration;
    QLineEdit *m_lineDecayFactor;
    QLineEdit *m_lineTimeShift;
    QComboBox *m_comboDerivIntegral;

    // StreamSTF widgets
    QWidget   *m_streamGroup;
    QPushButton *m_btnBrowseAscii;
    QLineEdit *m_lineAsciiFile;
    QLineEdit *m_lineStreamPadding;

    // NetCDF_STF widgets
    QWidget   *m_netcdfGroup;
    QPushButton *m_btnBrowseNcStf;
    QLineEdit *m_lineNcStfFile;
    QLineEdit *m_lineNcVarTimes;
    QLineEdit *m_lineNcVarData;
    QLineEdit *m_lineNcPadding;
    QLineEdit *m_lineNcChunkSize;

    // ── stored values ──
    QString m_valName;

    QString m_valHorizType;
    QString m_valHorizCoords;
    QString m_valVertType;
    QString m_valVertValue;
    bool    m_valLocEllipticity       = true;
    bool    m_valLocDepthBelowSolid   = true;
    bool    m_valLocUndulatedGeom     = true;

    QString m_valMechType;
    QString m_valMechData;
    QString m_valMechUnit;

    QString m_valStfClass;

    QString m_valHalfDuration;
    QString m_valDecayFactor;
    QString m_valTimeShift;
    QString m_valDerivIntegral;

    QString m_valAsciiFile;
    QString m_valStreamPadding;

    QString m_valNcStfFile;
    QString m_valNcVarTimes;
    QString m_valNcVarData;
    QString m_valNcPadding;
    QString m_valNcChunkSize;
};

#endif // SOURCEWIDGET_H
