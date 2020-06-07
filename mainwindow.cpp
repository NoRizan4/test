#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap(":/"));
    //foreach (Tower *tower, m_towersList)
    //tower->draw(&painter);
}


class TowerPos// 塔的位置
{
public:
    TowerPos(QPoint pos, const QPixmap &sprite /*= QPixmap(":/")*/);
    const QPoint centerPos() const;
    bool hasPoint(const QPoint &pos) const;
    bool hasTower() const;
    void sethasTower(bool hasTower=true);
    void draw(QPainter *painter) const;

private:
    QPoint		t_pos;
    bool		t_hasTower;
    QPixmap		t_sprite;
    static const QSize fixedSize;
};

const QSize TowerPos::fixedSize(44, 44);

TowerPos::TowerPos(QPoint pos, const QPixmap &sprite/* = QPixmap(":/")*/): t_pos(pos), t_hasTower(false), t_sprite(sprite){}

const QPoint TowerPos::centerPos() const
{
    QPoint offsetPoint(fixedSize.width()/2, fixedSize.height()/2);
    return t_pos+offsetPoint;
}

bool TowerPos::hasPoint(const QPoint &pos) const
{
    bool IsXinhere = t_pos.x()<pos.x() && pos.x()<(t_pos.x()+fixedSize.width());
    bool IsYinhere = t_pos.y()<pos.y() && pos.y()<(t_pos.y()+fixedSize.height());
    return IsXinhere && IsYinhere;
}

bool TowerPos::hasTower() const
{
    return t_hasTower;
}

void TowerPos::sethasTower(bool hasTower)
{
    t_hasTower = hasTower;
}

void TowerPos::draw(QPainter *painter) const
{
    painter -> drawPixmap(t_pos.x(), t_pos.y(), t_sprite);
}


void MainWindow::GetTowerPos()
{
    QPoint pos[]=
    {
        QPoint(65, 220),
        QPoint(125, 220),
        QPoint(185, 220),

        QPoint(100, 125),
        QPoint(165, 125),
        QPoint(225, 125),

        QPoint(80, 35),
        QPoint(140, 35),
        QPoint(200, 35),

    };
    int num=sizeof(pos)/sizeof(pos[0]);
    for (int i = 0; i < num; ++i) t_towerPossList.push_back(pos[i]);
}


