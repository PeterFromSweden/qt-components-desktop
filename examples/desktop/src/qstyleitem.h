/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef STYLEWRAPPER_H
#define STYLEWRAPPER_H

#include <QDeclarativeItem>
#include <QtGui/QStyle>


class QStyleItem: public QDeclarativeItem
{
    Q_OBJECT

    Q_PROPERTY( bool sunken READ sunken WRITE setSunken NOTIFY sunkenChanged)
    Q_PROPERTY( bool raised READ raised WRITE setRaised NOTIFY raisedChanged)
    Q_PROPERTY( bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY( bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY( bool selected READ selected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY( bool focus READ focus WRITE setFocus NOTIFY focusChanged)
    Q_PROPERTY( bool on READ on WRITE setOn NOTIFY onChanged)
    Q_PROPERTY( bool hover READ hover WRITE setHover NOTIFY hoverChanged)
    Q_PROPERTY( bool horizontal READ horizontal WRITE setHorizontal NOTIFY horizontalChanged)
    Q_PROPERTY( QString elementType READ elementType WRITE setElementType NOTIFY elementTypeChanged)
    // For range controls
    Q_PROPERTY( int minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)
    Q_PROPERTY( int maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
    Q_PROPERTY( int value READ value WRITE setValue NOTIFY valueChanged)


public:
    QStyleItem(QDeclarativeItem *parent = 0);
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *);

    bool sunken() const { return m_sunken; }
    bool raised() const { return m_raised; }
    bool active() const { return m_active; }
    bool enabled() const { return m_enabled; }
    bool selected() const { return m_selected; }
    bool focus() const { return m_focus; }
    bool on() const { return m_on; }
    bool hover() const { return m_hover; }
    bool horizontal() const { return m_horizontal; }
    int minimum() const { return m_minimum; }
    int maximum() const { return m_maximum; }
    int value() const { return m_value; }

    void setSunken(bool sunken) { if (m_sunken != sunken) {m_sunken = sunken; emit sunkenChanged(); update();}}
    void setRaised(bool raised) { if (m_raised!= raised) {m_raised = raised; emit raisedChanged(); update();}}
    void setActive(bool active) { if (m_active!= active) {m_active = active; emit activeChanged();update();}}
    void setEnabled(bool enabled) { if (m_enabled!= enabled) {m_enabled = enabled; emit enabledChanged();update();}}
    void setSelected(bool selected) { if (m_selected!= selected) {m_selected = selected; emit selectedChanged(); update();}}
    void setFocus(bool focus) { if (m_focus != focus) {m_focus = focus; emit focusChanged(); update();}}
    void setOn(bool on) { if (m_on != on) {m_on = on ; emit onChanged(); update();}}
    void setHover(bool hover) { if (m_hover != hover) {m_hover = hover ; emit hoverChanged(); update();}}
    void setHorizontal(bool horizontal) { if (m_horizontal != horizontal) {m_horizontal = horizontal; emit horizontalChanged(); update();}}
    void setMinimum(int minimum) { if (m_minimum!= minimum) {m_minimum = minimum; emit minimumChanged(); update();}}
    void setMaximum(int maximum) { if (m_maximum != maximum) {m_maximum = maximum; emit maximumChanged(); update();}}
    void setValue(int  value) { if (m_value!= value) {m_value = value; emit valueChanged(); update();}}



    virtual void initStyleOption(QStyleOption *opt) const;

    QString elementType() const { return m_type; }
    void setElementType(const QString &str) { if (m_type != str) {m_type = str; emit elementTypeChanged();update(); }}

Q_SIGNALS:
    void elementTypeChanged();
    void sunkenChanged();
    void raisedChanged();
    void activeChanged();
    void enabledChanged();
    void selectedChanged();
    void focusChanged();
    void onChanged();
    void hoverChanged();
    void horizontalChanged();
    void minimumChanged();
    void maximumChanged();
    void valueChanged();

protected:
    QString m_type;
    bool m_sunken;
    bool m_raised;
    bool m_active;
    bool m_enabled;
    bool m_selected;
    bool m_focus;
    bool m_hover;
    bool m_on;
    bool m_horizontal;
    int m_minimum;
    int m_maximum;
    int m_value;
};

#endif //STYLEWRAPPER_H