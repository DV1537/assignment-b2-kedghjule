#include <string>
#include <iostream>
#include "Shape.h"
#include "Bound.h"
#ifndef FIGURE_H
#define FIGURE_H


class Figure{
    public:
        Figure(){}
        void addShape(Shape* s);
        Bound getBoundingBox();
    private:
        int n;
        Shape** shapes;
        Shape** addToArray(Shape** array, int bufferSize, Shape* value); //Dynamic array manager
};

#endif