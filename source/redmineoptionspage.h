#ifndef REDMINEOPETIONSPAGE_H
#define REDMINEOPETIONSPAGE_H

#include <QPointer>
#include <coreplugin/dialogs/ioptionspage.h>

namespace Redmine {
namespace Internal {

class RedmineConfigWidget;

class RedmineOptionsPage : public Core::IOptionsPage
{
public:
    RedmineOptionsPage( QObject *parent = 0 );

    // IOptionsPage interface
    QWidget *widget();
    void apply();
    void finish();

private:
    QPointer<RedmineConfigWidget> m_configWidget;

};

} // namespace Internal
} // namespace Redmine

#endif // REDMINEOPETIONSPAGE_H
