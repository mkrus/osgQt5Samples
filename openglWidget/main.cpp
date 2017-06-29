// Copyright (C) 2017 Mike Krus
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

#include <QApplication>
#include <QSurfaceFormat>
#include <QMainWindow>
#include <QDebug>

#include "osgwidget.h"
#include "osgrenderer.h"

#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setVersion(3, 2);
    QSurfaceFormat::setDefaultFormat(format);

    QMainWindow view;
    OSGWidget *w = new OSGWidget;

    QObject::connect(w, &OSGWidget::initialized, [w]() {
        QString sample = "/Users/mike/Developers/qt5/qt3d/examples/qt3d/exampleresources/assets/obj/toyplane.obj";
        osg::ref_ptr<osg::Node> model = osgDB::readNodeFile(sample.toStdString());
        if (model)
            w->m_renderer->viewer()->setSceneData(model);
        else
            qDebug() << "Failed to load " << sample;

        w->m_renderer->viewer()->setCameraManipulator(new osgGA::TrackballManipulator());
    });

    view.setCentralWidget(w);
    view.resize(800, 600);
    view.show();

    return app.exec();
}
