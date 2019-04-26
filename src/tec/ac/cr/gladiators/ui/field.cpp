#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent, int stage) :
    QMainWindow(parent),
    ui(new Ui::Field)
{
    ui->setupUi(this);

    // Initialize background stage
    if (stage == 1) {
        ui->background->setPixmap(QPixmap("://main/fieldStage.png"));
    } else {
        ui->background->setPixmap(QPixmap("://main/cityStage.jpg"));
    }

    // Plays musica and sets sound effects.
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/main/mainTheme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer* background_music = new QMediaPlayer();
    background_music->setMedia(playlist);
    background_music->play();
}

Field::~Field()
{
    delete ui;
}
