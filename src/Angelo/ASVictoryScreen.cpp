#include "victoryscreen.h"
#include "ui_victoryscreen.h"

VictoryScreen::VictoryScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VictoryScreen)
{
    ui->setupUi(this);
}

VictoryScreen::~VictoryScreen()
{
    delete ui;
}

void VictoryScreen::on_pushButton_clicked() //return
{

}

void VictoryScreen::on_pushButton_2_clicked() //exit
{
    exit( EXIT_SUCCESS );
}

void VictoryScreen::display()
{
    VictoryScreen screen;
    screen.setModal(true);
    screen.exec();
}

