#ifndef REDMINEICONS_H
#define REDMINEICONS_H

#include <utils/icon.h>

namespace Redmine {
namespace Icons {

    const Utils::Icon MODE_REDMINE_CLASSIC( QLatin1String( ":/redmine/images/mode_redmine.png" ) );
    const Utils::Icon MODE_REDMINE_FLAT({
            {QLatin1String( ":/redmine/images/mode_redmine_mask.png" ), Utils::Theme::IconsBaseColor}});
    const Utils::Icon MODE_REDMINE_FLAT_ACTIVE({
            {QLatin1String( ":/redmine/images/mode_redmine_mask.png" ), Utils::Theme::IconsErrorColor}});

} // namespace Icons
} // namespace Redmine

#endif // REDMINEICONS_H
