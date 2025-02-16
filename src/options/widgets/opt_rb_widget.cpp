/****************************************************************************
** RbWidget implementation
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

#include "help/help_context.h"
#include "help/help_urls.h"
#include "options/widgets/opt_rb_widget.h"
#include "options/vk_option.h"
#include "utils/vk_utils.h"

#include <QRadioButton>
#include <QCompleter>
#include <QHBoxLayout>
#include <QWidget>
#include <QString>


/***************************************************************************/
/*!
    Constructs a RbWidget object
    has-a QRadioButton
*/
RbWidget::RbWidget( QWidget* parent, VkOption* vkopt, bool mklabel )
   : OptionWidget( parent, vkopt, mklabel )
{
   this->setObjectName( "rb_widget" );

   m_radio   = new QRadioButton( parent );
   m_widg    = m_radio;
   
   m_radio->setText(m_opt->shortHelp);
   m_radio->setChecked( strToBool(m_initialValue) );

   connect( m_radio, SIGNAL(   toggled( bool ) ),
            this,      SLOT( rbToggled( bool ) ) );
            
   // not added if the url is empty
   ContextHelp::addHelp( m_widg, m_opt->urlAddress );
}


/*!
    Destroys this widget, and frees any allocated resources.
*/
RbWidget::~RbWidget()
{
   if ( m_radio ) {
      delete m_radio;
      m_radio = 0;
   }
}


void RbWidget::rbToggled( bool checked )
{
   setCurrValue( m_opt->possValues[ (checked ? 0 : 1) ] );

   // for dis/enabling associated widgets
   emit changed( checked );
}

/*!
  txt value translated to boolean to check box.
  only updates if value valid 'boolean' string
*/
void RbWidget::update( const QString& txt )
{
   bool ok;
   bool checked = strToBool( txt, &ok );
   if ( ok ) {
      m_radio->setChecked( checked );
      // toggled signal sent -> calls rbToggled()
   }
}


QHBoxLayout* RbWidget::hlayout()
{
   vk_assert( m_wLabel != 0 );
   
   m_hBox = new QHBoxLayout();
   m_hBox->addWidget( m_wLabel );
   m_hBox->addWidget( m_widg );
   m_hBox->setStretchFactor( m_wLabel, 6 );
   m_hBox->setStretchFactor( m_widg,   2 );
   
   return m_hBox;
}
