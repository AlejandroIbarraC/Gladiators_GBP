#include "stageselect.h"
#include "ui_stageselect.h"

StageSelect::StageSelect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StageSelect)
{
    ui->setupUi(this);
    ButtonHoverWatcher* fieldWatcher = new ButtonHoverWatcher(this,":/main/fieldButton.png",":/main/fieldButton_pressed.png");
    ButtonHoverWatcher* cityWatcher = new ButtonHoverWatcher(this,":/main/cityButton.png",":/main/cityButton_pressed.png");
    ui->fieldButton->installEventFilter(fieldWatcher);
    ui->cityButton->installEventFilter(cityWatcher);
    ui->selectLabel->setFont(QFont("Papyrus", 35));
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
    field->setInstance(field);
}

StageSelect::~StageSelect()
{
    delete ui;
}
