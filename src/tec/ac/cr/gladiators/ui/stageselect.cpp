#include "stageselect.h"
#include "ui_stageselect.h"

//! The main method to create the StageSelect window
//! \param parent

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

//! A method that hides the StageSelect window
void StageSelect::on_fieldButton_clicked() {
    toField(1);
    QString ip = ui->ipEntry->text();
    if (ip != "") {

    }
    hide();
}

//! A method that hides the StageSelect window
void StageSelect::on_cityButton_clicked() {
    toField(2);
    QString ip = ui->ipEntry->text();
    if (ip != "") {

    }
    hide();
}

//! A method that opens the field selected
//! \param stage
void StageSelect::toField(int stage) {
    field = new Field(this, stage);
    field->show();
    field->setInstance(field);
}

StageSelect::~StageSelect()
{
    delete ui;
}
