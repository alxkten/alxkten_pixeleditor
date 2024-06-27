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
#include <QEvent>
#include <iostream>
#include <QLabel>
#include <QString>
#include <QImage>
#include <QMessageBox>
//#include <QFileDialog>

class pixeleditor : public QMainWindow{

    Q_OBJECT

public:


    int getCurrentBrush(){
        return currentBrush;
    }
    /*
     * void pixeleditor::paint(QMouseEvent *e)
     * Setzt ein Kästchen/ Pixel an die Stelle des Cursors
    */

    void paint(QMouseEvent *e){ //Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

        currentPos = QPoint((int)((qreal)(calcPixel(px_size,e->position().x()-2*(sceneView->x())))),calcPixel(px_size,e->position().y()-bar->height()-windowWOScene/2));
        scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        update();
    }
    //-------------------------------------------------------------------------------//

    /*
     * void pixeleditor::paintNine(QMouseEvent *e)
     * Setzt ein 3x3 Kästchen-/ Pixelmuster an die Position des Cursors.
    */

    void paintNine(QMouseEvent *e){ //Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

        currentPos = QPoint((int)(qCeil((qreal)(calcPixel(px_size,e->position().x())-2*(sceneView->x())))-1),calcPixel(px_size,e->position().y()-bar->height()-windowWOScene/2));
        scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        update();
    }
//-------------------------------------------------------------------------------//

    /*
     * void pixeleditor::paintHeart(QMouseEvent *e)
     * Setzt ein herzförmiges Kästchen-/ Pixelmuster an die Position des Cursors.
    */

    void paintHeart(QMouseEvent *e){//Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

        currentPos = QPoint((int)(qCeil((qreal)(calcPixel(px_size,e->position().x())-2*(sceneView->x())))-1),calcPixel(px_size,e->position().y()-bar->height()-windowWOScene/2));

        scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()-2*px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-2*px_size,currentPos.y()-2*px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-2*px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-2*px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()-2*px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+2*px_size,currentPos.y()-2*px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+2*px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+2*px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()+2*px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        update();
    }

    //-------------------------------------------------------------------------------//

    /*
     * void pixeleditor::paintHeart(QMouseEvent *e)
     * Setzt ein herzförmiges Kästchen-/ Pixelmuster an die Position des Cursors.
    */

