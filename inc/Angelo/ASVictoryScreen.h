#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include <QDialog>

namespace Ui {
class VictoryScreen;
}

class VictoryScreen : public QDialog
{
    Q_OBJECT

public:
    explicit VictoryScreen(QWidget *parent = 0);
    ~VictoryScreen();

    void display();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::VictoryScreen *ui;
};

#endif // VICTORYSCREEN_H
