#ifndef REDMINEMODE_H
#define REDMINEMODE_H

#include <coreplugin/imode.h>

namespace Redmine {
namespace Internal {

class RedmineMode : public Core::IMode
{
public:
    RedmineMode( QObject *parent = 0 );
};

} // namespace Internal
} // namespace Redmine

#endif // REDMINEMODE_H
