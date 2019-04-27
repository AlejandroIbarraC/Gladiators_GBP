#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ButtonHoverWatcher* watcher = new ButtonHoverWatcher(this,":/main/playButton.png",":/main/playButton_pressed.png");
    ui->playButton->installEventFilter(watcher);
    QFontDatabase::addApplicationFont(":/font/Papyrus.ttc");
}

void Menu::toStageSelect() {
    stageSelect = new StageSelect(this);
    stageSelect->show();
}

void Menu::on_playButton_clicked() {
    toStageSelect();
    hide();
}

Menu::~Menu()
{
    delete ui;
}
