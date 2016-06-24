#ifndef REDMINECONFIGWIDGET_H
#define REDMINECONFIGWIDGET_H

#include <QWidget>

namespace Redmine {
namespace Internal {


namespace Ui {
class RedmineConfigWidget;
}

class RedmineConfigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RedmineConfigWidget(QWidget *parent = 0);
    ~RedmineConfigWidget();

private:
    Ui::RedmineConfigWidget *ui;
};

} // namespace Internal
} // namespace Redmine

#endif // REDMINECONFIGWIDGET_H
