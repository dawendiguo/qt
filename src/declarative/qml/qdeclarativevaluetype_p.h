/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDECLARATIVEVALUETYPE_P_H
#define QDECLARATIVEVALUETYPE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include "qdeclarativeproperty.h"
#include "qdeclarativeproperty_p.h"

#include <QtCore/qobject.h>
#include <QtCore/qrect.h>
#include <QtCore/qeasingcurve.h>
#include <QtCore/qvariant.h>
#include <QtGui/qvector3d.h>
#include <QtGui/qfont.h>

QT_BEGIN_NAMESPACE

class Q_DECLARATIVE_EXPORT QDeclarativeValueType : public QObject
{
    Q_OBJECT
public:
    QDeclarativeValueType(QObject *parent = 0);
    virtual void read(QObject *, int) = 0;
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags flags) = 0;
    virtual QVariant value() = 0;
    virtual void setValue(QVariant) = 0;
};

class Q_DECLARATIVE_EXPORT QDeclarativeValueTypeFactory
{
public:
    QDeclarativeValueTypeFactory();
    ~QDeclarativeValueTypeFactory();
    static QDeclarativeValueType *valueType(int);

    QDeclarativeValueType *valueTypes[QVariant::UserType - 1]; 
    QDeclarativeValueType *operator[](int idx) const { return valueTypes[idx]; }
};

class Q_AUTOTEST_EXPORT QDeclarativePointFValueType : public QDeclarativeValueType
{
    Q_PROPERTY(qreal x READ x WRITE setX)
    Q_PROPERTY(qreal y READ y WRITE setY)
    Q_OBJECT
public:
    QDeclarativePointFValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    qreal x() const;
    qreal y() const;
    void setX(qreal);
    void setY(qreal);

private:
    QPointF point;
};

class Q_AUTOTEST_EXPORT QDeclarativePointValueType : public QDeclarativeValueType
{
    Q_PROPERTY(int x READ x WRITE setX)
    Q_PROPERTY(int y READ y WRITE setY)
    Q_OBJECT
public:
    QDeclarativePointValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    int x() const;
    int y() const;
    void setX(int);
    void setY(int);

private:
    QPoint point;
};

class Q_AUTOTEST_EXPORT QDeclarativeSizeFValueType : public QDeclarativeValueType
{
    Q_PROPERTY(qreal width READ width WRITE setWidth)
    Q_PROPERTY(qreal height READ height WRITE setHeight)
    Q_OBJECT
public:
    QDeclarativeSizeFValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    qreal width() const;
    qreal height() const;
    void setWidth(qreal);
    void setHeight(qreal);

private:
    QSizeF size;
};

class Q_AUTOTEST_EXPORT QDeclarativeSizeValueType : public QDeclarativeValueType
{
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(int height READ height WRITE setHeight)
    Q_OBJECT
public:
    QDeclarativeSizeValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    int width() const;
    int height() const;
    void setWidth(int);
    void setHeight(int);

private:
    QSize size;
};

class Q_AUTOTEST_EXPORT QDeclarativeRectFValueType : public QDeclarativeValueType
{
    Q_PROPERTY(qreal x READ x WRITE setX)
    Q_PROPERTY(qreal y READ y WRITE setY)
    Q_PROPERTY(qreal width READ width WRITE setWidth)
    Q_PROPERTY(qreal height READ height WRITE setHeight)
    Q_OBJECT
public:
    QDeclarativeRectFValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    qreal x() const;
    qreal y() const;
    void setX(qreal);
    void setY(qreal);
    
    qreal width() const;
    qreal height() const;
    void setWidth(qreal);
    void setHeight(qreal);

private:
    QRectF rect;
};

class Q_AUTOTEST_EXPORT QDeclarativeRectValueType : public QDeclarativeValueType
{
    Q_PROPERTY(int x READ x WRITE setX)
    Q_PROPERTY(int y READ y WRITE setY)
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(int height READ height WRITE setHeight)
    Q_OBJECT
public:
    QDeclarativeRectValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    int x() const;
    int y() const;
    void setX(int);
    void setY(int);
    
    int width() const;
    int height() const;
    void setWidth(int);
    void setHeight(int);

private:
    QRect rect;
};

class Q_AUTOTEST_EXPORT QDeclarativeVector3DValueType : public QDeclarativeValueType
{
    Q_PROPERTY(qreal x READ x WRITE setX)
    Q_PROPERTY(qreal y READ y WRITE setY)
    Q_PROPERTY(qreal z READ z WRITE setZ)
    Q_OBJECT
public:
    QDeclarativeVector3DValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    qreal x() const;
    qreal y() const;
    qreal z() const;
    void setX(qreal);
    void setY(qreal);
    void setZ(qreal);

private:
    QVector3D vector;
};

class Q_AUTOTEST_EXPORT QDeclarativeEasingValueType : public QDeclarativeValueType
{
    Q_OBJECT
    Q_ENUMS(Type)

