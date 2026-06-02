#ifndef OUTPUTGROUPWIDGET_H
#define OUTPUTGROUPWIDGET_H

#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>

class OutputGroupWidget : public QGroupBox
{
    Q_OBJECT

public:
    explicit OutputGroupWidget(int index, QWidget *parent = nullptr);
    ~OutputGroupWidget() override;

    // ── accessors ──
    QString groupName()        const;

    // locations
    QString stationFile()      const;
    QString horizontalCoord()  const;
    QString verticalCoord()    const;
    bool    locEllipticity()   const;
    bool    locDepthBelowSolid() const;
    bool    locUndulatedGeom() const;

    // wavefields
    QString coordFrame()       const;
    QString medium()           const;
    QString channels()         const;

    // temporal
    QString samplingPeriod()   const;
    QString timeWindow()       const;

    // file options
    QString fileFormat()       const;
    int     bufferSize()       const;
    bool    flush()            const;

private:
    void buildUi();

    int m_index;

    // ── widgets ──
    // top-level
    QLineEdit  *m_lineGroupName;

    // locations
    QPushButton *m_btnBrowseStation;
    QLineEdit  *m_lineStationFile;
    QComboBox  *m_comboHorizCoord;
    QComboBox  *m_comboVertCoord;
    QCheckBox  *m_checkLocEllipticity;
    QCheckBox  *m_checkLocDepthBelowSolid;
    QCheckBox  *m_checkLocUndulatedGeom;

    // wavefields
    QComboBox  *m_comboCoordFrame;
    QComboBox  *m_comboMedium;
    QLineEdit  *m_lineChannels;

    // temporal
    QLineEdit  *m_lineSamplingPeriod;
    QLineEdit  *m_lineTimeWindow;

    // file options
    QComboBox  *m_comboFormat;
    QSpinBox   *m_spinBufferSize;
    QCheckBox  *m_checkFlush;

    // ── stored values (updated on every change) ──
    QString m_valGroupName;
    QString m_valStationFile;
    QString m_valHorizCoord;
    QString m_valVertCoord;
    bool    m_valLocEllipticity       = true;
    bool    m_valLocDepthBelowSolid   = true;
    bool    m_valLocUndulatedGeom     = true;
    QString m_valCoordFrame;
    QString m_valMedium;
    QString m_valChannels;
    QString m_valSamplingPeriod;
    QString m_valTimeWindow;
    QString m_valFormat;
    int     m_valBufferSize           = 1000;
    bool    m_valFlush                = true;
};

#endif // OUTPUTGROUPWIDGET_H
