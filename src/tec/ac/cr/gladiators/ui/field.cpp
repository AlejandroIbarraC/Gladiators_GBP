#include "field.h"
#include "ui_field.h"

Field* Field::field = nullptr;

Field::Field(QWidget *parent, int stage) :
    QMainWindow(parent),
    ui(new Ui::Field)
{
    ui->setupUi(this);

    // Width and height of window.
    int width = 1000;
    int height = 800;
    currentStage = stage;

    // Connects designer UI with programatically added UI elements.
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,width, height);
    view = ui->graphicsView;
    view->setScene(scene);
    view->setFixedSize(width, height);
    soldier_scene = new QGraphicsScene(this);
    soldier_scene->setSceneRect(0,0,width, height);
    soldier_view = ui->soldierView;
    soldier_view->setScene(soldier_scene);
    soldier_view->setFixedSize(width, height);

    // Initialize background stage
    if (stage == 1) {
        ui->background->setPixmap(QPixmap("://main/fieldStage.png"));
        columns = 19;
        rows = 11;
        startingx = 125;
        startingy = 75;
    } else {
        ui->background->setPixmap(QPixmap("://main/cityStage.jpg"));
        columns = 17;
        rows = 8;
        startingx = 55;
        startingy = 84;
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

/// Animates soldier through path at a specific speed.
/// @param soldier
/// @param path QList of path that follows
/// @param speed
void Field::animateSoldier(Soldier* soldier, QList<int>* path, int speed) {
    QSize size = QSize(15, 15);
    QPoint start = QPoint(100, 350);
    QPoint end;
    int duration = speed * 100;

    // Creates animation.
    QPropertyAnimation* animation = new QPropertyAnimation(soldier, "geometry");
    animation->setDuration(duration);

    // Controls individual movement of soldier through path.
    for(int i = 0; i < path->length(); i++) {
        int currentID = path->at(i);
        end.setX(allSquares[currentID]->x() + 13);
        end.setY(allSquares[currentID]->y() + 13);
        animation->setStartValue(QRect(start, size));
        animation->setEndValue(QRect(end, size));
        animation->start();
        start.setX(end.x());
        start.setY(end.y());
        delay(duration + 15);
    }
}

/// Delays GUI without stopping thread.
/// @param ms int miliseconds to delay
void Field::delay(int ms) {
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        update();
    }
}

/// Deopaques grid
void Field::deOpaqueGrid() {
    int dimensions = rows * columns;
    for (int i = 0; i < dimensions; i++) {
        QGraphicsRectItem* currentSquare = allSquares[i];
        if (!currentSquare->acceptDrops()) {
            currentSquare->setBrush(QBrush(QColor(0, 0, 0, 0)));
        }
    }
}

void Field::generateArmy(int amount, QList<int>* path) {
    for(int i = 0; i < amount; i++) {
        Soldier* player = new Soldier(nullptr);
        soldier_scene->addItem(player);
        animateSoldier(player, path, 20);
    }
}

Field* Field::getInstance() {
    return field;
}

/// Initializes field with default attributes.
void Field::initializeField() {
    // Grid icons.
    QRectF rect(0,0,40,40);
    double xpos = startingx;
    double ypos = startingy;
    bool isOpaque = false;

    for(int i = 0; i < rows; i++) {
        for (int i = 0; i < columns; i++) {
            QGraphicsRectItem* item = new QGraphicsRectItem(rect);
            item->setPen(Qt::NoPen);
            allSquares.append(item);
            scene->addItem(item);
            item->setPos(xpos, ypos);
            xpos += 42;
        }
        if (currentStage == 2) {
            if (isOpaque) {
                isOpaque = false;
            } else {
                isOpaque = true;
            }
        }
        ypos += 42;
        xpos = startingx;
    }

    // Draggable tower icons.
    QRectF dRect(0,0,70,70);
    xpos = 200;
    ypos = 600;
    QStringList* towerTypes = new QStringList;
    towerTypes->append("gatling");
    towerTypes->append("fire");
    towerTypes->append("electric");

    for(int i = 0; i < 3; i++) {
        DraggableRectItem* dItem = new DraggableRectItem(nullptr, towerTypes->at(i));
        scene->addItem(dItem);
        dItem->setRect(dRect);
        dItem->setPos(xpos,ypos);
        xpos += 120;
        dItem->setPen(Qt::NoPen);
        dItem->setAnchorPoint(dItem->pos());
    }
}

void Field::on_playButton_clicked() {
    QList<int>* path = new QList<int>();
    path->append(10);
    path->append(21);
    path->append(30);
    //generateArmy(20, path);
    Soldier* soldier = new Soldier();
    soldier_scene->addItem(soldier);
    animateSoldier(soldier, path, 5);
}

/// Opaques grid.
void Field::opaqueGrid() {
    bool opaque = true;
    int dimensions = rows * columns;
    QBrush clearBrush = QBrush(QColor(8, 8, 8, 30));
    QBrush opaqueBrush = QBrush(QColor(80, 80, 80, 120));
    QBrush currentBrush;
    for (int i = 0; i < dimensions; i++) {
        QGraphicsRectItem* currentSquare = allSquares[i];
        if (opaque) {
            currentBrush = opaqueBrush;
            opaque = false;
        } else {
            currentBrush = clearBrush;
            opaque = true;
        }
        if (!currentSquare->acceptDrops()) {
            currentSquare->setBrush(currentBrush);
        }
    }
}

void Field::setInstance(Field* nfield) {
    field = nfield;
}

Field::~Field()
{
    delete ui;
}
