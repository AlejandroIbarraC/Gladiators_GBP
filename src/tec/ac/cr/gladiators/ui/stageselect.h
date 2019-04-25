#ifndef STAGESELECT_H
#define STAGESELECT_H

#include <QMainWindow>

#include "field.h"

namespace Ui {
class StageSelect;
}

class StageSelect : public QMainWindow
{
    Q_OBJECT

public:
    explicit StageSelect(QWidget *parent = nullptr);
    ~StageSelect();

private:
    Ui::StageSelect *ui;
    Field* field;
    void toField(int stage);

private slots:
    void on_stage1Button_clicked();
    void on_stage2Button_clicked();
};

#endif // STAGESELECT_H
