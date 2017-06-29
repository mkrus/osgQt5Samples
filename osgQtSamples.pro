TEMPLATE = subdirs

SUBDIRS = \
    shared \
    openglWidget \
    openglWindow \
    qmlBackground

openglWidget.depends = shared
openglWindow.depends = shared
qmlBackground.depends = shared

OTHER_FILES += README.md
