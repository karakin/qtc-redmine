#pragma once

#include "redmine_global.h"

#include <extensionsystem/iplugin.h>

namespace Redmine {
namespace Internal {

class RedmineMode;
class RedmineOptionsPage;

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

private slots:
    void triggerAction();
};

} // namespace Internal
} // namespace Redmine
