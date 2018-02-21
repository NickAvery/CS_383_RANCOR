######################################################################
# Automatically generated by qmake (3.1) Wed Feb 21 10:40:59 2018
######################################################################
QT += core gui    \
      multimedia   \
      multimediawidgets    \
      winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 


TEMPLATE = app
TARGET = SpaceShooter
INCLUDEPATH += . inc inc/Jake inc/James inc/Nick inc/Baylus inc/Angelo inc/Karstin

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += inc/JAaudio.h inc/JAgame.h inc/JTgame.h inc/JTwalls.h
SOURCES += src/Jake/JAaudio.cpp src/Jake/JAgame.cpp src/Jake/main.cpp src/James/JTmap.cpp src/James/JTwalls.cpp
