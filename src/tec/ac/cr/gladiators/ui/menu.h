#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

#include "stageselect.h"

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;
    StageSelect* stageSelect;
    void toStageSelect();

private slots:
    void on_playButton_clicked();
};

#endif // MENU_H
