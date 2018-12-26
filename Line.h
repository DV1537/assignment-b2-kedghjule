#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef LINE_H
#define LINE_H


class Line: public Shape{
    public:
        Line(Point* pnts, int count);
        Line(Point p1, Point p2);
        std::string getType();
        double area();
        bool isConvex();
        double circumference();
        Point position();

        Point* getPoints();
        int getCount();
    private:
        int p;
        Point* points;
};

#endif