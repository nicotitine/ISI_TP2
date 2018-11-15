######################################################################
# Automatically generated by qmake (3.1) Sun Oct 21 04:33:42 2018
######################################################################
QT += widgets xml opengl
CONFIG *= qt opengl release
TEMPLATE = app
TARGET = isiviewer-1.4
LIBS = -lQGLViewer


# Input
HEADERS += my_main_window.h \
           my_object3d.h \
           my_qglviewer.h \
           my_scene.h \
           objects/pyramid.h \
           objects/triMesh.h \
           objects/corner_cube.h \
           objects/cube.h \
    objects/disk.h \
    objects/cylinder.h \
    objects/cone.h \
    objects/disk_hole.h \
    objects/sphere.h \
    objects/torus.h
FORMS += my_gui_form.ui
SOURCES += main.cpp \
           my_main_window.cpp \
           my_object3d.cpp \
           my_qglviewer.cpp \
           my_scene.cpp \
           objects/pyramid.cpp \
           objects/triMesh.cpp \
    objects/cube.cpp \
    objects/corner_cube.cpp \
    objects/disk.cpp \
    objects/cylinder.cpp \
    objects/cone.cpp \
    objects/disk_hole.cpp \
    objects/sphere.cpp \
    objects/torus.cpp
