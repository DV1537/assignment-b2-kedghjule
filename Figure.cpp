#include <iostream>
#include "Figure.h"
#include "Shape.h"
#include "Bound.h"

Figure::~Figure(){
    for(int i = 0; i < n; i++){
        delete shapes[i];
    }
}

void Figure::addShape(Shape* s){
    Shape** tmp = new Shape*[n+1];

    for(int i = 0; i < n; i++){
        tmp[i] = nullptr;
        tmp[i] = shapes[i];
    }
    tmp[n] = s;

    shapes = nullptr;
    shapes = tmp;

    n++;
}

Bound Figure::getBoundingBox(){
    int xR = 0, xL = 0, yT = 0, yB = 0;

    int iYTS = 0; //Index, Y-Axis, Top, Shape
    int iYTP = 0; //Index, Y-Axis, Top, Points
    int iYBS = 0; //Index, Y-Axis, Bottom, Shape
    int iYBP = 0; //Index, Y-Axis, Bottom, Points
    int iXRS = 0; //Index, Y-Axis, Right, Shape
    int iXRP = 0; //Index, Y-Axis, Right, Points
    int iXLS = 0; //Index, Y-Axis, Left, Shape
    int iXLP = 0; //Index, Y-Axis, Left, Points

    //Find out all indexes for our edge points...

    for(int i = 0; i < n; i++){
        for(int v = 0; v < shapes[i]->getCount(); v++){
            if(shapes[i]->getPoints()[v].getX() > shapes[iXRS]->getPoints()[iXRP].getX()){
                iXRS = i;
                iXRP = v;
            }    
            if(shapes[i]->getPoints()[v].getX() < shapes[iXLS]->getPoints()[iXLP].getX()){
                iXLS = i;
                iXLP = v;
            }
            if(shapes[i]->getPoints()[v].getY() > shapes[iYTS]->getPoints()[iYTP].getY()){
                iYTS = i;
                iYTP = v;
            }
            if(shapes[i]->getPoints()[v].getY() < shapes[iYBS]->getPoints()[iYBP].getY()){
                iYBS = i;
                iYBP = v;
            }
        }
    }

    //Conclude bounds

    xR = shapes[iXRS]->getPoints()[iXRP].getX();
    xL = shapes[iXLS]->getPoints()[iXLP].getX();
    yT = shapes[iYTS]->getPoints()[iYTP].getY();
    yB = shapes[iYBS]->getPoints()[iYBP].getY();
    Bound b = Bound(Point(xL, yT), Point(xR, yB));
    return b;
}

Shape** Figure::getClosest(Shape* location, int n){
    //Generate list of Shape Distances
    shapeDist* listOfDistances = new shapeDist[this->n];
    for(int k = 0; k < this->n; k++){
        shapeDist dist = shapeDist();
        dist.s = shapes[k];
        dist.d = shapes[k]->distance(location);
        listOfDistances[k] = dist;
    }
    
    quickSort(listOfDistances, 0, (this->n-1));

    //List should be complete and sorted

    Shape** result = new Shape*[n];
    int i = 0;
    int r = 0;
    while(r < n){
        if(listOfDistances[i].d == 0){
            i++;
        }else{    
            result[r] = listOfDistances[i].s;
            i++;
            r++;
        }
    }

    //Clean up
    delete[] listOfDistances;

    return result;
}

//Recursive sorting
//######################################################
//Source code: https://www.geeksforgeeks.org/quick-sort/
//######################################################

void Figure::swap(shapeDist& a, shapeDist& b) 
{ 
    shapeDist t = a; 
    a = b; 
    b = t; 
} 

int Figure::partition (shapeDist arr[], int low, int high) 
{ 
    shapeDist pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j].d <= pivot.d) 
        { 
            i++;    // increment index of smaller element 
            swap(arr[i],arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void Figure::quickSort(shapeDist arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 