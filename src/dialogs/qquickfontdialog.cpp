/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtQuick.Dialogs module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qquickfontdialog_p.h"
#include <QQuickItem>
#include <private/qguiapplication_p.h>
#include <qpa/qplatformintegration.h>

QT_BEGIN_NAMESPACE

/*!
    \qmltype AbstractFontDialog
    \instantiates QQuickFontDialog
    \inqmlmodule QtQuick.Dialogs 1
    \ingroup qtquick-visual
    \brief API wrapper for QML font dialog implementations
    \since 5.2
    \internal

    AbstractFontDialog provides only the API for implementing a font dialog.
    The implementation (e.g. a Window or preferably an Item, in case it is
    shown on a device that doesn't support multiple windows) can be provided as
    \l implementation, which is the default property (the only allowed child
    element).
*/

/*!
    \qmlsignal QtQuick::Dialogs::AbstractFontDialog::accepted

    The \a accepted signal is emitted by \l accept().

    The corresponding handler is \c onAccepted.
*/

/*!
    \qmlsignal QtQuick::Dialogs::AbstractFontDialog::rejected

    The \a accepted signal is emitted by \l reject().

    The corresponding handler is \c onRejected.
*/

/*!
    \class QQuickFontDialog
    \inmodule QtQuick.Dialogs
    \internal

    The QQuickFontDialog class is a concrete subclass of \l
    QQuickAbstractFontDialog, but it is abstract from the QML perspective
    because it needs to enclose a graphical implementation. It exists in order
    to provide accessors and helper functions which the QML implementation will
    need.

    \since 5.2
*/

/*!
    Constructs a font dialog wrapper with parent window \a parent.
*/
QQuickFontDialog::QQuickFontDialog(QObject *parent)
    : QQuickAbstractFontDialog(parent)
{
}


/*!
    Destroys the font dialog wrapper.
*/
QQuickFontDialog::~QQuickFontDialog()
{
}

/*!
    \qmlproperty bool AbstractFontDialog::visible

    This property holds whether the dialog is visible. By default this is false.
*/

/*!
    \qmlproperty QObject AbstractFontDialog::implementation

    The QML object which implements the actual font dialog. Should be either a
    \l Window or an \l Item.
*/

void QQuickFontDialog::accept()
{
    setFont(m_currentFont);
    QQuickAbstractFontDialog::accept();
}

QT_END_NAMESPACE
