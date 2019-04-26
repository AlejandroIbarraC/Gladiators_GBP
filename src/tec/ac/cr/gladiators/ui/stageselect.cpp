#include "stageselect.h"
#include "ui_stageselect.h"

StageSelect::StageSelect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StageSelect)
{
    ui->setupUi(this);
}

void StageSelect::on_fieldButton_clicked() {
    toField(1);
    hide();
}

void StageSelect::on_cityButton_clicked() {
    toField(2);
    hide();
}

void StageSelect::toField(int stage) {
    field = new Field(this, stage);
    field->show();
}

StageSelect::~StageSelect()
{
    delete ui;
}
