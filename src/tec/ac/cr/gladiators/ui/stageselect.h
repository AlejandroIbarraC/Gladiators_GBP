#ifndef STAGESELECT_H
#define STAGESELECT_H

#include <QMainWindow>
#include <QFontDatabase>

#include "field.h"
#include "elements/buttonhoverwatcher.h"

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
    void on_fieldButton_clicked();
    void on_cityButton_clicked();
};

#endif // STAGESELECT_H
