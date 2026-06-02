cmake_minimum_required(VERSION 3.19)
project(axisem3d_v1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(axisem3d_v1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    NrText.h
    NrText.cpp
    udpfieldswidget.h udpfieldswidget.cpp udpfieldswidget.ui
    model3dwidget.h model3dwidget.cpp
    outputgroupwidget.h outputgroupwidget.cpp
    sourcewidget.h sourcewidget.cpp
    resources.qrc
    styles/main.qss
    styles/button.qss



)

target_link_libraries(axisem3d_v1
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS axisem3d_v1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET axisem3d_v1
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
