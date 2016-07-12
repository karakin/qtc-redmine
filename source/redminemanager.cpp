#include "redminemanager.h"

#include "utils/qtcassert.h"


using namespace Redmine::Internal;

static RedmineManager *m_instance = 0;

RedmineManager *RedmineManager::instance()
{
    Q_ASSERT(m_instance);
    return m_instance;
}


RedmineManager::RedmineManager(QObject *parent) :
    QObject( parent )
{
    QTC_CHECK(!m_instance);
    m_instance = this;
}

RedmineManager::~RedmineManager()
{
    m_instance = 0;
}
