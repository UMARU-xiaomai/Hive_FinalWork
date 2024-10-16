cmake_minimum_required(VERSION 3.16)

project(Hive_FinalWork VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia LinguistTools)

set(TS_FILES Hive_FinalWork_zh_CN.ts)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Hive_FinalWork
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        scenemanager.h scenemanager.cpp


        Scenes/startscene.h Scenes/startscene.cpp Scenes/startscene.ui
        Scenes/playing.h Scenes/playing.cpp Scenes/playing.ui
        Resources.qrc
        Playing/game.h Playing/game.cpp
        Playing/player.h Playing/player.cpp
        Playing/aiplayer.h Playing/aiplayer.cpp
        Playing/board.h Playing/board.cpp
        Playing/piece.h Playing/piece.cpp
        Playing/position.h Playing/position.cpp
        Playing/cell.h Playing/cell.cpp


        Playing/piecewidget.h Playing/piecewidget.cpp Playing/piecewidget.ui
        Playing/pieces.h
        Playing/pieces.cpp
        Playing/availablecellwidget.h Playing/availablecellwidget.cpp Playing/availablecellwidget.ui
        Scenes/extensions/hexagonlayout.cpp Scenes/extensions/hexagonlayout.h
        Scenes/extensions/centeredscrollarea.cpp Scenes/extensions/centeredscrollarea.h
        Playing/plugpiece.h Playing/plugpiece.cpp
        Playing/testwidget.h Playing/testwidget.cpp Playing/testwidget.ui








    )


    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(Hive_FinalWork SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Hive_FinalWork
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(Hive_FinalWork PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia)

# 添加插件构建目录
# add_subdirectory(Playing/Plugins)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Hive_FinalWork)
endif()
set_target_properties(Hive_FinalWork PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Hive_FinalWork
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Hive_FinalWork)
endif()

