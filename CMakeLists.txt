cmake_minimum_required(VERSION 3.16)

project(BMIcalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        bmi_graphwidget.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BMIcalc
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        bmi_graphwidget.h
        bmi_graphwidget.cpp
        bmi_recommendationwidget.h
        bmi_recommendationwidget.cpp
    )
else()
    add_executable(BMIcalc
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(BMIcalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BMIcalc)
endif()
