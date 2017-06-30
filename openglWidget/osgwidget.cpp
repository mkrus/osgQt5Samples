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

#include "osgwidget.h"
#include "osgrenderer.h"

#include <QWindow>
#include <QScreen>

OSGWidget::OSGWidget(QWidget* parent)
    : QOpenGLWidget(parent)
    , m_renderer(nullptr)
{

}

void OSGWidget::initializeGL()
{
    m_renderer = new OSGRenderer(this);
    m_renderer->setup(this);
    m_renderer->setupOSG(width(), height(), windowHandle()->screen()->devicePixelRatio());
    emit initialized();
}

void OSGWidget::resizeGL(int w, int h)
{
    m_renderer->resize(w, h, windowHandle()->screen()->devicePixelRatio());
}

void OSGWidget::paintGL()
{
    m_renderer->render();
}

void OSGWidget::keyPressEvent(QKeyEvent *event)
{
    m_renderer->keyPressEvent(event);
}

void OSGWidget::keyReleaseEvent(QKeyEvent *event)
{
    m_renderer->keyReleaseEvent(event);
}

void OSGWidget::mousePressEvent(QMouseEvent *event)
{
    m_renderer->mousePressEvent(event);
}

void OSGWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_renderer->mouseReleaseEvent(event);
}

void OSGWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_renderer->mouseDoubleClickEvent(event);
}

void OSGWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_renderer->mouseMoveEvent(event);
}

void OSGWidget::wheelEvent(QWheelEvent *event)
{
    m_renderer->wheelEvent(event);
}
