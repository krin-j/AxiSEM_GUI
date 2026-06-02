#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QProcess>
#include <QDir>
#include <QFileInfo>
#include "udpfieldswidget.h"
#include "model3dwidget.h"
#include "outputgroupwidget.h"
#include "sourcewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void onCodeIDChanged(const QString &text);
    void onModelCountChanged(int count);
    void onSSHConnect();
    void onStationGroupCountChanged(int count);
    void onSourceCountChanged(int count);
    void onRunSimulation();
    void onStopSimulation();

private:
    void generateYamlFiles(const QString &inputDir);
    void copyFileToInput(const QString &srcPath, const QString &inputDir);
    QProcess *m_simProcess = nullptr;
    Ui::MainWindow *ui;
    QVector<Model3DWidget*> m_modelWidgets;
    QVector<OutputGroupWidget*> m_outputGroupWidgets;
    QVector<SourceWidget*> m_sourceWidgets;
    bool m_isRemoteMode = false;

    // ── stored values: file paths ──
    QString meshFile;
    QString stationsFile;

    // ── stored values: advanced ──
    QString adv_verboseChannelType;
    QString adv_verboseFile;
    QString adv_verboseLevel;
    bool    adv_verboseWarnings = true;
    QString adv_loopInterval;
    QString adv_stabilityInterval;
    QString adv_numProcessors;
    QString adv_loadBalancing;
    bool    adv_plotDomainDecomp = false;
    bool    adv_diagnosePreloop = true;
    QString adv_maxTimeSteps;
    QString adv_timeLimitFFTW;
    bool    adv_FFTWLuckyNum = true;

    // ── stored values: model ──
    QString model_latLongNP;
    QString model_NP;
    QString model_flatteningSurface;
    QString model_flatteningNum;
    QString model_boundaries;
    bool    model_clayton = true;
    bool    model_Kosloff = true;
    QString model_relativeSpans;
    QString model_gammaSolid;
    QString model_gammaFluid;
    QString model_attenuation;

    // ── stored values: source time axis ──
    QString src_recordLength;
    QString src_enforcedDt;
    QString src_courantNumber;
    QString src_integrator;

    // ── stored values: nr ──
    QString nr_nrType;
    bool    nr_inplane = true;
    QString nr_constNr;
    QString nr_codeID;
    QString nr_controlDepths;
    QString nr_controlAtDepths;
    QString nr_pointwiseFile;
    QString nr_pointwiseNrFactor;
    QString nr_structuredFile;
    QString nr_structuredOutOfRange;
    bool    nr_wavefieldScanning = false;
    QString nr_wavefieldOutputFile;
    QString nr_thresholdFourierConv;
    QString nr_relativeAmpSkip;
    QString nr_absAmpSkip;
    QString nr_maxNumPeaks;
    bool    nr_scanOnlyVertexGLL = true;
    QString nr_numStepsPerMeshPeriod;
};

#endif // MAINWINDOW_H