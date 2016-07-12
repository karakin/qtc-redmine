#ifndef REDMINEMANAGER_H
#define REDMINEMANAGER_H

#include <QObject>

QT_FORWARD_DECLARE_CLASS(QNetworkReply)


namespace Redmine {
namespace Internal {

class RedminePlugin;



class RedmineManager : QObject
{
    Q_OBJECT
public:
    static RedmineManager *instance();


private:
    RedmineManager( QObject *parent = 0 );
    ~RedmineManager();



    friend class RedminePlugin;
};

} // namespace Internal
} // namespace Redmine

#endif // REDMINEMANAGER_H
