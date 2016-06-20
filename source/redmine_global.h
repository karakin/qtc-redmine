#pragma once

#include <QtGlobal>

#if defined(REDMINE_LIBRARY)
#  define REDMINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define REDMINESHARED_EXPORT Q_DECL_IMPORT
#endif
