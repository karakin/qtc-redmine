#pragma once

#include "redmine_global.h"

#include <extensionsystem/iplugin.h>
#include <coreplugin/id.h>

namespace Redmine {
namespace Internal {

class RedmineMode;
class RedmineOptionsPage;

class RedmineManager;

class RedminePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Redmine.json")

public:
    RedminePlugin();
    ~RedminePlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void initLanguage();
    void initOptionsPage();

private:
    RedmineMode *m_mode;
    RedmineOptionsPage *m_optionsPage;
    RedmineManager *m_redmineManager;


private slots:
    void triggerAction();
    void modeChanged( Core::Id mode, Core::Id old );
};

} // namespace Internal
} // namespace Redmine
