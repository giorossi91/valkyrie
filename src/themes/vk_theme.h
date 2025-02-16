/****************************************************************************
** VkTheme definition
** --------------------------------------------------------------------------
**
** Copyright (C) 2000-2011, OpenWorks LLP. All rights reserved.
** <info@open-works.co.uk>
**
** This file is part of Valkyrie, a front-end for Valgrind.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file COPYING included in the packaging of
** this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef __VK_THEME_H
#define __VK_THEME_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QMap>

class VkTheme : public QObject
{
    Q_OBJECT
public:
    VkTheme();
    virtual ~VkTheme();

    void addElementColor(const QString &key, const QColor& color);
    QColor getElementColor(const QString &key) const;

private:
    QMap<QString, QColor> m_colorMap;

    VkTheme(VkTheme&) = delete;
    VkTheme& operator=(VkTheme&) = delete;
};


#endif // #ifndef __VK_THEME_H
