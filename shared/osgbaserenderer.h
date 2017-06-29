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

#ifndef OSGBASERENDERER_H
#define OSGBASERENDERER_H

#include <QObject>

#include <osg/ref_ptr>
// Copyright (C) 2017 Mike Krus
// derived from OSG GraphicsWindowQt by Wang Rui
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
#include <osgViewer/Viewer>

class QInputEvent;
class QKeyEvent;
class QMouseEvent;
class QWheelEvent;

class OSGBaseRenderer : public QObject
{
    Q_OBJECT
public:
    explicit OSGBaseRenderer(QObject *parent = 0);
    virtual ~OSGBaseRenderer();

    osgViewer::Viewer *viewer() { return &m_osgViewer; }

    bool continuousUpdate() const { return m_continuousUpdate; }
    void setContinuousUpdate(bool continuousUpdate) { m_continuousUpdate = continuousUpdate; }

    virtual void keyPressEvent( QKeyEvent* event );
    virtual void keyReleaseEvent( QKeyEvent* event );
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseDoubleClickEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void wheelEvent( QWheelEvent* event );

    virtual void update();
    virtual void render();
    virtual void resize(int windowWidth, int windowHeight, float windowScale);

    void setupOSG(int windowWidth, int windowHeight, float windowScale);

protected:
    void setKeyboardModifiers( QInputEvent* event );

    bool m_osgInitialized;
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> m_osgWinEmb;
    osgViewer::Viewer m_osgViewer;
    float m_windowScale;
    bool m_continuousUpdate;
};

#endif // OSGRENDERER_H
