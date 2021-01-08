/* -*- c++ -*- */
/*
 * Copyright 2013-2021 Sylvain Munaut <tnt@246tNt.com>
 *
 * This file is part of gr-fosphor
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QtEvents>
#include <QThread>

#include "QGLSurface.h"
#include "qt_sink_c_impl.h"

#include <stdio.h>

namespace gr {
  namespace fosphor {

QGLSurface::QGLSurface(QWidget *parent, qt_sink_c_impl *block)
  : QGLWidget(parent), d_block(block)
{
	/* Save the pointer to the main GUI thread */
	this->d_gui_thread = this->thread();

	/* QWidget policies */
	this->setFocusPolicy(Qt::StrongFocus);
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


void
QGLSurface::hideEvent(QHideEvent *he)
{
	this->d_block->cb_visibility(this->isVisible());
}

void
QGLSurface::showEvent(QShowEvent *he)
{
	this->d_block->cb_visibility(this->isVisible());
}

void
QGLSurface::paintEvent(QPaintEvent *pe)
{
	/* Don't do anything */

	/*
	 * The default implementation calls makeCurrent but here we want
	 * _other_ threads to be current, so we need a dummy empty impl
	 * for the paintEvent
	 */
}

void
QGLSurface::resizeEvent(QResizeEvent *re)
{
	/*
	 * The default implementation calls makeCurrent but here we want
	 * _other_ threads to be current, so don't do that !
	 */

	/* Call back to main block */
	this->d_block->cb_reshape(re->size().width(), re->size().height());
}

void
QGLSurface::keyPressEvent(QKeyEvent *ke)
{
	switch (ke->key()) {
	case Qt::Key_Up:
		this->d_block->execute_ui_action(qt_sink_c_impl::REF_DOWN);
		break;
	case Qt::Key_Down:
		this->d_block->execute_ui_action(qt_sink_c_impl::REF_UP);
		break;
	case Qt::Key_Left:
		this->d_block->execute_ui_action(qt_sink_c_impl::DB_PER_DIV_DOWN);
		break;
	case Qt::Key_Right:
		this->d_block->execute_ui_action(qt_sink_c_impl::DB_PER_DIV_UP);
		break;
	case Qt::Key_Z:
		this->d_block->execute_ui_action(qt_sink_c_impl::ZOOM_TOGGLE);
		break;
	case Qt::Key_W:
		this->d_block->execute_ui_action(qt_sink_c_impl::ZOOM_WIDTH_UP);
		break;
	case Qt::Key_S:
		this->d_block->execute_ui_action(qt_sink_c_impl::ZOOM_WIDTH_DOWN);
		break;
	case Qt::Key_D:
		this->d_block->execute_ui_action(qt_sink_c_impl::ZOOM_CENTER_UP);
		break;
	case Qt::Key_A:
		this->d_block->execute_ui_action(qt_sink_c_impl::ZOOM_CENTER_DOWN);
		break;
	case Qt::Key_Q:
		this->d_block->execute_ui_action(qt_sink_c_impl::RATIO_UP);
		break;
	case Qt::Key_E:
		this->d_block->execute_ui_action(qt_sink_c_impl::RATIO_DOWN);
		break;
	case Qt::Key_Space:
		this->d_block->execute_ui_action(qt_sink_c_impl::FREEZE_TOGGLE);
		break;
	}
}

void
QGLSurface::mousePressEvent(QMouseEvent *me)
{
	int x, y;

	if (me->type() != QEvent::MouseButtonDblClick)
		return;

	x = me->x();
	y = this->size().height() - me->y() - 1;

	this->d_block->execute_mouse_action(qt_sink_c_impl::CLICK, x, y);
}


void
QGLSurface::grabContext()
{
	QMetaObject::invokeMethod(
		this,
		"giveContext",
		Qt::BlockingQueuedConnection,
		Q_ARG(QThread*, QThread::currentThread())
	);

	this->makeCurrent();
}

void
QGLSurface::releaseContext()
{
	this->doneCurrent();
	this->context()->moveToThread(this->d_gui_thread);
}

void
QGLSurface::giveContext(QThread *thread)
{
	this->doneCurrent();
	this->context()->moveToThread(thread);
}

  } /* namespace fosphor */
} /* namespace gr */