    Q_PROPERTY(QDeclarativeEasingValueType::Type type READ type WRITE setType)
    Q_PROPERTY(qreal amplitude READ amplitude WRITE setAmplitude)
    Q_PROPERTY(qreal overshoot READ overshoot WRITE setOvershoot)
    Q_PROPERTY(qreal period READ period WRITE setPeriod)
public:
    enum Type {
        Linear = QEasingCurve::Linear,
        InQuad = QEasingCurve::InQuad, OutQuad = QEasingCurve::OutQuad,
        InOutQuad = QEasingCurve::InOutQuad, OutInQuad = QEasingCurve::OutInQuad,
        InCubic = QEasingCurve::InCubic, OutCubic = QEasingCurve::OutCubic,
        InOutCubic = QEasingCurve::InOutCubic, OutInCubic = QEasingCurve::OutInCubic,
        InQuart = QEasingCurve::InQuart, OutQuart = QEasingCurve::OutQuart,
        InOutQuart = QEasingCurve::InOutQuart, OutInQuart = QEasingCurve::OutInQuart,
        InQuint = QEasingCurve::InQuint, OutQuint = QEasingCurve::OutQuint,
        InOutQuint = QEasingCurve::InOutQuint, OutInQuint = QEasingCurve::OutInQuint,
        InSine = QEasingCurve::InSine, OutSine = QEasingCurve::OutSine,
        InOutSine = QEasingCurve::InOutSine, OutInSine = QEasingCurve::OutInSine,
        InExpo = QEasingCurve::InExpo, OutExpo = QEasingCurve::OutExpo,
        InOutExpo = QEasingCurve::InOutExpo, OutInExpo = QEasingCurve::OutInExpo,
        InCirc = QEasingCurve::InCirc, OutCirc = QEasingCurve::OutCirc,
        InOutCirc = QEasingCurve::InOutCirc, OutInCirc = QEasingCurve::OutInCirc,
        InElastic = QEasingCurve::InElastic, OutElastic = QEasingCurve::OutElastic,
        InOutElastic = QEasingCurve::InOutElastic, OutInElastic = QEasingCurve::OutInElastic,
        InBack = QEasingCurve::InBack, OutBack = QEasingCurve::OutBack,
        InOutBack = QEasingCurve::InOutBack, OutInBack = QEasingCurve::OutInBack,
        InBounce = QEasingCurve::InBounce, OutBounce = QEasingCurve::OutBounce,
        InOutBounce = QEasingCurve::InOutBounce, OutInBounce = QEasingCurve::OutInBounce,
        InCurve = QEasingCurve::InCurve, OutCurve = QEasingCurve::OutCurve,
        SineCurve = QEasingCurve::SineCurve, CosineCurve = QEasingCurve::CosineCurve,
    };

    QDeclarativeEasingValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    Type type() const;
    qreal amplitude() const;
    qreal overshoot() const;
    qreal period() const;
    void setType(Type);
    void setAmplitude(qreal);
    void setOvershoot(qreal);
    void setPeriod(qreal);

private:
    QEasingCurve easing;
};

class Q_AUTOTEST_EXPORT QDeclarativeFontValueType : public QDeclarativeValueType
{
    Q_OBJECT
    Q_ENUMS(FontWeight)
    Q_ENUMS(Capitalization)

    Q_PROPERTY(QString family READ family WRITE setFamily)
    Q_PROPERTY(bool bold READ bold WRITE setBold)
    Q_PROPERTY(FontWeight weight READ weight WRITE setWeight)
    Q_PROPERTY(bool italic READ italic WRITE setItalic)
    Q_PROPERTY(bool underline READ underline WRITE setUnderline)
    Q_PROPERTY(bool overline READ overline WRITE setOverline)
    Q_PROPERTY(bool strikeout READ strikeout WRITE setStrikeout)
    Q_PROPERTY(qreal pointSize READ pointSize WRITE setPointSize)
    Q_PROPERTY(int pixelSize READ pixelSize WRITE setPixelSize)
    Q_PROPERTY(Capitalization capitalization READ capitalization WRITE setCapitalization)
    Q_PROPERTY(qreal letterSpacing READ letterSpacing WRITE setLetterSpacing)
    Q_PROPERTY(qreal wordSpacing READ wordSpacing WRITE setWordSpacing)

public:
    enum FontWeight { Light = QFont::Light,
                       Normal = QFont::Normal,
                       DemiBold = QFont::DemiBold,
                       Bold = QFont::Bold,
                       Black = QFont::Black };
    enum Capitalization { MixedCase = QFont::MixedCase,
                           AllUppercase = QFont::AllUppercase,
                           AllLowercase = QFont::AllLowercase,
                           SmallCaps = QFont::SmallCaps,
                           Capitalize = QFont::Capitalize };

    QDeclarativeFontValueType(QObject *parent = 0);

    virtual void read(QObject *, int);
    virtual void write(QObject *, int, QDeclarativePropertyPrivate::WriteFlags);
    virtual QVariant value();
    virtual void setValue(QVariant value);

    QString family() const;
    void setFamily(const QString &);

    bool bold() const;
    void setBold(bool b);

    FontWeight weight() const;
    void setWeight(FontWeight);

    bool italic() const;
    void setItalic(bool b);

    bool underline() const;
    void setUnderline(bool b);

    bool overline() const;
    void setOverline(bool b);

    bool strikeout() const;
    void setStrikeout(bool b);

    qreal pointSize() const;
    void setPointSize(qreal size);

    int pixelSize() const;
    void setPixelSize(int size);

    Capitalization capitalization() const;
    void setCapitalization(Capitalization);

    qreal letterSpacing() const;
    void setLetterSpacing(qreal spacing);

    qreal wordSpacing() const;
    void setWordSpacing(qreal spacing);

private:
    QFont font;
    bool hasPixelSize;
};

QT_END_NAMESPACE

#endif  // QDECLARATIVEVALUETYPE_P_H