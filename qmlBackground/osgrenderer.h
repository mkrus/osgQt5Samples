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

#ifndef OSGRENDERER_H
#define OSGRENDERER_H

#include <osgbaserenderer.h>

class QQuickWindow;
class QOpenGLContext;
class QOpenGLFunctions;

class OSGRenderer : public OSGBaseRenderer
{
    Q_OBJECT
public:
    explicit OSGRenderer(QObject *parent = 0);
    virtual ~OSGRenderer();

    void setup(QQuickWindow* win);

    void update() override;
    void render() override;

signals:
    void initialized();

private:
    QOpenGLFunctions *m_glFuncs;
    QQuickWindow* m_window;
};

#endif // OSGRENDERER_H
