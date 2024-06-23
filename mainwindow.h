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
#include <QtMath>
/*class checkeredBrush : public QPainter{
    Q_OBJECT
    checkeredBrush(QPainter *parent = NULL) : QPainter(parent){
    public:
        QPainter *painter();
    }
    void checkeredBrush::drawCheckered(int x, int y, int size){

    }
};*/

class pixeleditor : public QMainWindow{
    Q_OBJECT //Schlüssel für Kompiler: Einschließen von allem aus QObject

public:
    void paint(QMouseEvent *e){
        //currentPos = sceneView->mapToScene(QPoint(e->position().x(), e->position().y()));

        currentPos = QPoint((int)(qCeil((qreal)(e->position().x())-2*(sceneView->x()))),e->position().y()-bar->height()-windowWOScene/2);
        scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::darkGreen, Qt::SolidPattern));
        update();
    }
    pixeleditor(QWidget *parent = NULL) : QMainWindow(parent){

        px_x = 32.0;
        px_y = 32.0;
        px_size = 10.0;
        this->resize(600,600);
        isPainting = false;
        this->setWindowTitle("PixelEditor");
        //currentColour = new QColor(QColor(Qt::red));
        colour1 = new QPushButton("Rot", this);
        colour2 = new QPushButton("Orange", this);
        colour3 = new QPushButton("Gelb", this);
        colour4 = new QPushButton("Grün", this);
        colour5 = new QPushButton("Blau", this);
        colour6 = new QPushButton("Lila", this);
        colour7 = new QPushButton("Schwarz", this);
        colour8 = new QPushButton("Weiß", this);

        paletteGrid = new QGridLayout();
        paletteGrid->addWidget(colour1);
        paletteGrid->addWidget(colour2);
        paletteGrid->addWidget(colour3);
        paletteGrid->addWidget(colour4);
        paletteGrid->addWidget(colour5);
        paletteGrid->addWidget(colour6);
        paletteGrid->addWidget(colour7);
        paletteGrid->addWidget(colour8);
        layout1 = new QHBoxLayout();
        layout2 = new QVBoxLayout();
        scene = new QGraphicsScene(0,0,(qreal)(px_size*px_x),(qreal)(px_size*px_y));
        brush1 = new QBrush();
        brush2 = new QBrush();
        pen = new QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);
        brush1->setColor(Qt::darkGray);
        brush1->setStyle(Qt::SolidPattern);
        brush2->setColor(Qt::darkGreen);
        brush2->setStyle(Qt::SolidPattern);
        //scene->setSceneRect(0,0,0,0);
        sceneView = new QGraphicsView(scene);
        sceneView->setMaximumSize(px_x*px_size+px_size,px_y*px_size+px_size);
        sceneView->setBackgroundBrush(Qt::white);

        //-----------grid-----------//
        for(auto i = 0; i < px_x; i++){
            for(auto j = 0; j < px_y; j++){
                px = new QRectF(i*px_size, j*px_size, px_size, px_size);
                    scene->addRect(i*px_size, j*px_size, 1*px_size, 1*px_size,QPen(Qt::lightGray,1,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::transparent, Qt::SolidPattern));
                this->update();
            }
        }
        //--------------------------//

        /*        for(auto i = 0; i < px_x; i++){
            for(auto j = 0; j < px_y; j++){
                px = new QRectF(i*px_size, j*px_size, px_size, px_size);
                if(i%2==0 && j%2==0 || i%2!=0 && j%2!=0){
                    scene->addRect(i*px_size, j*px_size, 1*px_size, 1*px_size,QPen(Qt::darkgray,1,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::transparent, Qt::SolidPattern));
                }
                else{
                    scene->addRect(i*px_size, j*px_size, 1*px_size, 1*px_size,QPen(Qt::lightGray,1,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::transparent, Qt::SolidPattern));
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

        gridWidget = new QWidget();
        gridWidget->setLayout(paletteGrid);
        layout1->addWidget(sceneView);
        layout1->addWidget(gridWidget);

        layoutWidget = new QWidget();
        layoutWidget->setLayout(layout1);
        setCentralWidget(layoutWidget);

        //gridWidget->setLayout(paletteGrid);
        //layout1->addWidget(layoutWidget);

        //layout2->addWidget(gridWidget);
        QObject::connect(action1, &QAction::triggered, this, &pixeleditor::newFile);
        QObject::connect(action2, &QAction::triggered, this, &pixeleditor::load);
        QObject::connect(action3, &QAction::triggered, this, &pixeleditor::save);
        QObject::connect(action4, &QAction::triggered, this, &pixeleditor::saveUnder);
        QObject::connect(action5, &QAction::triggered, this, &pixeleditor::exit);
        windowWOMenuBar = this->height()-bar->height();
        windowWOScene = windowWOMenuBar - scene->height();
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
    QWidget *gridWidget;

    QLayout *layout1;
    QGridLayout *paletteGrid;
    QLayout *layout2;
    QMenuBar *bar;
    QMenu *menu;

    QPushButton *colour1;
    QPushButton *colour2;
    QPushButton *colour3;
    QPushButton *colour4;
    QPushButton *colour5;
    QPushButton *colour6;
    QPushButton *colour7;
    QPushButton *colour8;
    QColor currentColour;

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
    QPointF currentPos;

    int windowWOMenuBar; //part of the menu without the menu bar
    int windowWOScene; //windowWOMenuBar without the scene area
    int menuBarHeight;

    bool isPainting;
    int px_x;
    int px_y;
    int px_size;
protected:
    void mousePressEvent(QMouseEvent *event){
        isPainting = true;
        if((event->position().x() <= scene->sceneRect().width()) && (event->position().y() <= scene->sceneRect().height()) && (event->position().x() >= 0) && (event->position().y() >= 0)){
            paint(event);
            ;}

    }
    void mouseMoveEvent(QMouseEvent *event){
        if(isPainting){
            if((event->position().x() <= scene->sceneRect().width()) && (event->position().y() <= scene->sceneRect().height()) && (event->position().x() >= 0) && (event->position().y() >= 0)){
                paint(event);
                ;}
        }
    }
    void mouseReleaseEvent(QMouseEvent *event){
        isPainting = false;
    }

};

#endif // MAINWINDOW_H