    void paintStar(QMouseEvent *e){//Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

        currentPos = QPoint((int)(qCeil((qreal)(calcPixel(px_size,e->position().x())-2*(sceneView->x())))-1),calcPixel(px_size,e->position().y()-bar->height()-windowWOScene/2));

        scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x(),currentPos.y()-2*px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()-2*px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        scene->addRect(currentPos.x()+2*px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        update();
    }

    //-------------------------------------------------------------------------------//

    /*
     * void pixeleditor::paintCheckered(QMouseEvent *e)
     * Setzt ein 3x3 Kästchen-/ Pixel-Schachmuster an die Position des Cursors.
     * Es werden immer die gleichen Pixel ausgefüllt (alle mit x-Koord + y-Koord % 2 = 0, also "alle zwei Pixel")
    */

    void paintCheckered(QMouseEvent *e){//Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

        currentPos = QPoint((int)(qCeil((qreal)(calcPixel(px_size,e->position().x())-2*(sceneView->x())))-1),calcPixel(px_size,e->position().y()-bar->height()-windowWOScene/2));

        if(qRound(( ((currentPos.x())/px_size) + ((currentPos.y())/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x()-px_size)/px_size) + ((currentPos.y()-px_size)/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x()-px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x())/px_size) + ((currentPos.y()-px_size)/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x(),currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x())/px_size) + ((currentPos.y()+px_size)/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x(),currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x()+px_size)/px_size) + ((currentPos.y()+px_size)/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x()+px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x()-px_size)/px_size) + ((currentPos.y()+px_size)/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x()-px_size,currentPos.y()+px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x()+px_size)/px_size) + ((currentPos.y()-px_size)/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x()+px_size,currentPos.y()-px_size, 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x()+px_size)/px_size) + ((currentPos.y())/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x()+px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        if(qRound(( ((currentPos.x()-px_size)/px_size) + ((currentPos.y())/px_size) )) % 2 == 0){
            scene->addRect(currentPos.x()-px_size,currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
        }
        update();
    }

    //-------------------------------------------------------------------------------//

    /*
     * int calcPixel(int pPx_size, int coord)
     * Auf Rasterkoordinate des zu zeichnenden Pixel runden,
     *  z.B. wenn Cursor auf (100,100) liegt und px_size = 32
     *  dann soll er den Pixel an (96,96) zeichnen
    */

    int calcPixel(int pPx_size, int coord){
        return qFloor((coord/pPx_size))*pPx_size;
    }

    //-------------------------------------------------------------------------------//
    pixeleditor(QWidget *parent = NULL) : QMainWindow(parent){

        currentBrush = 1;
        currentColor = QColor(20,20,20,255); //Ausgangspinsel: Dünn, Schwarz
        isPainting = false;

        px_x = 32.0; //Anzahl der Pixel entlang x
        px_y = 32.0; //Anzahl der Pixel entlang y
        px_size = 10.0; //Größe der Pixel

        this->resize(600,600);
        this->setWindowTitle("PixelEditor");

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

        layout1 = new QHBoxLayout(); //"Basis"-Layout, legt Zeichenfläche und Farbpalette aus

        scene = new QGraphicsScene(0,0,(qreal)(px_size*px_x),(qreal)(px_size*px_y));
        sceneView = new QGraphicsView(scene);
        sceneView->setMaximumSize(px_x*px_size+px_size,px_y*px_size+px_size);
        sceneView->setBackgroundBrush(Qt::white);

        farbe = new QLabel("Farbe: Schwarz", this); //Anzeige der momentan verwendeten Farbe
        farbe->setGeometry(sceneView->sceneRect().left()+px_size, sceneView->sceneRect().bottom(),sceneView->sceneRect().left()+(sceneView->sceneRect().width())/2, sceneView->sceneRect().bottom()+20);
        whichBrush= new QLabel("Stift: Dünn", this); //Anzeige des momentan verwendeten Stifts
        whichBrush->setGeometry(sceneView->sceneRect().left()+(sceneView->sceneRect().width())/2, sceneView->sceneRect().bottom(),sceneView->sceneRect().left()+(sceneView->sceneRect().width()), sceneView->sceneRect().bottom()+20);


        //-----------grid-----------//
        for(auto i = 0; i < px_x; i++){
            for(auto j = 0; j < px_y; j++){
                px = new QRectF(i*px_size, j*px_size, px_size, px_size);
                    scene->addRect(i*px_size, j*px_size, 1*px_size, 1*px_size,QPen(Qt::lightGray,1,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(Qt::transparent, Qt::SolidPattern));
                this->update();
            }
        }
        //--------------------------//

        bar = menuBar();
        menu = bar->addMenu(tr("&Datei"));
        action1 = new QAction("&Neue Datei", this);
        action2 = new QAction("&Datei laden", this);
        action3 = new QAction("&Speichern", this);
        action4 = new QAction("&Speichern unter...", this);
        action5 = new QAction("&Beenden", this);

        menu2 = bar->addMenu(tr("&Stift"));
        action6 = new QAction("&Dünn (1x1)", this);
        action7 = new QAction("&Dick (3x3)", this);
        action8 = new QAction("&Schachmuster (3x3)", this);
        action9 = new QAction("&Stern", this);
        action10 = new QAction("&Herz", this);

        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        menu->addAction(action4);
        menu->addAction(action5);
        menu2->addAction(action6);
        menu2->addAction(action7);
        menu2->addAction(action8);
        menu2->addAction(action9);
        menu2->addAction(action10);

        gridWidget = new QWidget();
        gridWidget->setLayout(paletteGrid); //Widget für das Farbpalettenlayout, um es ins Basis-Layout einzufügen

        layout1->addWidget(sceneView);
        layout1->addWidget(gridWidget);

        layoutWidget = new QWidget();
        layoutWidget->setLayout(layout1); //Widet für das Basis-Layout, um es zentral setzen zu können
        setCentralWidget(layoutWidget);

        QObject::connect(action1, &QAction::triggered, this, &pixeleditor::newFile);
        QObject::connect(action2, &QAction::triggered, this, &pixeleditor::load);
        QObject::connect(action3, &QAction::triggered, this, &pixeleditor::save);
        QObject::connect(action4, &QAction::triggered, this, &pixeleditor::saveUnder);
        QObject::connect(action5, &QAction::triggered, this, &pixeleditor::exit);
        QObject::connect(action6, &QAction::triggered, this, &pixeleditor::setToThin);
        QObject::connect(action7, &QAction::triggered, this, &pixeleditor::setToThick);
        QObject::connect(action8, &QAction::triggered, this, &pixeleditor::setToCheckered);
        QObject::connect(action9, &QAction::triggered, this, &pixeleditor::setToStar);
        QObject::connect(action10, &QAction::triggered, this, &pixeleditor::setToHeart);
        QObject::connect(colour1, &QPushButton::clicked, this, &pixeleditor::colorToRed);
        QObject::connect(colour2, &QPushButton::clicked, this, &pixeleditor::colorToOrange);
        QObject::connect(colour3, &QPushButton::clicked, this, &pixeleditor::colorToYellow);
        QObject::connect(colour4, &QPushButton::clicked, this, &pixeleditor::colorToGreen);
        QObject::connect(colour5, &QPushButton::clicked, this, &pixeleditor::colorToBlue);
        QObject::connect(colour6, &QPushButton::clicked, this, &pixeleditor::colorToPurple);
        QObject::connect(colour7, &QPushButton::clicked, this, &pixeleditor::colorToBlack);
        QObject::connect(colour8, &QPushButton::clicked, this, &pixeleditor::colorToWhite);

        windowWOMenuBar = this->height()-bar->height();
        windowWOScene = windowWOMenuBar - scene->height();

    }
    virtual ~pixeleditor(){}
public slots:
    void setToThin(){
        whichBrush->setText("Stift : Dünn");
        currentBrush = 1;
    }
    void setToThick(){
        whichBrush->setText("Stift : Dick");
        currentBrush = 2;
    }
    void setToCheckered(){
        whichBrush->setText("Stift : Schach");
        currentBrush = 3;
    }
    void setToStar(){
        whichBrush->setText("Stift : Stern");
        currentBrush = 4;
    }
    void setToHeart(){
        whichBrush->setText("Stift : Herz");
        currentBrush = 5;
    }
    void colorToRed(){
        farbe->setText("Farbe : Rot");
        currentColor = QColor(200,30,30,255);
    }
    void colorToOrange(){
        farbe->setText("Farbe : Orange");
        currentColor = QColor(220,140,0,255);
    }
    void colorToYellow(){
        farbe->setText("Farbe : Gelb");
        currentColor = QColor(200,180,0,255);
    }
    void colorToGreen(){
        farbe->setText("Farbe : Grün");
        currentColor = QColor(30,120,30,255);
    }
    void colorToBlue(){
        farbe->setText("Farbe : Blau");
        currentColor = QColor(30,30,220,255);
    }
    void colorToPurple(){
        farbe->setText("Farbe : Lila");
        currentColor = QColor(120,20,200,255);
    }
    void colorToBlack(){
        farbe->setText("Farbe : Schwarz");
        currentColor = QColor(20,20,20,255);
    }
    void colorToWhite(){
        farbe->setText("Farbe : Weiß");
        currentColor = QColor(255,255,255,255);
    }
    void newFile(){}
    void load(){
    }
    void save(){
        img = new QImage(sceneView->sceneRect().width(), sceneView->sceneRect().height(), QImage::Format_RGBX16FPx4);
        pain = new QPainter(img);
        saveMessage = new QMessageBox(QMessageBox::Information, "Vorgang abgeschlossen", "Das Bild wurde gespeichert.", QMessageBox::Ok);
        img->fill(Qt::white);
        scene->render(pain);
        img->save("test.png");
        saveMessage->open();
    }
    void saveUnder(){}
    void exit(){
        close();
    }
private:
    QWidget *layoutWidget;
    QWidget *gridWidget;

    QLayout *layout1;
    QGridLayout *paletteGrid;
    QLabel *farbe;
    QLabel *cursorPos;
    QLabel *whichBrush;
    QMenuBar *bar;
    QMenu *menu; //Datei-Menü
    QMenu *menu2;//Stift-Menü
    QImage *img;
    QPainter *pain;
    QMessageBox *saveMessage;
    //QFileDialog *fileDia;

    QPushButton *colour1;
    QPushButton *colour2;
    QPushButton *colour3;
    QPushButton *colour4;
    QPushButton *colour5;
    QPushButton *colour6;
    QPushButton *colour7;
    QPushButton *colour8;
    QColor currentColor;
    int currentBrush; //Verwendet zur Fallunterscheidung zwischen ausgewähltem Brush

    QGraphicsScene *scene;
    QGraphicsView *sceneView;
    QRectF *px;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    QAction *action5;
    QAction *action6;
    QAction *action7;
    QAction *action8;
    QAction *action9;
    QAction *action10;
    QPointF currentPos; //Momentane Position, verwendet für Zeichenfunktionen

    int windowWOMenuBar; //part of the menu without the menu bar
    int windowWOScene; //windowWOMenuBar without the scene area
    int menuBarHeight;

    bool isPainting;
    int px_x;
    int px_y;
    int px_size;

protected:
    void mousePressEvent(QMouseEvent *event){
        cursorPos = new QLabel("allo", this);
        switch(currentBrush){
        case 1:
            paint(event);
            break;
        case 2:
            paintNine(event);
            break;
        case 3:
            paintCheckered(event);
            break;
        case 4:
            paintStar(event);
            break;
        case 5:
            paintHeart(event);
            break;
        default:
            paint(event);
            break;
        }

    }
    void mouseMoveEvent(QMouseEvent *event){
            switch(currentBrush){
            case 1:
                paint(event);
                break;
            case 2:
                paintNine(event);
                break;
            case 3:
                paintCheckered(event);
                break;
            case 4:
                paintStar(event);
                break;
            case 5:
                paintHeart(event);
                break;
            default:
                paint(event);
                break;
            }
    }
    void mouseReleaseEvent(QMouseEvent *event){
        switch(currentBrush){
        case 1:
            paint(event);
            break;
        case 2:
            paintNine(event);
            break;
        case 3:
            paintCheckered(event);
            break;
        case 4:
            paintStar(event);
            break;
        case 5:
            paintHeart(event);
            break;
        default:
            paint(event);
            break;
        }
    }

};


#endif // MAINWINDOW_H
