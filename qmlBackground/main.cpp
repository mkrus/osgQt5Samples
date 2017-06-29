#include <QGuiApplication>
#include <QSurfaceFormat>

#include "osgquickview.h"
#include "osgrenderer.h"

#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setVersion(3, 2);
    QSurfaceFormat::setDefaultFormat(format);

    OSGQuickView view;
    view.resize(800, 600);
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();

    OSGRenderer* r = view.m_renderer;
    QObject::connect(&view, &OSGQuickView::initialized, [r]() {
        QString sample = "/Users/mike/Developers/qt5/qt3d/examples/qt3d/exampleresources/assets/obj/toyplane.obj";
        osg::ref_ptr<osg::Node> model = osgDB::readNodeFile(sample.toStdString());
        if (model)
            r->viewer()->setSceneData(model);
        else
            qDebug() << "Failed to load " << sample;

        r->viewer()->setCameraManipulator(new osgGA::TrackballManipulator());
    });

    return app.exec();
}
