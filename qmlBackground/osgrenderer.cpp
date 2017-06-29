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

#include <QQuickWindow>
#include <QScreen>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

#include "osgrenderer.h"

#include <osgGA/TrackballManipulator>
#include <osg/Geode>
#include <osg/Shape>
#include <osg/ShapeDrawable>

OSGRenderer::OSGRenderer(QObject *parent)
    : OSGBaseRenderer(parent)
    , m_glFuncs(nullptr)
    , m_window(nullptr)
{

}

OSGRenderer::~OSGRenderer()
{

}

void OSGRenderer::setup(QQuickWindow *win)
{
    m_window = win;
    m_window->setClearBeforeRendering(false);

    connect(win, &QQuickWindow::beforeRendering, this, &OSGRenderer::render, Qt::DirectConnection);
    update();
}

void OSGRenderer::update()
{
    if(m_window)
        m_window->update();
}

void OSGRenderer::render()
{
    m_window->resetOpenGLState();

    if (!m_osgInitialized) {
        m_glFuncs = m_window->openglContext()->functions();
        setupOSG(m_window->width(), m_window->height(), m_window->screen()->devicePixelRatio());
        m_osgInitialized = true;
        emit initialized();
    }

    OSGBaseRenderer::render();

    if (m_glFuncs) {
        m_glFuncs->glPixelStorei(GL_PACK_ALIGNMENT, 4);
        m_glFuncs->glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    }

    update();
}
