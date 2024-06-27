#include "mainwindow.h"

void pixeleditor::paint(QMouseEvent *e){ //Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

    currentPos = QPoint((int)((qreal)(calcPixel(px_size,e->position().x()-2*(sceneView->x())))),calcPixel(px_size,e->position().y()-bar->height()-windowWOScene/2));
    scene->addRect(currentPos.x(),currentPos.y(), 1*px_size,1*px_size,QPen(Qt::transparent,3,Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin), QBrush(currentColor, Qt::SolidPattern));
    update();
}
//-------------------------------------------------------------------------------//
void pixeleditor::paintNine(QMouseEvent *e){ //Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

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

void pixeleditor::paintHeart(QMouseEvent *e){

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

void pixeleditor::paintStar(QMouseEvent *e){

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

void pixeleditor::paintCheckered(QMouseEvent *e){//Berechnung der Position beachtet auch Abstände zu anderen Widget-Elementen (z.B. Menübar)

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


int pixeleditor::calcPixel(int pPx_size, int coord){
    return qFloor((coord/pPx_size))*pPx_size;
}

//-------------------------------------------------------------------------------//

