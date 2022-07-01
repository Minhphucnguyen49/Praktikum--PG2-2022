QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AbstractUI.cpp \
        Active.cpp \
        Character.cpp \
        DungeonCrawler.cpp \
        Floor.cpp \
        Level.cpp \
        Pit.cpp \
        Portal.cpp \
        Ramp.cpp \
        TerminalUI.cpp \
        Tile.cpp \
        Wall.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AbstractUI.h \
    Active.h \
    Character.h \
    Controller.h \
    Door.h \
    DungeonCrawler.h \
    Floor.h \
    Level.h \
    Passive.h \
    Pit.h \
    Portal.h \
    Ramp.h \
    TerminalUI.h \
    Tile.h \
    Wall.h
