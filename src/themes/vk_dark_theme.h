/****************************************************************************
** VkDarkTheme definition
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

#ifndef __VK_DARK_THEME_H
#define __VK_DARK_THEME_H

#include "themes/vk_theme.h"
#include "utils/vk_config.h"

class VkDarkTheme : public VkTheme
{
    Q_OBJECT
public:
    VkDarkTheme(const VkCfgGlbl * const vkConfig)
    {
        addElementColor("colour_background"     , vkConfig->value( "colour_dark_background"      ).value<QColor>());
        addElementColor("colour_base"           , vkConfig->value( "colour_dark_base"            ).value<QColor>());
        addElementColor("colour_text"           , vkConfig->value( "colour_dark_text"            ).value<QColor>());
        addElementColor("colour_dkgray"         , vkConfig->value( "colour_dark_dkgray"          ).value<QColor>());
        addElementColor("colour_highlight"      , vkConfig->value( "colour_dark_highlight"       ).value<QColor>());
        addElementColor("colour_view_background", vkConfig->value( "colour_dark_view_background" ).value<QColor>());
        addElementColor("colour_view_text"      , vkConfig->value( "colour_dark_view_text"       ).value<QColor>());

        addElementColor("frame_expandable_foreground"   , QColor(  59, 155, 235));
        addElementColor("frame_notexpandable_foreground", QColor( 186,  44,  44));
        addElementColor("src_item_background"           , QColor(  60,  60,  60));
    }
    ~VkDarkTheme() = default;
};


#endif // #ifndef __VK_VALGRIND_THEME_H
