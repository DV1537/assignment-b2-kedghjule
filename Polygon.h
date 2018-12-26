#include <string>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#ifndef POLYGON_H
#define POLYGON_H


class Polygon: public Shape{
    public:
        Polygon();
        Polygon(Point* pnts, int count);
        ~Polygon();
        std::string getType();
        double area();
        bool isConvex();
        double circumference();
        Point position();

        Point* getPoints();
        int getCount();
        
        void operator=(const Polygon& rhs);
        friend Polygon operator+(Polygon a, Polygon b);
        friend Polygon operator+(Polygon a, Point b);
        friend std::ostream &operator<<(std::ostream &out, Polygon s);
    private:
        int p;
        Point* points;
};

#endif