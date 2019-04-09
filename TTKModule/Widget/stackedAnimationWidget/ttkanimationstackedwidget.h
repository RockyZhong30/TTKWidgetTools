#ifndef TTKANIMATIONSTACKEDWIDGET_H
#define TTKANIMATIONSTACKEDWIDGET_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2019 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QPainter>
#include <QVariant>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include "ttkglobaldefine.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_EXTRAS_EXPORT TTKAnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
    Q_PROPERTY(float value READ GetValue WRITE SetValue)
public:
    enum AnimationType
    {
        TopToBottom,
        BottomToTop,
        LeftToRight,
        RightToLeft,
		RollInOut,
		FadeInOut,
		BlackInOut,
		SlideInOut,
		CoverInOutLeft,
		CoverInOutRight,
		FadeExchange,
		VerticalFlipRotate,
		VerticalFlipRotateOut,
		VerticalCubeRotateT2B,
		VerticalCubeRotateB2T,
		HorizontalFlipRotate
    };

    explicit TTKAnimationStackedWidget(QWidget *parent = nullptr);
    virtual ~TTKAnimationStackedWidget();

    void start(int index);
    void setLength(int length, AnimationType type);

    void setCurve(QEasingCurve::Type curve);
    void setRevert(bool revert);

    void setDuration(int duration);
    int getDuration() const;

    void setFadeEnable(bool enable);
    void setAnimatEnable(bool animat);

	void addWidget(QWidget *widget);

	bool isAnimating();

	float GetValue() const;
    void SetValue(const float value);

Q_SIGNALS:
    void pageChanged(int index);

public Q_SLOTS:
	void setCurrentIndex(int index);

private Q_SLOTS:
    void animationFinished();

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    void renderCurrentWidget(QPainter &painter, QTransform &transform);

    bool m_isAnimating;
    float m_currentValue;
    float m_rangeValue;
    float m_startValue;
    float m_endValue;

    bool m_fade;
    bool m_animat;

    QEasingCurve::Type m_curve;
    int m_currentIndex, m_previousIndex;
    AnimationType m_type;
    QPropertyAnimation *m_animation;

    bool m_revert;

    QPixmap m_privPixmap;
    QPixmap m_currentPixmap;
    QPixmap	*m_coverPixmap;
};

#endif // TTKANIMATIONSTACKEDWIDGET_H