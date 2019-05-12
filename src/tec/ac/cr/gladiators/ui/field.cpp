#include "field.h"
#include "ui_field.h"
#include "/home/jose/CLionProjects/Gladiators_GBP/src/tec/ac/cr/gladiators/logic/GladiatorsList.h"
#include "iostream"
#include <QString>

using namespace std;


Field* Field::field = nullptr;

//! A method that creates the field window
//! \param parent
//! \param stage
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

    // Initialiaze Field with default grid and starts game.
    initializeField();
    game = Game::getInstance();
    game->run();
}

//! A method that undulls grid
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

//! A method that reduces player life
void Field::lowerLife() {
    life --;
    ui->lifeLabel->setText("Life: " + QString::number(life));
}

Field* Field::getInstance() {
    return field;
}

QGraphicsScene* Field::getScene() {
    return this->scene;
}

QGraphicsScene* Field::getSoldierScene() {
    return this->soldier_scene;
}
//! A method that Initializes field with default attributes.

void Field::initializeField() {
    // Grid icons.
    QRectF rect(0,0,40,40);
    double xpos = startingx;
    double ypos = startingy;
    bool isOpaque = false;

    for(int i = 0; i < rows; i++) {
        for (int i = 0; i < columns; i++) {
            CustomRectItem* item = new CustomRectItem();
            item->setRect(rect);
            item->setPen(Qt::NoPen);
            allSquares.append(item);
            item->setID(allSquares.length());
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

//! A method that is run when play button is clicked
void Field::on_playButton_clicked() {
    QList<int>* path = new QList<int>();
    path->append(95);
    path->append(96);
    path->append(97);
    path->append(98);
    path->append(117);
    path->append(136);
    path->append(155);
    path->append(174);
    path->append(175);
    path->append(176);
    path->append(177);
    path->append(178);
    path->append(179);
    path->append(160);
    path->append(141);
    path->append(122);
    game->createArmy(3);
    game->setPath(path);
}

//! A method that dulls grid
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

void Field::setSoldierScene(QGraphicsScene* newScene) {
    soldier_scene = newScene;
}

Field::~Field()
{
    delete ui;
}

//! A method that shows in labels the attributes from the selected soldier
void Field::setSoldierLabels() {

    GladiatorsList* gladiatorsList = GladiatorsList::getInstance();

    int age = gladiatorsList->soldierToShow->getAge();
    QString Age = QString::number(age);
    ui->SoldierAge->setText(Age);

    int probability = gladiatorsList->soldierToShow->getSurvivalProbability();
    QString Probability = QString::number(probability);
    ui->SoldierSurvivalProbability->setText(Probability);

    int gensToSurvive = gladiatorsList->soldierToShow->getHowManyGensWillSurvive();
    QString GensToSurvive = QString::number(gensToSurvive);
    ui->SoldierHowManyGensWillSurvive->setText(GensToSurvive);

    int emotionInteligence = gladiatorsList->soldierToShow->getEmotionalInteligence();
    QString EmotionInteligence = QString::number(emotionInteligence);
    ui->SoldierEmotionalInteligence->setText(EmotionInteligence);

    int physicalCondition = gladiatorsList->soldierToShow->getPhysicalCondition();
    QString PhysicalCondition = QString::number(physicalCondition);
    ui->SoldierPhysicalCondition->setText(PhysicalCondition);

    int resistence = gladiatorsList->soldierToShow->getResistence();
    QString Resistence = QString::number(resistence);
    ui->SoldierPhysicalCondition->setText(Resistence);
}
