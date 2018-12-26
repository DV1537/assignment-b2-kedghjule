#include <iostream>
#include "Point.h"
#ifndef BOUND_H
#define BOUND_H


class Bound{
    public:
        Bound(Point topLeft, Point bottomRight);
        Bound();
        Point getTopLeft();
        Point getBottomRight();
        void setTopLeft(Point TL);
        void setBottomRight(Point BR);
        friend std::ostream& operator<<(std::ostream& out, Bound b);
    private:
        Point tl;
        Point br;
};

#endif