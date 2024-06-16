#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QApplication>
#include <QLayout>
#include <QPushButton>
#include <QMouseEvent>
#include <QMenu>
#include <QMenuBar>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QGridLayout>
#include <QCursor>

/*class checkeredBrush : public QPainter{
    Q_OBJECT
    checkeredBrush(QPainter *parent = NULL) : QPainter(parent){
    public:
        QPainter *painter();
    }
    void checkeredBrush::drawCheckered(int x, int y, int size){

    }
};*/
class drawingScene : public QWidget{
    Q_OBJECT
public:
    drawingScene(QWidget *parent = NULL) : QWidget(parent){

    }
};
class pixeleditor : public QMainWindow{
    Q_OBJECT //Schlüssel für Kompiler: Einschließen von allem aus QObject
public:
    pixeleditor(QWidget *parent = NULL) : QMainWindow(parent){
        this->resize(400,300);
        this->setWindowTitle("PixelEditor");
        cursor = new QCursor();
        currentPos = new QPoint(QCursor::pos());

        px_x = 32.0;
        px_y = 32.0;
        px_size = 5.0;
        px = new QRectF(0.0,0.0,0.0,0.0);
        layout1 = new QHBoxLayout();
        layout2 = new QVBoxLayout();
        scene = new QGraphicsScene();
        brush1 = new QBrush();
        brush2 = new QBrush();
        pen = new QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
        brush1->setColor(Qt::darkGray);
        brush1->setStyle(Qt::SolidPattern);
        brush2->setColor(Qt::darkGreen);
        brush2->setStyle(Qt::SolidPattern);
        scene->setSceneRect(0,0,0,0);
        sceneView = new QGraphicsView(scene);
        sceneView->setMaximumSize(px_x*px_size+px_size,px_y*px_size+px_size);
        sceneView->setBackgroundBrush(Qt::gray);
        /*for(auto i = 0; i < px_x; i++){ //checkered pattern test
            for(auto j = 0; j < px_y; j++){
                px = new QRectF(i*px_size, j*px_size, px_size, px_size);
                if(i%2==0 && j%2==0 || i%2!=0 && j%2!=0){
                    scene->addRect(i*px_size, j*px_size, 1*px_size, 1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::darkGreen, Qt::SolidPattern));
                }
                else{
                    scene->addRect(i*px_size, j*px_size, 1*px_size, 1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::darkGray, Qt::SolidPattern));
                }
                this->update();
            }
        }*/

        bar = menuBar();
        menu = bar->addMenu(tr("&Datei"));
        action1 = new QAction("&Neue Datei", this);
        action2 = new QAction("&Datei laden", this);
        action3 = new QAction("&Speichern", this);
        action4 = new QAction("&Speichern unter...", this);
        action5 = new QAction("&Beenden", this);
        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        menu->addAction(action4);
        menu->addAction(action5);
        layoutWidget = new QWidget();
        layoutWidget->setLayout(layout1);
        setCentralWidget(layoutWidget);
        layout1->addWidget(sceneView);
        layout1->addLayout(layout2);
        QObject::connect(action1, &QAction::triggered, this, &pixeleditor::newFile);
        QObject::connect(action2, &QAction::triggered, this, &pixeleditor::load);
        QObject::connect(action3, &QAction::triggered, this, &pixeleditor::save);
        QObject::connect(action4, &QAction::triggered, this, &pixeleditor::saveUnder);
        QObject::connect(action5, &QAction::triggered, this, &pixeleditor::exit);
        update();
    }
    virtual ~pixeleditor(){}
public slots:
    void newFile(){}
    void load(){}
    void save(){}
    void saveUnder(){}
    void exit(){
        close();
    }
private:
    QWidget *layoutWidget;
    QCursor *cursor;
    QBoxLayout *layout1;
    QLayout *layout2;
    QMenuBar *bar;
    QMenu *menu;
    QGraphicsScene *scene;
    QGraphicsView *sceneView;
    QPen *pen;
    QBrush *brush1;
    QBrush *brush2;
    QRectF *px;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QPoint *currentPos;
    int px_x;
    int px_y;
    int px_size;
protected:
    void mousePressEvent(QMouseEvent *event){
        scene->addRect(event->position().x(),event->position().y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::darkGreen, Qt::SolidPattern));
        update();
    }
};

#endif // MAINWINDOW_H
