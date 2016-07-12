#include "redmineplugin.h"
#include "redmineconstants.h"

#include "redminemode.h"
#include "redmineoptionspage.h"

#include "redminemanager.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <coreplugin/modemanager.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

#include <QDebug>

#include <QtPlugin>

#include <QTranslator>

using namespace Redmine::Internal;

RedminePlugin::RedminePlugin() :
    m_mode( 0 ),
    m_redmineManager( new RedmineManager )
{
}

RedminePlugin::~RedminePlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
    delete m_redmineManager;
    m_redmineManager = 0;
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
    initOptionsPage();

    QAction *action = new QAction(tr("Redmine Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("Redmine"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    m_mode = new RedmineMode;
    m_mode->setWidget( new QWidget );
    addAutoReleasedObject( m_mode );

    connect( Core::ModeManager::instance(), SIGNAL(currentModeChanged(Core::Id,Core::Id)), SLOT(modeChanged(Core::Id,Core::Id)) );

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

    const QString &trFile = QLatin1String( "redmine_" ) + language;
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

void RedminePlugin::initOptionsPage()
{
    m_optionsPage = new RedmineOptionsPage;
    addAutoReleasedObject( m_optionsPage );
}

void RedminePlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             tr("This is an action from Redmine."));
}

void RedminePlugin::modeChanged(Core::Id mode, Core::Id old)
{
    Q_UNUSED(old)
    if (mode == m_mode->id()) {
    }
}
