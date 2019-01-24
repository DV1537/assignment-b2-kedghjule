#include <string>
#include <iostream>
#include "Shape.h"
#include "Bound.h"
#ifndef FIGURE_H
#define FIGURE_H

struct shapeDist{ 
    double d = 0; 
    Shape* s = nullptr; 
};

class Figure{
    public:
        Figure(){}
        ~Figure();
        void addShape(Shape* s);
        Bound getBoundingBox();
        Shape** getClosest(Shape* location, int n);
        
    private:
        int n = 0;
        Shape** shapes = nullptr;

        //Sorting
        void swap(shapeDist& a, shapeDist& b);
        int partition(shapeDist arr[], int low, int high);
        void quickSort(shapeDist arr[], int low, int high);  
};



#endif