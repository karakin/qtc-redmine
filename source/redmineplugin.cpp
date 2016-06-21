#include "redmineplugin.h"
#include "redmineconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QDebug>

#include <QtPlugin>

#include <QTranslator>

using namespace Redmine::Internal;

RedminePlugin::RedminePlugin()
{
    // Create your members
}

RedminePlugin::~RedminePlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool RedminePlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    initLanguage();

    QAction *action = new QAction(tr("Redmine Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("Redmine"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void RedminePlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag RedminePlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void RedminePlugin::initLanguage()
{
    const QString &language = Core::ICore::userInterfaceLanguage();

    if( language.isEmpty() )
        return;

    QStringList paths = QStringList() << Core::ICore::resourcePath ()
                                      << Core::ICore::userResourcePath();

    const QString &trFile = QLatin1String( QString( "redmine_" ).arg( language ) );
    QTranslator *translator = new QTranslator( this );
    foreach( const QString& path, paths )
    {
        if (translator->load( trFile, path + QLatin1String ("/translations") ) )
        {
            qApp->installTranslator( translator );
            break;
        }
    }
}

void RedminePlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from Redmine."));
}
