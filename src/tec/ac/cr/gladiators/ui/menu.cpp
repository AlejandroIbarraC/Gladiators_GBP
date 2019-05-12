#include "menu.h"
#include "ui_menu.h"

//! The main method to create the Menu window
//! \param parent
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ButtonHoverWatcher* watcher = new ButtonHoverWatcher(this,":/main/playButton.png",":/main/playButton_pressed.png");
    ui->playButton->installEventFilter(watcher);
    QFontDatabase::addApplicationFont(":/font/Papyrus.ttc");
}

//! A method that goes to the field selected
void Menu::toStageSelect() {
    stageSelect = new StageSelect(this);
    stageSelect->show();
}

//! A method that opens the field and hides the stage select window
void Menu::on_playButton_clicked() {
    toStageSelect();
    hide();
}

Menu::~Menu()
{
    delete ui;
}
