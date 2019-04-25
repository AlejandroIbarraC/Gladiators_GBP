#ifndef FIELD_H
#define FIELD_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>

namespace Ui {
class Field;
}

class Field : public QMainWindow
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr, int stage = 1);
    ~Field();

private:
    Ui::Field *ui;
};

#endif // FIELD_H
