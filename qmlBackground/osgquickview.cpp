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

#include "osgquickview.h"
#include "osgrenderer.h"

#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScreen>

OSGQuickView::OSGQuickView()
    : QQuickView()
{
    connect(engine(), SIGNAL(quit()), this, SLOT(close()));
    setResizeMode(QQuickView::SizeRootObjectToView);
    setClearBeforeRendering(false);

    m_renderer = new OSGRenderer(this);
    m_renderer->setup(this);
    engine()->rootContext()->setContextProperty("_renderer", m_renderer);

    connect(m_renderer, &OSGRenderer::initialized, this, &OSGQuickView::initialized);
}

void OSGQuickView::resizeEvent(QResizeEvent *ev)
{
    m_renderer->resize(ev->size().width(), ev->size().height(), screen()->devicePixelRatio());
}

void OSGQuickView::keyPressEvent(QKeyEvent *event)
{
    m_renderer->keyPressEvent(event);
}

void OSGQuickView::keyReleaseEvent(QKeyEvent *event)
{
    m_renderer->keyReleaseEvent(event);
}

void OSGQuickView::mousePressEvent(QMouseEvent *event)
{
    m_renderer->mousePressEvent(event);
}

void OSGQuickView::mouseReleaseEvent(QMouseEvent *event)
{
    m_renderer->mouseReleaseEvent(event);
}

void OSGQuickView::mouseDoubleClickEvent(QMouseEvent *event)
{
    m_renderer->mouseDoubleClickEvent(event);
}

void OSGQuickView::mouseMoveEvent(QMouseEvent *event)
{
    m_renderer->mouseMoveEvent(event);
}

void OSGQuickView::wheelEvent(QWheelEvent *event)
{
    m_renderer->wheelEvent(event);
}
