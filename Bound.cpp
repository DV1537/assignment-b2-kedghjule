#include "Bound.h"
#include "Point.h"

Bound::Bound(Point topLeft, Point bottomRight){
    this->tl = topLeft;
    this->br = bottomRight;
}

Bound::Bound(){
    this->tl = Point();
    this->br = Point();
}

Point Bound::getTopLeft(){
    return this->tl;
}

Point Bound::getBottomRight(){
    return this->br;
}

void Bound::setTopLeft(Point TL){
    this->tl = TL;
}

void Bound::setBottomRight(Point BR){
    this->br = BR;
}

std::ostream& operator<<(std::ostream& out, Bound b){
    out << "Top left: " << b.getTopLeft() << ", Bottom Right: " << b.getBottomRight();
    return out;
}