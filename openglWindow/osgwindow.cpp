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

#include "osgwindow.h"
#include "osgrenderer.h"

#include <QScreen>
#include <QDebug>

OSGWindow::OSGWindow()
    : QOpenGLWindow()
    , m_renderer(nullptr)
{

}

void OSGWindow::initializeGL()
{
    m_renderer = new OSGRenderer(this);
    m_renderer->setup(this);
    m_renderer->setupOSG(width(), height(), screen()->devicePixelRatio());
    emit initialized();
}

void OSGWindow::resizeGL(int w, int h)
{
    m_renderer->resize(w, h, screen()->devicePixelRatio());
}

void OSGWindow::paintGL()
{
    m_renderer->render();
}

void OSGWindow::keyPressEvent(QKeyEvent *event)
{
    m_renderer->keyPressEvent(event);
}

void OSGWindow::keyReleaseEvent(QKeyEvent *event)
{
    m_renderer->keyReleaseEvent(event);
}

void OSGWindow::mousePressEvent(QMouseEvent *event)
{
    m_renderer->mousePressEvent(event);
}

void OSGWindow::mouseReleaseEvent(QMouseEvent *event)
{
    m_renderer->mouseReleaseEvent(event);
}

void OSGWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_renderer->mouseDoubleClickEvent(event);
}

void OSGWindow::mouseMoveEvent(QMouseEvent *event)
{
    m_renderer->mouseMoveEvent(event);
}

void OSGWindow::wheelEvent(QWheelEvent *event)
{
    m_renderer->wheelEvent(event);
}
