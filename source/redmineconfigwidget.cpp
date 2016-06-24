#include "redmineconfigwidget.h"
#include "ui_redmineconfigwidget.h"

using namespace Redmine::Internal;

RedmineConfigWidget::RedmineConfigWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RedmineConfigWidget)
{
    ui->setupUi(this);
}

RedmineConfigWidget::~RedmineConfigWidget()
{
    delete ui;
}

