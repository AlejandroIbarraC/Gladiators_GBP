#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent, int stage) :
    QMainWindow(parent),
    ui(new Ui::Field)
{
    ui->setupUi(this);

    // Width and height of window.
    int width = 1000;
    int height = 800;

    // Connects designer UI with programatically added UI elements.
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width, height);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setFixedSize(width, height);


    // Initialize background stage
    if (stage == 1) {
        ui->background->setPixmap(QPixmap("://main/fieldStage.png"));
        columns = 19;
        rows = 11;
    } else {
        ui->background->setPixmap(QPixmap("://main/cityStage.jpg"));
        columns = 19;
        rows = 11;
    }

    // Plays music.
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/main/mainTheme.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer* background_music = new QMediaPlayer();
    background_music->setMedia(playlist);
    background_music->play();

    // Initialiaze Field with default grid.
    initializeField();
}

void Field::initializeField() {
    QRectF rect(0,0,42,42);
    double xpos = 0;
    double ypos = 0;
    bool isOpaque = false;
    QBrush clearBrush = QBrush(QColor(5, 5, 5, 25));
    QBrush opaqueBrush = QBrush(QColor(128, 128, 128, 100));

    for(int i = 0; i < columns; i++) {
        for (int i = 0; i < rows; i++) {
            QGraphicsRectItem *item = new QGraphicsRectItem(rect);
            if (isOpaque) {
                item->setBrush(opaqueBrush);
                isOpaque = false;
            } else {
                item->setBrush(clearBrush);
                isOpaque = true;
            }
            //item->setPen(Qt::NoPen);
            allSquares.append(item);
            scene->addItem(item);
            item->setPos(xpos, ypos);
            ypos += 42;
        }
        xpos += 42;
        ypos = 0;
    }

    xpos = 100;
    ypos = 530;

    for(int i = 0; i < 4; i++) {
        DraggableRectItem* dItem = new DraggableRectItem();
        scene->addItem(dItem);
        dItem->setBrush(Qt::black);
        dItem->setRect(rect);
        dItem->setPos(xpos,ypos);
        dItem->setAcceptDrops(true);
        xpos += 120;
        dItem->setAnchorPoint(dItem->pos());
    }
}

Field::~Field()
{
    delete ui;
}
