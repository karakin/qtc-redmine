#include "redmineoptionspage.h"
#include "redmineconstants.h"

#include "redmineconfigwidget.h"

#include <utils/qtcassert.h>

using namespace Redmine;
using namespace Redmine::Internal;

RedmineOptionsPage::RedmineOptionsPage(QObject *parent) :
    Core::IOptionsPage( parent ),
    m_configWidget( 0 )
{
    setId( Constants::REDMINE_SETTINGS_PAGE_ID );
    setDisplayName( tr("Connection") );
    setCategory( Constants::REDMINE_SETTINGS_CATEGORY );
    setDisplayCategory( tr("Redmine") );
    setCategoryIcon( QLatin1String( Constants::REDMINE_CATEGORY_ICON ) );
}

QWidget *RedmineOptionsPage::widget()
{
    if( !m_configWidget )
        m_configWidget = new RedmineConfigWidget;

    return m_configWidget;
}

void RedmineOptionsPage::apply()
{
    QTC_ASSERT(m_configWidget, return);
}

void RedmineOptionsPage::finish()
{
    delete m_configWidget;
    m_configWidget = 0;
}
