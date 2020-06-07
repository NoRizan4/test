#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void GetTowerPos();
    friend class TowerPos;
private:
    Ui::MainWindow *ui;
    QList<TowerPos> t_towerPossList;

};
#endif // MAINWINDOW_H
