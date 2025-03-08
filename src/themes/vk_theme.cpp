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

#include "themes/vk_theme.h"
#include "utils/vk_utils.h"

VkTheme::VkTheme()
{
}

VkTheme::~VkTheme()
{
    m_colorMap.clear();
}

void VkTheme::addElementColor(const QString &key, const QColor& color)
{
    vk_assert(color.isValid());

    m_colorMap[key] = color;
}

QColor VkTheme::getElementColor(const QString &key) const
{
    return m_colorMap.value(key);
}
