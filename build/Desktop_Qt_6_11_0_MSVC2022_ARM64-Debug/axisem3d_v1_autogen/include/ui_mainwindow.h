/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "udpfieldswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_home;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelMain;
    QPushButton *btnLocal;
    QPushButton *btnRemote;
    QWidget *page_local;
    QGridLayout *gridLayout_2;
    QLineEdit *lineStationsPath;
    QPushButton *btnModel3D;
    QPushButton *btnOutput;
    QPushButton *btnAdvanced;
    QPushButton *btnModel;
    QPushButton *btnBrowseMesh;
    QPushButton *btnBrowseStations;
    QStackedWidget *stackedLocalSections;
    QWidget *page_advanced;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *grpVerbose;
    QFormLayout *formVerbose;
    QLabel *label_4;
    QComboBox *comboVerboseChannel;
    QPushButton *btnBrowseVerboseChannel;
    QLineEdit *lineVerboseChannelPath;
    QLabel *label_5;
    QComboBox *comboVerboseLevel;
    QCheckBox *checkVerboseWarnings;
    QLabel *label_7;
    QLineEdit *lineLoopInterval;
    QLabel *label_8;
    QLineEdit *lineStabilityInterval;
    QGroupBox *grpMPI;
    QFormLayout *formMPI;
    QLabel *label_9;
    QLineEdit *lineNumProcessorsPerGroup;
    QLabel *label_10;
    QComboBox *loadBalancingBox;
    QCheckBox *checkBoxPlotDomainDecomp;
    QGroupBox *grpDevelop;
    QFormLayout *formDevelop;
    QCheckBox *checkBoxDiagnosePreloop;
    QLabel *label_12;
    QLineEdit *lineMaxNumTimeSteps;
    QLabel *label_13;
    QLineEdit *lineTimeLimitFFTW;
    QCheckBox *checkBoxFFTWLuckyNum;
    QWidget *page_model;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *grpGeodesy;
    QFormLayout *formGeodesy;
    QLabel *label_15;
    QComboBox *comboBoxLatLongNP;
    QLabel *label_14;
    QLineEdit *lineEditNP;
    QLabel *label_16;
    QComboBox *comboBoxFlatteningSurface;
    QLabel *label_17;
    QLineEdit *lineFlatteningCustomNum;
    QGroupBox *grpAbsorbingBoundaries;
    QFormLayout *formAbsorbingBoundaries;
    QLabel *label_18;
    QLineEdit *lineBoundaries;
    QCheckBox *checkBoxClayton;
    QLabel *label_19;
    QCheckBox *checkBoxKosloff;
    QLabel *label_20;
    QLineEdit *lineRelativeSpans;
    QLabel *label_22;
    QLineEdit *lineGammaSolid;
    QLabel *label_23;
    QLineEdit *lineGammaFluid;
    QGroupBox *grpAttenuation;
    QFormLayout *formAttenuation;
    QLabel *label_24;
    QComboBox *attenuationBox;
    QWidget *page_3d;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_25;
    QSpinBox *boxHowMany3D;
    QScrollArea *scrollArea3D;
    QWidget *scrollAreaContents3D;
    QVBoxLayout *layout3DModels;
    QSpacerItem *spacer3D;
    QWidget *page_nr;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *grpNrType;
    QFormLayout *formNrType;
    QLabel *label_26;
    QComboBox *comboBoxNrType;
    QCheckBox *checkBoxNrInplane;
    QGroupBox *grpConstant;
    QFormLayout *formConstant;
    QLabel *label_27;
    QLineEdit *lineConstNr;
    QGroupBox *grpAnalytical;
    QFormLayout *formAnalytical;
    QLabel *label_29;
    QLineEdit *lineEditCodeID;
    QLabel *label_21;
    QLabel *labelCodeID;
    QLabel *label_30;
    QLineEdit *lineNrControlDepths;
    QLabel *label_31;
    QLineEdit *lineNrAtControlDepths;
    QLabel *label_32;
    UDPFieldsWidget *udpWidget;
    QGroupBox *grpPointwise;
    QFormLayout *formPointwise;
    QLabel *label_34;
    QPushButton *btnBrowsePointwise;
    QLabel *label_33;
    QLineEdit *linePointwisePath;
    QLabel *label_37;
    QLineEdit *lineNrFactor;
    QGroupBox *grpStructured;
    QFormLayout *formStructured;
    QLabel *label_39;
    QPushButton *pushBrowseStructured;
    QLabel *label_38;
    QLineEdit *lineStructuredPath;
    QLabel *label_40;
    QLineEdit *lineStructuredOutOfRange;
    QGroupBox *grpWavefieldScanning;
    QFormLayout *formWavefieldScanning;
    QCheckBox *checkWavefieldScanningOn;
    QLabel *label_43;
    QLineEdit *lineWavefieldOutputFile;
    QLabel *label_44;
    QLineEdit *lineThresholdFourierConv;
    QLabel *label_45;
    QLineEdit *lineRelativeAmpSkip;
    QLabel *label_47;
    QLineEdit *lineAbsAmpSkip;
    QLabel *label_48;
    QLineEdit *lineMaxNumPeaks;
    QCheckBox *checkScanOnlyVertexGLL;
    QLabel *label_49;
    QLineEdit *lineNumStepsPerMeshPeriod;
    QWidget *page_source;
    QVBoxLayout *verticalLayout_source;
    QGroupBox *grpTimeAxis;
    QFormLayout *formTimeAxis;
    QLabel *lblRecordLength;
    QLineEdit *lineRecordLength;
    QLabel *lblEnforcedDt;
    QLineEdit *lineEnforcedDt;
    QLabel *lblCourant;
    QLineEdit *lineCourantNumber;
    QLabel *lblIntegrator;
    QComboBox *comboIntegrator;
    QHBoxLayout *layoutSourceCount;
    QLabel *labelSourceCount;
    QSpinBox *spinSourceCount;
    QScrollArea *scrollAreaSource;
    QWidget *scrollAreaContentsSource;
    QVBoxLayout *layoutSources;
    QSpacerItem *spacerSources;
    QWidget *page_output;
    QVBoxLayout *verticalLayout_output;
    QLabel *labelOutputTitle;
    QHBoxLayout *layoutOutputCount;
    QLabel *labelOutputCount;
    QSpinBox *spinStationGroupCount;
    QScrollArea *scrollAreaOutput;
    QWidget *scrollAreaContentsOutput;
    QVBoxLayout *layoutOutputGroups;
    QSpacerItem *spacerOutput;
    QLabel *labelElementWise;
    QPushButton *btnNr;
    QPushButton *btnRun;
    QLabel *label;
    QLineEdit *lineMeshPath;
    QLabel *label_2;
    QPushButton *btnSource;
    QPushButton *btnBackL;
    QWidget *page_run;
    QVBoxLayout *verticalLayout_run;
    QGroupBox *grpExePath;
    QFormLayout *formExePath;
    QPushButton *btnBrowseExe;
    QLineEdit *lineExePath;
    QLabel *lblMpiProcs;
    QSpinBox *spinMpiProcs;
    QGroupBox *grpBatchJob;
    QVBoxLayout *layoutBatchJob;
    QCheckBox *checkBatchJob;
    QHBoxLayout *layoutBatchFilename;
    QLabel *lblBatchFilename;
    QLineEdit *lineBatchFilename;
    QPlainTextEdit *editBatchScript;
    QHBoxLayout *layoutRunButtons;
    QPushButton *btnRunSim;
    QPushButton *btnStopSim;
    QPushButton *btnBackRun;
    QGroupBox *grpRunLog;
    QVBoxLayout *layoutRunLog;
    QPlainTextEdit *editRunLog;
    QWidget *page_remote;
    QVBoxLayout *verticalLayout_remote;
    QSpacerItem *spacerRemoteTop;
    QLabel *labelSSHTitle;
    QFormLayout *formSSH;
    QLabel *labelHost;
    QLineEdit *lineSSHHost;
    QLabel *labelPort;
    QLineEdit *lineSSHPort;
    QLabel *labelUsername;
    QLineEdit *lineSSHUser;
    QLabel *labelPassword;
    QLineEdit *lineSSHPass;
    QLabel *labelSSHStatus;
    QHBoxLayout *layoutSSHButtons;
    QPushButton *btnBackR;
    QPushButton *btnSSHConnect;
    QSpacerItem *spacerRemoteBottom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(633, 601);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_home = new QWidget();
        page_home->setObjectName("page_home");
        verticalLayout_8 = new QVBoxLayout(page_home);
        verticalLayout_8->setObjectName("verticalLayout_8");
        labelMain = new QLabel(page_home);
        labelMain->setObjectName("labelMain");
        QFont font;
        font.setFamilies({QString::fromUtf8("Imprint MT Shadow")});
        font.setPointSize(72);
        labelMain->setFont(font);
        labelMain->setScaledContents(true);
        labelMain->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(labelMain);

        btnLocal = new QPushButton(page_home);
        btnLocal->setObjectName("btnLocal");

        verticalLayout_8->addWidget(btnLocal);

        btnRemote = new QPushButton(page_home);
        btnRemote->setObjectName("btnRemote");

        verticalLayout_8->addWidget(btnRemote);

        stackedWidget->addWidget(page_home);
        page_local = new QWidget();
        page_local->setObjectName("page_local");
        gridLayout_2 = new QGridLayout(page_local);
        gridLayout_2->setObjectName("gridLayout_2");
        lineStationsPath = new QLineEdit(page_local);
        lineStationsPath->setObjectName("lineStationsPath");

        gridLayout_2->addWidget(lineStationsPath, 2, 5, 1, 2);

        btnModel3D = new QPushButton(page_local);
        btnModel3D->setObjectName("btnModel3D");
        btnModel3D->setMinimumSize(QSize(0, 35));

        gridLayout_2->addWidget(btnModel3D, 3, 2, 1, 1);

        btnOutput = new QPushButton(page_local);
        btnOutput->setObjectName("btnOutput");
        btnOutput->setMinimumSize(QSize(0, 35));

        gridLayout_2->addWidget(btnOutput, 3, 4, 1, 1);

        btnAdvanced = new QPushButton(page_local);
        btnAdvanced->setObjectName("btnAdvanced");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnAdvanced->sizePolicy().hasHeightForWidth());
        btnAdvanced->setSizePolicy(sizePolicy);
        btnAdvanced->setMinimumSize(QSize(0, 35));

        gridLayout_2->addWidget(btnAdvanced, 3, 0, 1, 1);

        btnModel = new QPushButton(page_local);
        btnModel->setObjectName("btnModel");
        btnModel->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnModel, 3, 1, 1, 1);

        btnBrowseMesh = new QPushButton(page_local);
        btnBrowseMesh->setObjectName("btnBrowseMesh");

        gridLayout_2->addWidget(btnBrowseMesh, 1, 0, 1, 2);

        btnBrowseStations = new QPushButton(page_local);
        btnBrowseStations->setObjectName("btnBrowseStations");

        gridLayout_2->addWidget(btnBrowseStations, 1, 5, 1, 2);

        stackedLocalSections = new QStackedWidget(page_local);
        stackedLocalSections->setObjectName("stackedLocalSections");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedLocalSections->sizePolicy().hasHeightForWidth());
        stackedLocalSections->setSizePolicy(sizePolicy1);
        page_advanced = new QWidget();
        page_advanced->setObjectName("page_advanced");
        verticalLayout = new QVBoxLayout(page_advanced);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(page_advanced);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 257, 425));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        grpVerbose = new QGroupBox(scrollAreaWidgetContents);
        grpVerbose->setObjectName("grpVerbose");
        formVerbose = new QFormLayout(grpVerbose);
        formVerbose->setObjectName("formVerbose");
        label_4 = new QLabel(grpVerbose);
        label_4->setObjectName("label_4");

        formVerbose->setWidget(0, QFormLayout::ItemRole::LabelRole, label_4);

        comboVerboseChannel = new QComboBox(grpVerbose);
        comboVerboseChannel->addItem(QString());
        comboVerboseChannel->addItem(QString());
        comboVerboseChannel->setObjectName("comboVerboseChannel");

        formVerbose->setWidget(0, QFormLayout::ItemRole::FieldRole, comboVerboseChannel);

        btnBrowseVerboseChannel = new QPushButton(grpVerbose);
        btnBrowseVerboseChannel->setObjectName("btnBrowseVerboseChannel");

        formVerbose->setWidget(1, QFormLayout::ItemRole::LabelRole, btnBrowseVerboseChannel);

        lineVerboseChannelPath = new QLineEdit(grpVerbose);
        lineVerboseChannelPath->setObjectName("lineVerboseChannelPath");

        formVerbose->setWidget(1, QFormLayout::ItemRole::FieldRole, lineVerboseChannelPath);

        label_5 = new QLabel(grpVerbose);
        label_5->setObjectName("label_5");

        formVerbose->setWidget(2, QFormLayout::ItemRole::LabelRole, label_5);

        comboVerboseLevel = new QComboBox(grpVerbose);
        comboVerboseLevel->addItem(QString());
        comboVerboseLevel->addItem(QString());
        comboVerboseLevel->addItem(QString());
        comboVerboseLevel->setObjectName("comboVerboseLevel");

        formVerbose->setWidget(2, QFormLayout::ItemRole::FieldRole, comboVerboseLevel);

        checkVerboseWarnings = new QCheckBox(grpVerbose);
        checkVerboseWarnings->setObjectName("checkVerboseWarnings");

        formVerbose->setWidget(3, QFormLayout::ItemRole::FieldRole, checkVerboseWarnings);

        label_7 = new QLabel(grpVerbose);
        label_7->setObjectName("label_7");

        formVerbose->setWidget(4, QFormLayout::ItemRole::LabelRole, label_7);

        lineLoopInterval = new QLineEdit(grpVerbose);
        lineLoopInterval->setObjectName("lineLoopInterval");

        formVerbose->setWidget(4, QFormLayout::ItemRole::FieldRole, lineLoopInterval);

        label_8 = new QLabel(grpVerbose);
        label_8->setObjectName("label_8");

        formVerbose->setWidget(5, QFormLayout::ItemRole::LabelRole, label_8);

        lineStabilityInterval = new QLineEdit(grpVerbose);
        lineStabilityInterval->setObjectName("lineStabilityInterval");

        formVerbose->setWidget(5, QFormLayout::ItemRole::FieldRole, lineStabilityInterval);


        verticalLayout_2->addWidget(grpVerbose);

        grpMPI = new QGroupBox(scrollAreaWidgetContents);
        grpMPI->setObjectName("grpMPI");
        formMPI = new QFormLayout(grpMPI);
        formMPI->setObjectName("formMPI");
        label_9 = new QLabel(grpMPI);
        label_9->setObjectName("label_9");

        formMPI->setWidget(0, QFormLayout::ItemRole::LabelRole, label_9);

        lineNumProcessorsPerGroup = new QLineEdit(grpMPI);
        lineNumProcessorsPerGroup->setObjectName("lineNumProcessorsPerGroup");

        formMPI->setWidget(0, QFormLayout::ItemRole::FieldRole, lineNumProcessorsPerGroup);

        label_10 = new QLabel(grpMPI);
        label_10->setObjectName("label_10");

        formMPI->setWidget(1, QFormLayout::ItemRole::LabelRole, label_10);

        loadBalancingBox = new QComboBox(grpMPI);
        loadBalancingBox->addItem(QString());
        loadBalancingBox->addItem(QString());
        loadBalancingBox->setObjectName("loadBalancingBox");

        formMPI->setWidget(1, QFormLayout::ItemRole::FieldRole, loadBalancingBox);

        checkBoxPlotDomainDecomp = new QCheckBox(grpMPI);
        checkBoxPlotDomainDecomp->setObjectName("checkBoxPlotDomainDecomp");

        formMPI->setWidget(2, QFormLayout::ItemRole::FieldRole, checkBoxPlotDomainDecomp);


        verticalLayout_2->addWidget(grpMPI);

        grpDevelop = new QGroupBox(scrollAreaWidgetContents);
        grpDevelop->setObjectName("grpDevelop");
        formDevelop = new QFormLayout(grpDevelop);
        formDevelop->setObjectName("formDevelop");
        checkBoxDiagnosePreloop = new QCheckBox(grpDevelop);
        checkBoxDiagnosePreloop->setObjectName("checkBoxDiagnosePreloop");

        formDevelop->setWidget(0, QFormLayout::ItemRole::FieldRole, checkBoxDiagnosePreloop);

        label_12 = new QLabel(grpDevelop);
        label_12->setObjectName("label_12");

        formDevelop->setWidget(1, QFormLayout::ItemRole::LabelRole, label_12);

        lineMaxNumTimeSteps = new QLineEdit(grpDevelop);
        lineMaxNumTimeSteps->setObjectName("lineMaxNumTimeSteps");

        formDevelop->setWidget(1, QFormLayout::ItemRole::FieldRole, lineMaxNumTimeSteps);

        label_13 = new QLabel(grpDevelop);
        label_13->setObjectName("label_13");

        formDevelop->setWidget(2, QFormLayout::ItemRole::LabelRole, label_13);

        lineTimeLimitFFTW = new QLineEdit(grpDevelop);
        lineTimeLimitFFTW->setObjectName("lineTimeLimitFFTW");

        formDevelop->setWidget(2, QFormLayout::ItemRole::FieldRole, lineTimeLimitFFTW);

        checkBoxFFTWLuckyNum = new QCheckBox(grpDevelop);
        checkBoxFFTWLuckyNum->setObjectName("checkBoxFFTWLuckyNum");

        formDevelop->setWidget(3, QFormLayout::ItemRole::FieldRole, checkBoxFFTWLuckyNum);


        verticalLayout_2->addWidget(grpDevelop);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        stackedLocalSections->addWidget(page_advanced);
        page_model = new QWidget();
        page_model->setObjectName("page_model");
        verticalLayout_4 = new QVBoxLayout(page_model);
        verticalLayout_4->setObjectName("verticalLayout_4");
        scrollArea_2 = new QScrollArea(page_model);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 470, 383));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        grpGeodesy = new QGroupBox(scrollAreaWidgetContents_2);
        grpGeodesy->setObjectName("grpGeodesy");
        formGeodesy = new QFormLayout(grpGeodesy);
        formGeodesy->setObjectName("formGeodesy");
        label_15 = new QLabel(grpGeodesy);
        label_15->setObjectName("label_15");

        formGeodesy->setWidget(0, QFormLayout::ItemRole::LabelRole, label_15);

        comboBoxLatLongNP = new QComboBox(grpGeodesy);
        comboBoxLatLongNP->addItem(QString());
        comboBoxLatLongNP->addItem(QString());
        comboBoxLatLongNP->setObjectName("comboBoxLatLongNP");

        formGeodesy->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBoxLatLongNP);

        label_14 = new QLabel(grpGeodesy);
        label_14->setObjectName("label_14");

        formGeodesy->setWidget(1, QFormLayout::ItemRole::LabelRole, label_14);

        lineEditNP = new QLineEdit(grpGeodesy);
        lineEditNP->setObjectName("lineEditNP");

        formGeodesy->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEditNP);

        label_16 = new QLabel(grpGeodesy);
        label_16->setObjectName("label_16");

        formGeodesy->setWidget(2, QFormLayout::ItemRole::LabelRole, label_16);

        comboBoxFlatteningSurface = new QComboBox(grpGeodesy);
        comboBoxFlatteningSurface->addItem(QString());
        comboBoxFlatteningSurface->addItem(QString());
        comboBoxFlatteningSurface->addItem(QString());
        comboBoxFlatteningSurface->addItem(QString());
        comboBoxFlatteningSurface->addItem(QString());
        comboBoxFlatteningSurface->setObjectName("comboBoxFlatteningSurface");

        formGeodesy->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBoxFlatteningSurface);

        label_17 = new QLabel(grpGeodesy);
        label_17->setObjectName("label_17");

        formGeodesy->setWidget(3, QFormLayout::ItemRole::LabelRole, label_17);

        lineFlatteningCustomNum = new QLineEdit(grpGeodesy);
        lineFlatteningCustomNum->setObjectName("lineFlatteningCustomNum");

        formGeodesy->setWidget(3, QFormLayout::ItemRole::FieldRole, lineFlatteningCustomNum);


        verticalLayout_3->addWidget(grpGeodesy);

        grpAbsorbingBoundaries = new QGroupBox(scrollAreaWidgetContents_2);
        grpAbsorbingBoundaries->setObjectName("grpAbsorbingBoundaries");
        formAbsorbingBoundaries = new QFormLayout(grpAbsorbingBoundaries);
        formAbsorbingBoundaries->setObjectName("formAbsorbingBoundaries");
        label_18 = new QLabel(grpAbsorbingBoundaries);
        label_18->setObjectName("label_18");

        formAbsorbingBoundaries->setWidget(0, QFormLayout::ItemRole::LabelRole, label_18);

        lineBoundaries = new QLineEdit(grpAbsorbingBoundaries);
        lineBoundaries->setObjectName("lineBoundaries");

        formAbsorbingBoundaries->setWidget(0, QFormLayout::ItemRole::FieldRole, lineBoundaries);

        checkBoxClayton = new QCheckBox(grpAbsorbingBoundaries);
        checkBoxClayton->setObjectName("checkBoxClayton");

        formAbsorbingBoundaries->setWidget(1, QFormLayout::ItemRole::FieldRole, checkBoxClayton);

        label_19 = new QLabel(grpAbsorbingBoundaries);
        label_19->setObjectName("label_19");

        formAbsorbingBoundaries->setWidget(2, QFormLayout::ItemRole::LabelRole, label_19);

        checkBoxKosloff = new QCheckBox(grpAbsorbingBoundaries);
        checkBoxKosloff->setObjectName("checkBoxKosloff");

        formAbsorbingBoundaries->setWidget(2, QFormLayout::ItemRole::FieldRole, checkBoxKosloff);

        label_20 = new QLabel(grpAbsorbingBoundaries);
        label_20->setObjectName("label_20");

        formAbsorbingBoundaries->setWidget(3, QFormLayout::ItemRole::LabelRole, label_20);

        lineRelativeSpans = new QLineEdit(grpAbsorbingBoundaries);
        lineRelativeSpans->setObjectName("lineRelativeSpans");

        formAbsorbingBoundaries->setWidget(3, QFormLayout::ItemRole::FieldRole, lineRelativeSpans);

        label_22 = new QLabel(grpAbsorbingBoundaries);
        label_22->setObjectName("label_22");

        formAbsorbingBoundaries->setWidget(4, QFormLayout::ItemRole::LabelRole, label_22);

        lineGammaSolid = new QLineEdit(grpAbsorbingBoundaries);
        lineGammaSolid->setObjectName("lineGammaSolid");

        formAbsorbingBoundaries->setWidget(4, QFormLayout::ItemRole::FieldRole, lineGammaSolid);

        label_23 = new QLabel(grpAbsorbingBoundaries);
        label_23->setObjectName("label_23");

        formAbsorbingBoundaries->setWidget(5, QFormLayout::ItemRole::LabelRole, label_23);

        lineGammaFluid = new QLineEdit(grpAbsorbingBoundaries);
        lineGammaFluid->setObjectName("lineGammaFluid");

        formAbsorbingBoundaries->setWidget(5, QFormLayout::ItemRole::FieldRole, lineGammaFluid);


        verticalLayout_3->addWidget(grpAbsorbingBoundaries);

        grpAttenuation = new QGroupBox(scrollAreaWidgetContents_2);
        grpAttenuation->setObjectName("grpAttenuation");
        formAttenuation = new QFormLayout(grpAttenuation);
        formAttenuation->setObjectName("formAttenuation");
        label_24 = new QLabel(grpAttenuation);
        label_24->setObjectName("label_24");

        formAttenuation->setWidget(0, QFormLayout::ItemRole::LabelRole, label_24);

        attenuationBox = new QComboBox(grpAttenuation);
        attenuationBox->addItem(QString());
        attenuationBox->addItem(QString());
        attenuationBox->addItem(QString());
        attenuationBox->setObjectName("attenuationBox");

        formAttenuation->setWidget(0, QFormLayout::ItemRole::FieldRole, attenuationBox);


        verticalLayout_3->addWidget(grpAttenuation);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_4->addWidget(scrollArea_2);

        stackedLocalSections->addWidget(page_model);
        page_3d = new QWidget();
        page_3d->setObjectName("page_3d");
        verticalLayout_5 = new QVBoxLayout(page_3d);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_25 = new QLabel(page_3d);
        label_25->setObjectName("label_25");
        label_25->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_25);

        boxHowMany3D = new QSpinBox(page_3d);
        boxHowMany3D->setObjectName("boxHowMany3D");

        verticalLayout_5->addWidget(boxHowMany3D);

        scrollArea3D = new QScrollArea(page_3d);
        scrollArea3D->setObjectName("scrollArea3D");
        scrollArea3D->setWidgetResizable(true);
        scrollAreaContents3D = new QWidget();
        scrollAreaContents3D->setObjectName("scrollAreaContents3D");
        scrollAreaContents3D->setGeometry(QRect(0, 0, 76, 16));
        layout3DModels = new QVBoxLayout(scrollAreaContents3D);
        layout3DModels->setObjectName("layout3DModels");
        spacer3D = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layout3DModels->addItem(spacer3D);

        scrollArea3D->setWidget(scrollAreaContents3D);

        verticalLayout_5->addWidget(scrollArea3D);

        stackedLocalSections->addWidget(page_3d);
        page_nr = new QWidget();
        page_nr->setObjectName("page_nr");
        verticalLayout_6 = new QVBoxLayout(page_nr);
        verticalLayout_6->setObjectName("verticalLayout_6");
        scrollArea_3 = new QScrollArea(page_nr);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 585, 735));
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy1);
        verticalLayout_7 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        grpNrType = new QGroupBox(scrollAreaWidgetContents_3);
        grpNrType->setObjectName("grpNrType");
        formNrType = new QFormLayout(grpNrType);
        formNrType->setObjectName("formNrType");
        label_26 = new QLabel(grpNrType);
        label_26->setObjectName("label_26");

        formNrType->setWidget(0, QFormLayout::ItemRole::LabelRole, label_26);

        comboBoxNrType = new QComboBox(grpNrType);
        comboBoxNrType->addItem(QString());
        comboBoxNrType->addItem(QString());
        comboBoxNrType->addItem(QString());
        comboBoxNrType->addItem(QString());
        comboBoxNrType->setObjectName("comboBoxNrType");

        formNrType->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBoxNrType);

        checkBoxNrInplane = new QCheckBox(grpNrType);
        checkBoxNrInplane->setObjectName("checkBoxNrInplane");

        formNrType->setWidget(1, QFormLayout::ItemRole::FieldRole, checkBoxNrInplane);


        verticalLayout_7->addWidget(grpNrType);

        grpConstant = new QGroupBox(scrollAreaWidgetContents_3);
        grpConstant->setObjectName("grpConstant");
        formConstant = new QFormLayout(grpConstant);
        formConstant->setObjectName("formConstant");
        label_27 = new QLabel(grpConstant);
        label_27->setObjectName("label_27");

        formConstant->setWidget(0, QFormLayout::ItemRole::LabelRole, label_27);

        lineConstNr = new QLineEdit(grpConstant);
        lineConstNr->setObjectName("lineConstNr");

        formConstant->setWidget(0, QFormLayout::ItemRole::FieldRole, lineConstNr);


        verticalLayout_7->addWidget(grpConstant);

        grpAnalytical = new QGroupBox(scrollAreaWidgetContents_3);
        grpAnalytical->setObjectName("grpAnalytical");
        formAnalytical = new QFormLayout(grpAnalytical);
        formAnalytical->setObjectName("formAnalytical");
        label_29 = new QLabel(grpAnalytical);
        label_29->setObjectName("label_29");

        formAnalytical->setWidget(0, QFormLayout::ItemRole::LabelRole, label_29);

        lineEditCodeID = new QLineEdit(grpAnalytical);
        lineEditCodeID->setObjectName("lineEditCodeID");

        formAnalytical->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEditCodeID);

        label_21 = new QLabel(grpAnalytical);
        label_21->setObjectName("label_21");

        formAnalytical->setWidget(1, QFormLayout::ItemRole::LabelRole, label_21);

        labelCodeID = new QLabel(grpAnalytical);
        labelCodeID->setObjectName("labelCodeID");

        formAnalytical->setWidget(1, QFormLayout::ItemRole::FieldRole, labelCodeID);

        label_30 = new QLabel(grpAnalytical);
        label_30->setObjectName("label_30");

        formAnalytical->setWidget(2, QFormLayout::ItemRole::LabelRole, label_30);

        lineNrControlDepths = new QLineEdit(grpAnalytical);
        lineNrControlDepths->setObjectName("lineNrControlDepths");

        formAnalytical->setWidget(2, QFormLayout::ItemRole::FieldRole, lineNrControlDepths);

        label_31 = new QLabel(grpAnalytical);
        label_31->setObjectName("label_31");

        formAnalytical->setWidget(3, QFormLayout::ItemRole::LabelRole, label_31);

        lineNrAtControlDepths = new QLineEdit(grpAnalytical);
        lineNrAtControlDepths->setObjectName("lineNrAtControlDepths");

        formAnalytical->setWidget(3, QFormLayout::ItemRole::FieldRole, lineNrAtControlDepths);

        label_32 = new QLabel(grpAnalytical);
        label_32->setObjectName("label_32");

        formAnalytical->setWidget(4, QFormLayout::ItemRole::LabelRole, label_32);

        udpWidget = new UDPFieldsWidget(grpAnalytical);
        udpWidget->setObjectName("udpWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(udpWidget->sizePolicy().hasHeightForWidth());
        udpWidget->setSizePolicy(sizePolicy2);

        formAnalytical->setWidget(4, QFormLayout::ItemRole::FieldRole, udpWidget);


        verticalLayout_7->addWidget(grpAnalytical);

        grpPointwise = new QGroupBox(scrollAreaWidgetContents_3);
        grpPointwise->setObjectName("grpPointwise");
        formPointwise = new QFormLayout(grpPointwise);
        formPointwise->setObjectName("formPointwise");
        label_34 = new QLabel(grpPointwise);
        label_34->setObjectName("label_34");

        formPointwise->setWidget(0, QFormLayout::ItemRole::LabelRole, label_34);

        btnBrowsePointwise = new QPushButton(grpPointwise);
        btnBrowsePointwise->setObjectName("btnBrowsePointwise");

        formPointwise->setWidget(0, QFormLayout::ItemRole::FieldRole, btnBrowsePointwise);

        label_33 = new QLabel(grpPointwise);
        label_33->setObjectName("label_33");

        formPointwise->setWidget(1, QFormLayout::ItemRole::LabelRole, label_33);

        linePointwisePath = new QLineEdit(grpPointwise);
        linePointwisePath->setObjectName("linePointwisePath");

        formPointwise->setWidget(1, QFormLayout::ItemRole::FieldRole, linePointwisePath);

        label_37 = new QLabel(grpPointwise);
        label_37->setObjectName("label_37");

        formPointwise->setWidget(2, QFormLayout::ItemRole::LabelRole, label_37);

        lineNrFactor = new QLineEdit(grpPointwise);
        lineNrFactor->setObjectName("lineNrFactor");

        formPointwise->setWidget(2, QFormLayout::ItemRole::FieldRole, lineNrFactor);


        verticalLayout_7->addWidget(grpPointwise);

        grpStructured = new QGroupBox(scrollAreaWidgetContents_3);
        grpStructured->setObjectName("grpStructured");
        formStructured = new QFormLayout(grpStructured);
        formStructured->setObjectName("formStructured");
        label_39 = new QLabel(grpStructured);
        label_39->setObjectName("label_39");

        formStructured->setWidget(0, QFormLayout::ItemRole::LabelRole, label_39);

        pushBrowseStructured = new QPushButton(grpStructured);
        pushBrowseStructured->setObjectName("pushBrowseStructured");

        formStructured->setWidget(0, QFormLayout::ItemRole::FieldRole, pushBrowseStructured);

        label_38 = new QLabel(grpStructured);
        label_38->setObjectName("label_38");

        formStructured->setWidget(1, QFormLayout::ItemRole::LabelRole, label_38);

        lineStructuredPath = new QLineEdit(grpStructured);
        lineStructuredPath->setObjectName("lineStructuredPath");

        formStructured->setWidget(1, QFormLayout::ItemRole::FieldRole, lineStructuredPath);

        label_40 = new QLabel(grpStructured);
        label_40->setObjectName("label_40");

        formStructured->setWidget(2, QFormLayout::ItemRole::LabelRole, label_40);

        lineStructuredOutOfRange = new QLineEdit(grpStructured);
        lineStructuredOutOfRange->setObjectName("lineStructuredOutOfRange");

        formStructured->setWidget(2, QFormLayout::ItemRole::FieldRole, lineStructuredOutOfRange);


        verticalLayout_7->addWidget(grpStructured);

        grpWavefieldScanning = new QGroupBox(scrollAreaWidgetContents_3);
        grpWavefieldScanning->setObjectName("grpWavefieldScanning");
        formWavefieldScanning = new QFormLayout(grpWavefieldScanning);
        formWavefieldScanning->setObjectName("formWavefieldScanning");
        checkWavefieldScanningOn = new QCheckBox(grpWavefieldScanning);
        checkWavefieldScanningOn->setObjectName("checkWavefieldScanningOn");

        formWavefieldScanning->setWidget(0, QFormLayout::ItemRole::FieldRole, checkWavefieldScanningOn);

        label_43 = new QLabel(grpWavefieldScanning);
        label_43->setObjectName("label_43");

        formWavefieldScanning->setWidget(1, QFormLayout::ItemRole::LabelRole, label_43);

        lineWavefieldOutputFile = new QLineEdit(grpWavefieldScanning);
        lineWavefieldOutputFile->setObjectName("lineWavefieldOutputFile");

        formWavefieldScanning->setWidget(1, QFormLayout::ItemRole::FieldRole, lineWavefieldOutputFile);

        label_44 = new QLabel(grpWavefieldScanning);
        label_44->setObjectName("label_44");

        formWavefieldScanning->setWidget(2, QFormLayout::ItemRole::LabelRole, label_44);

        lineThresholdFourierConv = new QLineEdit(grpWavefieldScanning);
        lineThresholdFourierConv->setObjectName("lineThresholdFourierConv");

        formWavefieldScanning->setWidget(2, QFormLayout::ItemRole::FieldRole, lineThresholdFourierConv);

        label_45 = new QLabel(grpWavefieldScanning);
        label_45->setObjectName("label_45");

        formWavefieldScanning->setWidget(3, QFormLayout::ItemRole::LabelRole, label_45);

        lineRelativeAmpSkip = new QLineEdit(grpWavefieldScanning);
        lineRelativeAmpSkip->setObjectName("lineRelativeAmpSkip");

        formWavefieldScanning->setWidget(3, QFormLayout::ItemRole::FieldRole, lineRelativeAmpSkip);

        label_47 = new QLabel(grpWavefieldScanning);
        label_47->setObjectName("label_47");

        formWavefieldScanning->setWidget(4, QFormLayout::ItemRole::LabelRole, label_47);

        lineAbsAmpSkip = new QLineEdit(grpWavefieldScanning);
        lineAbsAmpSkip->setObjectName("lineAbsAmpSkip");

        formWavefieldScanning->setWidget(4, QFormLayout::ItemRole::FieldRole, lineAbsAmpSkip);

        label_48 = new QLabel(grpWavefieldScanning);
        label_48->setObjectName("label_48");

        formWavefieldScanning->setWidget(5, QFormLayout::ItemRole::LabelRole, label_48);

        lineMaxNumPeaks = new QLineEdit(grpWavefieldScanning);
        lineMaxNumPeaks->setObjectName("lineMaxNumPeaks");

        formWavefieldScanning->setWidget(5, QFormLayout::ItemRole::FieldRole, lineMaxNumPeaks);

        checkScanOnlyVertexGLL = new QCheckBox(grpWavefieldScanning);
        checkScanOnlyVertexGLL->setObjectName("checkScanOnlyVertexGLL");

        formWavefieldScanning->setWidget(6, QFormLayout::ItemRole::FieldRole, checkScanOnlyVertexGLL);

        label_49 = new QLabel(grpWavefieldScanning);
        label_49->setObjectName("label_49");

        formWavefieldScanning->setWidget(7, QFormLayout::ItemRole::LabelRole, label_49);

        lineNumStepsPerMeshPeriod = new QLineEdit(grpWavefieldScanning);
        lineNumStepsPerMeshPeriod->setObjectName("lineNumStepsPerMeshPeriod");

        formWavefieldScanning->setWidget(7, QFormLayout::ItemRole::FieldRole, lineNumStepsPerMeshPeriod);


        verticalLayout_7->addWidget(grpWavefieldScanning);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_6->addWidget(scrollArea_3);

        stackedLocalSections->addWidget(page_nr);
        page_source = new QWidget();
        page_source->setObjectName("page_source");
        verticalLayout_source = new QVBoxLayout(page_source);
        verticalLayout_source->setObjectName("verticalLayout_source");
        grpTimeAxis = new QGroupBox(page_source);
        grpTimeAxis->setObjectName("grpTimeAxis");
        formTimeAxis = new QFormLayout(grpTimeAxis);
        formTimeAxis->setObjectName("formTimeAxis");
        lblRecordLength = new QLabel(grpTimeAxis);
        lblRecordLength->setObjectName("lblRecordLength");

        formTimeAxis->setWidget(0, QFormLayout::ItemRole::LabelRole, lblRecordLength);

        lineRecordLength = new QLineEdit(grpTimeAxis);
        lineRecordLength->setObjectName("lineRecordLength");

        formTimeAxis->setWidget(0, QFormLayout::ItemRole::FieldRole, lineRecordLength);

        lblEnforcedDt = new QLabel(grpTimeAxis);
        lblEnforcedDt->setObjectName("lblEnforcedDt");

        formTimeAxis->setWidget(1, QFormLayout::ItemRole::LabelRole, lblEnforcedDt);

        lineEnforcedDt = new QLineEdit(grpTimeAxis);
        lineEnforcedDt->setObjectName("lineEnforcedDt");

        formTimeAxis->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEnforcedDt);

        lblCourant = new QLabel(grpTimeAxis);
        lblCourant->setObjectName("lblCourant");

        formTimeAxis->setWidget(2, QFormLayout::ItemRole::LabelRole, lblCourant);

        lineCourantNumber = new QLineEdit(grpTimeAxis);
        lineCourantNumber->setObjectName("lineCourantNumber");

        formTimeAxis->setWidget(2, QFormLayout::ItemRole::FieldRole, lineCourantNumber);

        lblIntegrator = new QLabel(grpTimeAxis);
        lblIntegrator->setObjectName("lblIntegrator");

        formTimeAxis->setWidget(3, QFormLayout::ItemRole::LabelRole, lblIntegrator);

        comboIntegrator = new QComboBox(grpTimeAxis);
        comboIntegrator->addItem(QString());
        comboIntegrator->addItem(QString());
        comboIntegrator->setObjectName("comboIntegrator");

        formTimeAxis->setWidget(3, QFormLayout::ItemRole::FieldRole, comboIntegrator);


        verticalLayout_source->addWidget(grpTimeAxis);

        layoutSourceCount = new QHBoxLayout();
        layoutSourceCount->setObjectName("layoutSourceCount");
        labelSourceCount = new QLabel(page_source);
        labelSourceCount->setObjectName("labelSourceCount");

        layoutSourceCount->addWidget(labelSourceCount);

        spinSourceCount = new QSpinBox(page_source);
        spinSourceCount->setObjectName("spinSourceCount");
        spinSourceCount->setMinimum(0);
        spinSourceCount->setMaximum(20);
        spinSourceCount->setValue(1);

        layoutSourceCount->addWidget(spinSourceCount);


        verticalLayout_source->addLayout(layoutSourceCount);

        scrollAreaSource = new QScrollArea(page_source);
        scrollAreaSource->setObjectName("scrollAreaSource");
        scrollAreaSource->setWidgetResizable(true);
        scrollAreaContentsSource = new QWidget();
        scrollAreaContentsSource->setObjectName("scrollAreaContentsSource");
        scrollAreaContentsSource->setGeometry(QRect(0, 0, 76, 16));
        layoutSources = new QVBoxLayout(scrollAreaContentsSource);
        layoutSources->setObjectName("layoutSources");
        spacerSources = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layoutSources->addItem(spacerSources);

        scrollAreaSource->setWidget(scrollAreaContentsSource);

        verticalLayout_source->addWidget(scrollAreaSource);

        stackedLocalSections->addWidget(page_source);
        page_output = new QWidget();
        page_output->setObjectName("page_output");
        verticalLayout_output = new QVBoxLayout(page_output);
        verticalLayout_output->setObjectName("verticalLayout_output");
        labelOutputTitle = new QLabel(page_output);
        labelOutputTitle->setObjectName("labelOutputTitle");
        labelOutputTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelOutputTitle->setWordWrap(true);

        verticalLayout_output->addWidget(labelOutputTitle);

        layoutOutputCount = new QHBoxLayout();
        layoutOutputCount->setObjectName("layoutOutputCount");
        labelOutputCount = new QLabel(page_output);
        labelOutputCount->setObjectName("labelOutputCount");

        layoutOutputCount->addWidget(labelOutputCount);

        spinStationGroupCount = new QSpinBox(page_output);
        spinStationGroupCount->setObjectName("spinStationGroupCount");
        spinStationGroupCount->setMinimum(0);
        spinStationGroupCount->setMaximum(10);
        spinStationGroupCount->setValue(1);

        layoutOutputCount->addWidget(spinStationGroupCount);


        verticalLayout_output->addLayout(layoutOutputCount);

        scrollAreaOutput = new QScrollArea(page_output);
        scrollAreaOutput->setObjectName("scrollAreaOutput");
        scrollAreaOutput->setWidgetResizable(true);
        scrollAreaContentsOutput = new QWidget();
        scrollAreaContentsOutput->setObjectName("scrollAreaContentsOutput");
        scrollAreaContentsOutput->setGeometry(QRect(0, 0, 76, 16));
        layoutOutputGroups = new QVBoxLayout(scrollAreaContentsOutput);
        layoutOutputGroups->setObjectName("layoutOutputGroups");
        spacerOutput = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        layoutOutputGroups->addItem(spacerOutput);

        scrollAreaOutput->setWidget(scrollAreaContentsOutput);

        verticalLayout_output->addWidget(scrollAreaOutput);

        labelElementWise = new QLabel(page_output);
        labelElementWise->setObjectName("labelElementWise");
        labelElementWise->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_output->addWidget(labelElementWise);

        stackedLocalSections->addWidget(page_output);

        gridLayout_2->addWidget(stackedLocalSections, 4, 0, 1, 7);

        btnNr = new QPushButton(page_local);
        btnNr->setObjectName("btnNr");
        btnNr->setMinimumSize(QSize(0, 20));

        gridLayout_2->addWidget(btnNr, 3, 3, 1, 1);

        btnRun = new QPushButton(page_local);
        btnRun->setObjectName("btnRun");
        btnRun->setMinimumSize(QSize(0, 35));
        btnRun->setAutoFillBackground(false);

        gridLayout_2->addWidget(btnRun, 3, 6, 1, 1);

        label = new QLabel(page_local);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        lineMeshPath = new QLineEdit(page_local);
        lineMeshPath->setObjectName("lineMeshPath");

        gridLayout_2->addWidget(lineMeshPath, 2, 0, 1, 2);

        label_2 = new QLabel(page_local);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 5, 1, 2);

        btnSource = new QPushButton(page_local);
        btnSource->setObjectName("btnSource");
        btnSource->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(btnSource, 3, 5, 1, 1);

        btnBackL = new QPushButton(page_local);
        btnBackL->setObjectName("btnBackL");

        gridLayout_2->addWidget(btnBackL, 5, 3, 1, 1);

        stackedWidget->addWidget(page_local);
        page_run = new QWidget();
        page_run->setObjectName("page_run");
        verticalLayout_run = new QVBoxLayout(page_run);
        verticalLayout_run->setObjectName("verticalLayout_run");
        grpExePath = new QGroupBox(page_run);
        grpExePath->setObjectName("grpExePath");
        formExePath = new QFormLayout(grpExePath);
        formExePath->setObjectName("formExePath");
        btnBrowseExe = new QPushButton(grpExePath);
        btnBrowseExe->setObjectName("btnBrowseExe");

        formExePath->setWidget(0, QFormLayout::ItemRole::LabelRole, btnBrowseExe);

        lineExePath = new QLineEdit(grpExePath);
        lineExePath->setObjectName("lineExePath");
        lineExePath->setReadOnly(true);

        formExePath->setWidget(0, QFormLayout::ItemRole::FieldRole, lineExePath);

        lblMpiProcs = new QLabel(grpExePath);
        lblMpiProcs->setObjectName("lblMpiProcs");

        formExePath->setWidget(1, QFormLayout::ItemRole::LabelRole, lblMpiProcs);

        spinMpiProcs = new QSpinBox(grpExePath);
        spinMpiProcs->setObjectName("spinMpiProcs");
        spinMpiProcs->setMinimum(1);
        spinMpiProcs->setMaximum(1024);
        spinMpiProcs->setValue(4);

        formExePath->setWidget(1, QFormLayout::ItemRole::FieldRole, spinMpiProcs);


        verticalLayout_run->addWidget(grpExePath);

        grpBatchJob = new QGroupBox(page_run);
        grpBatchJob->setObjectName("grpBatchJob");
        layoutBatchJob = new QVBoxLayout(grpBatchJob);
        layoutBatchJob->setObjectName("layoutBatchJob");
        checkBatchJob = new QCheckBox(grpBatchJob);
        checkBatchJob->setObjectName("checkBatchJob");

        layoutBatchJob->addWidget(checkBatchJob);

        layoutBatchFilename = new QHBoxLayout();
        layoutBatchFilename->setObjectName("layoutBatchFilename");
        lblBatchFilename = new QLabel(grpBatchJob);
        lblBatchFilename->setObjectName("lblBatchFilename");

        layoutBatchFilename->addWidget(lblBatchFilename);

        lineBatchFilename = new QLineEdit(grpBatchJob);
        lineBatchFilename->setObjectName("lineBatchFilename");

        layoutBatchFilename->addWidget(lineBatchFilename);


        layoutBatchJob->addLayout(layoutBatchFilename);

        editBatchScript = new QPlainTextEdit(grpBatchJob);
        editBatchScript->setObjectName("editBatchScript");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Courier New")});
        font1.setPointSize(10);
        editBatchScript->setFont(font1);

        layoutBatchJob->addWidget(editBatchScript);


        verticalLayout_run->addWidget(grpBatchJob);

        layoutRunButtons = new QHBoxLayout();
        layoutRunButtons->setObjectName("layoutRunButtons");
        btnRunSim = new QPushButton(page_run);
        btnRunSim->setObjectName("btnRunSim");
        btnRunSim->setMinimumSize(QSize(0, 35));

        layoutRunButtons->addWidget(btnRunSim);

        btnStopSim = new QPushButton(page_run);
        btnStopSim->setObjectName("btnStopSim");
        btnStopSim->setEnabled(false);
        btnStopSim->setMinimumSize(QSize(0, 35));

        layoutRunButtons->addWidget(btnStopSim);

        btnBackRun = new QPushButton(page_run);
        btnBackRun->setObjectName("btnBackRun");
        btnBackRun->setMinimumSize(QSize(0, 35));

        layoutRunButtons->addWidget(btnBackRun);


        verticalLayout_run->addLayout(layoutRunButtons);

        grpRunLog = new QGroupBox(page_run);
        grpRunLog->setObjectName("grpRunLog");
        layoutRunLog = new QVBoxLayout(grpRunLog);
        layoutRunLog->setObjectName("layoutRunLog");
        editRunLog = new QPlainTextEdit(grpRunLog);
        editRunLog->setObjectName("editRunLog");
        editRunLog->setReadOnly(true);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Courier New")});
        font2.setPointSize(9);
        editRunLog->setFont(font2);

        layoutRunLog->addWidget(editRunLog);


        verticalLayout_run->addWidget(grpRunLog);

        stackedWidget->addWidget(page_run);
        page_remote = new QWidget();
        page_remote->setObjectName("page_remote");
        verticalLayout_remote = new QVBoxLayout(page_remote);
        verticalLayout_remote->setObjectName("verticalLayout_remote");
        spacerRemoteTop = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_remote->addItem(spacerRemoteTop);

        labelSSHTitle = new QLabel(page_remote);
        labelSSHTitle->setObjectName("labelSSHTitle");
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        labelSSHTitle->setFont(font3);
        labelSSHTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_remote->addWidget(labelSSHTitle);

        formSSH = new QFormLayout();
        formSSH->setObjectName("formSSH");
        labelHost = new QLabel(page_remote);
        labelHost->setObjectName("labelHost");

        formSSH->setWidget(0, QFormLayout::ItemRole::LabelRole, labelHost);

        lineSSHHost = new QLineEdit(page_remote);
        lineSSHHost->setObjectName("lineSSHHost");

        formSSH->setWidget(0, QFormLayout::ItemRole::FieldRole, lineSSHHost);

        labelPort = new QLabel(page_remote);
        labelPort->setObjectName("labelPort");

        formSSH->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPort);

        lineSSHPort = new QLineEdit(page_remote);
        lineSSHPort->setObjectName("lineSSHPort");

        formSSH->setWidget(1, QFormLayout::ItemRole::FieldRole, lineSSHPort);

        labelUsername = new QLabel(page_remote);
        labelUsername->setObjectName("labelUsername");

        formSSH->setWidget(2, QFormLayout::ItemRole::LabelRole, labelUsername);

        lineSSHUser = new QLineEdit(page_remote);
        lineSSHUser->setObjectName("lineSSHUser");

        formSSH->setWidget(2, QFormLayout::ItemRole::FieldRole, lineSSHUser);

        labelPassword = new QLabel(page_remote);
        labelPassword->setObjectName("labelPassword");

        formSSH->setWidget(3, QFormLayout::ItemRole::LabelRole, labelPassword);

        lineSSHPass = new QLineEdit(page_remote);
        lineSSHPass->setObjectName("lineSSHPass");
        lineSSHPass->setEchoMode(QLineEdit::EchoMode::Password);

        formSSH->setWidget(3, QFormLayout::ItemRole::FieldRole, lineSSHPass);


        verticalLayout_remote->addLayout(formSSH);

        labelSSHStatus = new QLabel(page_remote);
        labelSSHStatus->setObjectName("labelSSHStatus");
        labelSSHStatus->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelSSHStatus->setWordWrap(true);

        verticalLayout_remote->addWidget(labelSSHStatus);

        layoutSSHButtons = new QHBoxLayout();
        layoutSSHButtons->setObjectName("layoutSSHButtons");
        btnBackR = new QPushButton(page_remote);
        btnBackR->setObjectName("btnBackR");

        layoutSSHButtons->addWidget(btnBackR);

        btnSSHConnect = new QPushButton(page_remote);
        btnSSHConnect->setObjectName("btnSSHConnect");

        layoutSSHButtons->addWidget(btnSSHConnect);


        verticalLayout_remote->addLayout(layoutSSHButtons);

        spacerRemoteBottom = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_remote->addItem(spacerRemoteBottom);

        stackedWidget->addWidget(page_remote);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 633, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        stackedLocalSections->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelMain->setText(QCoreApplication::translate("MainWindow", "AxiSEM3D", nullptr));
        btnLocal->setText(QCoreApplication::translate("MainWindow", "Run Local", nullptr));
        btnRemote->setText(QCoreApplication::translate("MainWindow", "Run Remote", nullptr));
        btnModel3D->setText(QCoreApplication::translate("MainWindow", "3D Models", nullptr));
        btnOutput->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        btnAdvanced->setText(QCoreApplication::translate("MainWindow", "Advanced", nullptr));
        btnModel->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        btnBrowseMesh->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        btnBrowseStations->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        grpVerbose->setTitle(QCoreApplication::translate("MainWindow", "Verbose", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Channel:", nullptr));
        comboVerboseChannel->setItemText(0, QCoreApplication::translate("MainWindow", "STDOUT", nullptr));
        comboVerboseChannel->setItemText(1, QCoreApplication::translate("MainWindow", "File", nullptr));

        btnBrowseVerboseChannel->setText(QCoreApplication::translate("MainWindow", "Browse If File", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Level:", nullptr));
        comboVerboseLevel->setItemText(0, QCoreApplication::translate("MainWindow", "NONE", nullptr));
        comboVerboseLevel->setItemText(1, QCoreApplication::translate("MainWindow", "ESSENTIAL", nullptr));
        comboVerboseLevel->setItemText(2, QCoreApplication::translate("MainWindow", "DETAILED", nullptr));

        checkVerboseWarnings->setText(QCoreApplication::translate("MainWindow", "Enable Warnings", nullptr));
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QCoreApplication::translate("MainWindow", "Time step interval to display time loop info", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("MainWindow", "Loop Info Interval:", nullptr));
        lineLoopInterval->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
#if QT_CONFIG(tooltip)
        label_8->setToolTip(QCoreApplication::translate("MainWindow", "Time step interval for stability check", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("MainWindow", "Stability Interval:", nullptr));
        lineStabilityInterval->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        grpMPI->setTitle(QCoreApplication::translate("MainWindow", "MPI", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Processors Per Group:", nullptr));
        lineNumProcessorsPerGroup->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Load Balancing Weight:", nullptr));
        loadBalancingBox->setItemText(0, QCoreApplication::translate("MainWindow", "ELEMENT", nullptr));
        loadBalancingBox->setItemText(1, QCoreApplication::translate("MainWindow", "ELEMENT_POINT", nullptr));

        checkBoxPlotDomainDecomp->setText(QCoreApplication::translate("MainWindow", "Plot Domain Decomposition", nullptr));
        grpDevelop->setTitle(QCoreApplication::translate("MainWindow", "Develop", nullptr));
        checkBoxDiagnosePreloop->setText(QCoreApplication::translate("MainWindow", "Diagnose Preloop", nullptr));
#if QT_CONFIG(tooltip)
        label_12->setToolTip(QCoreApplication::translate("MainWindow", "Max Number of Time Steps (use 0 to free this limit)", nullptr));
#endif // QT_CONFIG(tooltip)
        label_12->setText(QCoreApplication::translate("MainWindow", "Max Time Steps:", nullptr));
        lineMaxNumTimeSteps->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
#if QT_CONFIG(tooltip)
        label_13->setToolTip(QCoreApplication::translate("MainWindow", "Time Limit For FFTW Planning", nullptr));
#endif // QT_CONFIG(tooltip)
        label_13->setText(QCoreApplication::translate("MainWindow", "FFTW Time Limit:", nullptr));
        lineTimeLimitFFTW->setText(QCoreApplication::translate("MainWindow", "60", nullptr));
        checkBoxFFTWLuckyNum->setText(QCoreApplication::translate("MainWindow", "FFTW Lucky Numbers", nullptr));
        grpGeodesy->setTitle(QCoreApplication::translate("MainWindow", "Geodesy", nullptr));
#if QT_CONFIG(tooltip)
        label_15->setToolTip(QCoreApplication::translate("MainWindow", "The latitude and longitude of the north pole of the computational coordinate system. Use SOURCE to let it be determined by the first source in list_of_sources.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_15->setText(QCoreApplication::translate("MainWindow", "Lat/Long of North Pole:", nullptr));
        comboBoxLatLongNP->setItemText(0, QCoreApplication::translate("MainWindow", "Array (Type Under)", nullptr));
        comboBoxLatLongNP->setItemText(1, QCoreApplication::translate("MainWindow", "SOURCE (determined by the FIRST source presented in list_of_sources in Source)", nullptr));

#if QT_CONFIG(tooltip)
        label_14->setToolTip(QCoreApplication::translate("MainWindow", "Custom north-pole coordinates as [latitude, longitude] array when using Array mode.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_14->setText(QCoreApplication::translate("MainWindow", "Custom [lat, lon]:", nullptr));
        lineEditNP->setText(QCoreApplication::translate("MainWindow", "[90., 0.]", nullptr));
#if QT_CONFIG(tooltip)
        label_16->setToolTip(QCoreApplication::translate("MainWindow", "Flattening of the ellipsoid surface. Choose a preset or enter a custom number.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_16->setText(QCoreApplication::translate("MainWindow", "Flattening on Surface:", nullptr));
        comboBoxFlatteningSurface->setItemText(0, QCoreApplication::translate("MainWindow", "Custom Number", nullptr));
        comboBoxFlatteningSurface->setItemText(1, QCoreApplication::translate("MainWindow", "SPHERE", nullptr));
        comboBoxFlatteningSurface->setItemText(2, QCoreApplication::translate("MainWindow", "WGS84", nullptr));
        comboBoxFlatteningSurface->setItemText(3, QCoreApplication::translate("MainWindow", "GRS80", nullptr));
        comboBoxFlatteningSurface->setItemText(4, QCoreApplication::translate("MainWindow", "SPECFEM3D_GLOBE", nullptr));

#if QT_CONFIG(tooltip)
        label_17->setToolTip(QCoreApplication::translate("MainWindow", "Custom numeric flattening value when using Custom Number mode.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_17->setText(QCoreApplication::translate("MainWindow", "Custom Flattening:", nullptr));
        lineFlatteningCustomNum->setText(QCoreApplication::translate("MainWindow", "0.0033", nullptr));
        grpAbsorbingBoundaries->setTitle(QCoreApplication::translate("MainWindow", "Absorbing Boundaries", nullptr));
#if QT_CONFIG(tooltip)
        label_18->setToolTip(QCoreApplication::translate("MainWindow", "A subset of [RIGHT, BOTTOM, TOP]. The mesh has four outer boundaries: left (axial), right, bottom and top (surface). Right, bottom and top can be absorbing. Use [] to disable (stress-free). Most common: [RIGHT, BOTTOM].", nullptr));
#endif // QT_CONFIG(tooltip)
        label_18->setText(QCoreApplication::translate("MainWindow", "Boundaries:", nullptr));
        lineBoundaries->setText(QCoreApplication::translate("MainWindow", "[RIGHT, BOTTOM]", nullptr));
        checkBoxClayton->setText(QCoreApplication::translate("MainWindow", "Enable Clayton Enquist", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Kosloff & Kosloff:", nullptr));
        checkBoxKosloff->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
#if QT_CONFIG(tooltip)
        label_20->setToolTip(QCoreApplication::translate("MainWindow", "Must match the order of absorbing_boundaries. The mesh should be slightly larger than the computational domain. Allowed range: 0.01\342\200\2230.25. E.g., 0.05 on a 110 km mesh gives a 5.5 km sponge layer.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_20->setText(QCoreApplication::translate("MainWindow", "Relative Spans:", nullptr));
        lineRelativeSpans->setText(QCoreApplication::translate("MainWindow", "[.05, .05]", nullptr));
#if QT_CONFIG(tooltip)
        label_22->setToolTip(QCoreApplication::translate("MainWindow", "\316\263-factor for absorbing strength (solid). Arguments: VP, VS (wave velocities), RHO (density), SPAN (sponge layer span), T0 (mesh period). Multiplied by a pattern function decreasing from 1 at the mesh boundary to 0 at the inner edge. Default from Haindl et al., 2020.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_22->setText(QCoreApplication::translate("MainWindow", "Gamma Expr Solid:", nullptr));
#if QT_CONFIG(tooltip)
        label_23->setToolTip(QCoreApplication::translate("MainWindow", "Same as gamma_expr_solid but without VS dependency (fluid has no shear wave).", nullptr));
#endif // QT_CONFIG(tooltip)
        label_23->setText(QCoreApplication::translate("MainWindow", "Gamma Expr Fluid:", nullptr));
        grpAttenuation->setTitle(QCoreApplication::translate("MainWindow", "Attenuation", nullptr));
#if QT_CONFIG(tooltip)
        label_24->setToolTip(QCoreApplication::translate("MainWindow", "Attenuation mode. NONE disables attenuation, FULL uses full attenuation, CG4 uses coarse-grained attenuation on 4 GLL points.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_24->setText(QCoreApplication::translate("MainWindow", "Mode:", nullptr));
        attenuationBox->setItemText(0, QCoreApplication::translate("MainWindow", "NONE", nullptr));
        attenuationBox->setItemText(1, QCoreApplication::translate("MainWindow", "FULL", nullptr));
        attenuationBox->setItemText(2, QCoreApplication::translate("MainWindow", "CG4", nullptr));

        label_25->setText(QCoreApplication::translate("MainWindow", "Even if using a 1D model, at least one model is needed.\n"
"\n"
"Select the amount of 3D models needed for your project.\n"
"", nullptr));
        grpNrType->setTitle(QCoreApplication::translate("MainWindow", "Nr Type", nullptr));
#if QT_CONFIG(tooltip)
        label_26->setToolTip(QCoreApplication::translate("MainWindow", "CONSTANT: Nr(s,z) = const. ANALYTICAL: analytical Nr(s,z) defined in NrFieldAnalytical.cpp. POINTWISE: Nr at discrete control points. STRUCTURED: Nr on a structured grid.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_26->setText(QCoreApplication::translate("MainWindow", "Type:", nullptr));
        comboBoxNrType->setItemText(0, QCoreApplication::translate("MainWindow", "CONSTANT", nullptr));
        comboBoxNrType->setItemText(1, QCoreApplication::translate("MainWindow", "ANALYTICAL", nullptr));
        comboBoxNrType->setItemText(2, QCoreApplication::translate("MainWindow", "POINTWISE", nullptr));
        comboBoxNrType->setItemText(3, QCoreApplication::translate("MainWindow", "STRUCTURED", nullptr));

        checkBoxNrInplane->setText(QCoreApplication::translate("MainWindow", "Bound Nr By Inplane", nullptr));
        grpConstant->setTitle(QCoreApplication::translate("MainWindow", "Constant", nullptr));
#if QT_CONFIG(tooltip)
        label_27->setToolTip(QCoreApplication::translate("MainWindow", "Constant value for Nr. For an axisymmetric model with a single axial source, use 5 for moment tensor (earthquake), 3 for force vector (impact), 1 for pressure (explosion).", nullptr));
#endif // QT_CONFIG(tooltip)
        label_27->setText(QCoreApplication::translate("MainWindow", "Value:", nullptr));
        lineConstNr->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        grpAnalytical->setTitle(QCoreApplication::translate("MainWindow", "Analytical", nullptr));
#if QT_CONFIG(tooltip)
        label_29->setToolTip(QCoreApplication::translate("MainWindow", "NrFieldAnalytical::sCodeID in NrFieldAnalytical.cpp (line 18).", nullptr));
#endif // QT_CONFIG(tooltip)
        label_29->setText(QCoreApplication::translate("MainWindow", "Code ID:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Preview:", nullptr));
        labelCodeID->setText(QCoreApplication::translate("MainWindow", "hold", nullptr));
#if QT_CONFIG(tooltip)
        label_30->setToolTip(QCoreApplication::translate("MainWindow", "Depth values at which Nr is controlled for the analytical field.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_30->setText(QCoreApplication::translate("MainWindow", "Control Depths:", nullptr));
#if QT_CONFIG(tooltip)
        label_31->setToolTip(QCoreApplication::translate("MainWindow", "Nr values corresponding to each control depth.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_31->setText(QCoreApplication::translate("MainWindow", "Nr at Control Depths:", nullptr));
#if QT_CONFIG(tooltip)
        label_32->setToolTip(QCoreApplication::translate("MainWindow", "Arbitrary parameters with arbitrary names and types, depending on how they are read and used in NrFieldAnalytical.cpp.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_32->setText(QCoreApplication::translate("MainWindow", "User-Defined Params:", nullptr));
        grpPointwise->setTitle(QCoreApplication::translate("MainWindow", "Pointwise", nullptr));
#if QT_CONFIG(tooltip)
        label_34->setToolTip(QCoreApplication::translate("MainWindow", "Must contain: pointwise_sz (double, X\303\2272, s/z of control points) and pointwise_Nr (int, X, Nr values). Unit: meters. Interpolation uses inverse distance weighting.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_34->setText(QCoreApplication::translate("MainWindow", "NC Data File:", nullptr));
        btnBrowsePointwise->setText(QCoreApplication::translate("MainWindow", "Browse...", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "File Path:", nullptr));
#if QT_CONFIG(tooltip)
        label_37->setToolTip(QCoreApplication::translate("MainWindow", "Factor multiplied to Nr(s,z) from the pointwise data file.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_37->setText(QCoreApplication::translate("MainWindow", "Factor:", nullptr));
        grpStructured->setTitle(QCoreApplication::translate("MainWindow", "Structured", nullptr));
#if QT_CONFIG(tooltip)
        label_39->setToolTip(QCoreApplication::translate("MainWindow", "Cartesian mesh: structured_s (double, M), structured_z (double, N), structured_Nr (int, M\303\227N). Spherical mesh: replace _s/_z with _r/_t (\316\270). Units: meters for s/z/r, radians for \316\270.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_39->setText(QCoreApplication::translate("MainWindow", "NC Data File:", nullptr));
        pushBrowseStructured->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "File Path:", nullptr));
#if QT_CONFIG(tooltip)
        label_40->setToolTip(QCoreApplication::translate("MainWindow", "Value of Nr at any location outside the structured grid range.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_40->setText(QCoreApplication::translate("MainWindow", "Nr Out of Range:", nullptr));
#if QT_CONFIG(tooltip)
        grpWavefieldScanning->setToolTip(QCoreApplication::translate("MainWindow", "AxiSEM3D learns a sub-optimal Nr(s,z) during simulation and dumps it to a file for re-use. It analyzes the Fourier series at mesh points upon energy peak arrival. To re-use: set type_Nr = POINTWISE and point nc_data_file to the scanning output.", nullptr));
#endif // QT_CONFIG(tooltip)
        grpWavefieldScanning->setTitle(QCoreApplication::translate("MainWindow", "Wavefield Scanning", nullptr));
        checkWavefieldScanningOn->setText(QCoreApplication::translate("MainWindow", "Enable Scanning", nullptr));
#if QT_CONFIG(tooltip)
        label_43->setToolTip(QCoreApplication::translate("MainWindow", "File path for the wavefield scanning output.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_43->setText(QCoreApplication::translate("MainWindow", "Output File:", nullptr));
#if QT_CONFIG(tooltip)
        label_44->setToolTip(QCoreApplication::translate("MainWindow", "Accuracy loss by truncating the Fourier series of the wavefield. Allowed range: [1e-4, 1e-1].", nullptr));
#endif // QT_CONFIG(tooltip)
        label_44->setText(QCoreApplication::translate("MainWindow", "Threshold Fourier Conv:", nullptr));
#if QT_CONFIG(tooltip)
        label_45->setToolTip(QCoreApplication::translate("MainWindow", "Peaks with amplitude smaller than this \303\227 largest peak are skipped. 1.0 = only largest peak, 0.0 = all peaks. Range: [0.0, 1.0].", nullptr));
#endif // QT_CONFIG(tooltip)
        label_45->setText(QCoreApplication::translate("MainWindow", "Relative Amp Skip:", nullptr));
#if QT_CONFIG(tooltip)
        label_47->setToolTip(QCoreApplication::translate("MainWindow", "Absolute amplitude threshold for skipping energy peaks. Allowed range: [1e-14, 1e-10].", nullptr));
#endif // QT_CONFIG(tooltip)
        label_47->setText(QCoreApplication::translate("MainWindow", "Absolute Amp Skip:", nullptr));
#if QT_CONFIG(tooltip)
        label_48->setToolTip(QCoreApplication::translate("MainWindow", "Maximum number of energy peaks to consider. Use a small value to focus on only the largest peaks.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_48->setText(QCoreApplication::translate("MainWindow", "Max Num Peaks:", nullptr));
        checkScanOnlyVertexGLL->setText(QCoreApplication::translate("MainWindow", "Perform Scanning Only on Vertex GLL Points", nullptr));
#if QT_CONFIG(tooltip)
        label_49->setToolTip(QCoreApplication::translate("MainWindow", "Number of steps per mesh period for scanning. Must be at least 4; recommended range: [8, 16].", nullptr));
#endif // QT_CONFIG(tooltip)
        label_49->setText(QCoreApplication::translate("MainWindow", "Steps per Mesh Period:", nullptr));
        grpTimeAxis->setTitle(QCoreApplication::translate("MainWindow", "Time Axis", nullptr));
#if QT_CONFIG(tooltip)
        lblRecordLength->setToolTip(QCoreApplication::translate("MainWindow", "The end time in seismograms (seconds). The start time depends on the source-time functions.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblRecordLength->setText(QCoreApplication::translate("MainWindow", "Record Length (s):", nullptr));
        lineRecordLength->setText(QCoreApplication::translate("MainWindow", "1800.", nullptr));
#if QT_CONFIG(tooltip)
        lblEnforcedDt->setToolTip(QCoreApplication::translate("MainWindow", "User-specified time step. Use NONE to automatically determine Dt by mesh, or enter a numeric value.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblEnforcedDt->setText(QCoreApplication::translate("MainWindow", "Enforced Dt:", nullptr));
        lineEnforcedDt->setText(QCoreApplication::translate("MainWindow", "NONE", nullptr));
#if QT_CONFIG(tooltip)
        lblCourant->setToolTip(QCoreApplication::translate("MainWindow", "Courant number for determining Dt by mesh. Dt increases with this number. Decrease if numerical instability occurs. Safe: 0.5, Aggressive: 1.0. Typical: 0.6-0.7.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblCourant->setText(QCoreApplication::translate("MainWindow", "Courant Number:", nullptr));
        lineCourantNumber->setText(QCoreApplication::translate("MainWindow", "0.6", nullptr));
#if QT_CONFIG(tooltip)
        lblIntegrator->setToolTip(QCoreApplication::translate("MainWindow", "NEWMARK is faster while SYMPLECTIC is less dispersive. Use SYMPLECTIC for ultra-long simulations. Dt can be larger for SYMPLECTIC than for NEWMARK.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblIntegrator->setText(QCoreApplication::translate("MainWindow", "Time Integrator:", nullptr));
        comboIntegrator->setItemText(0, QCoreApplication::translate("MainWindow", "NEWMARK", nullptr));
        comboIntegrator->setItemText(1, QCoreApplication::translate("MainWindow", "SYMPLECTIC", nullptr));

        labelSourceCount->setText(QCoreApplication::translate("MainWindow", "Number of Sources:", nullptr));
        labelOutputTitle->setText(QCoreApplication::translate("MainWindow", "Station-Wise Output\n"
"\n"
"Configure station groups for recording wavefields.\n"
"Each group can have its own channels, sampling rate, and file format.", nullptr));
        labelOutputCount->setText(QCoreApplication::translate("MainWindow", "Number of Station Groups:", nullptr));
        labelElementWise->setText(QCoreApplication::translate("MainWindow", "Element-Wise Output: not yet implemented (defaults to empty []).", nullptr));
        btnNr->setText(QCoreApplication::translate("MainWindow", "Nr", nullptr));
        btnRun->setText(QCoreApplication::translate("MainWindow", "Run!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Mesh File", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Stations File", nullptr));
        btnSource->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        btnBackL->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        grpExePath->setTitle(QCoreApplication::translate("MainWindow", "AxiSEM3D Executable", nullptr));
        btnBrowseExe->setText(QCoreApplication::translate("MainWindow", "Locate Executable...", nullptr));
        lineExePath->setPlaceholderText(QCoreApplication::translate("MainWindow", "Path to axisem3d executable", nullptr));
        lblMpiProcs->setText(QCoreApplication::translate("MainWindow", "MPI Processes:", nullptr));
#if QT_CONFIG(tooltip)
        lblMpiProcs->setToolTip(QCoreApplication::translate("MainWindow", "Number of MPI processes for mpirun. Only used for local runs.", nullptr));
#endif // QT_CONFIG(tooltip)
        grpBatchJob->setTitle(QCoreApplication::translate("MainWindow", "Batch Job (Remote)", nullptr));
        checkBatchJob->setText(QCoreApplication::translate("MainWindow", "Submit as batch job", nullptr));
#if QT_CONFIG(tooltip)
        checkBatchJob->setToolTip(QCoreApplication::translate("MainWindow", "If checked, write a batch job script and submit it instead of running directly. Only available in remote mode.", nullptr));
#endif // QT_CONFIG(tooltip)
        lblBatchFilename->setText(QCoreApplication::translate("MainWindow", "Filename:", nullptr));
        lineBatchFilename->setText(QCoreApplication::translate("MainWindow", "run_axisem3d.sh", nullptr));
        lineBatchFilename->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g. run_axisem3d.sh or job.slurm", nullptr));
        editBatchScript->setPlaceholderText(QCoreApplication::translate("MainWindow", "Write your batch job script here (e.g. SLURM, PBS, SGE)...", nullptr));
        btnRunSim->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        btnStopSim->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        btnBackRun->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        grpRunLog->setTitle(QCoreApplication::translate("MainWindow", "Output Log", nullptr));
        editRunLog->setPlaceholderText(QCoreApplication::translate("MainWindow", "Simulation output will appear here...", nullptr));
        labelSSHTitle->setText(QCoreApplication::translate("MainWindow", "SSH Connection", nullptr));
        labelHost->setText(QCoreApplication::translate("MainWindow", "Host:", nullptr));
        lineSSHHost->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g. cluster.university.edu", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        lineSSHPort->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        labelUsername->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        lineSSHUser->setPlaceholderText(QCoreApplication::translate("MainWindow", "e.g. jsmith", nullptr));
        labelPassword->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        labelSSHStatus->setText(QString());
        btnBackR->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnSSHConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
