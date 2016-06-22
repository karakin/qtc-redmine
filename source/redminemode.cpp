#include "redminemode.h"
#include "redmineconstants.h"
#include "redmineicons.h"

#include "redminemode.h"

#include <QCoreApplication>

using namespace Redmine;
using namespace Redmine::Internal;


RedmineMode::RedmineMode(QObject *parent) :
    Core::IMode( parent )
{
    setObjectName( QLatin1String( "RedmineMode" ) );
    setContext( Core::Context( Constants::C_MODE_REDMINE ) );
    setIcon( Utils::Icon::modeIcon( Icons::MODE_REDMINE_CLASSIC, Icons::MODE_REDMINE_FLAT, Icons::MODE_REDMINE_FLAT_ACTIVE ) );
    setDisplayName( QCoreApplication::translate("Redmine::Internal::RedmineMode", "Redmine") );
    setPriority( Constants::P_MODE_REDMINE );
    setId( Constants::ID_MODE_REDMINE );
}
