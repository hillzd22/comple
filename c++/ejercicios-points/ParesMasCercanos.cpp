#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <limits>
#include <cmath>
#include "point.h"
#include "quicksort.h"

class FinderPoints{
    public:
    Quicksort* qs = new Quicksort();
    
    int compareX(const void* a, const void *b){
        Point *p1 = (Point *)a;
        Point *p2 = (Point *)b;
        return (p1->x - p2->x);
    }
    
    int compareY(const void* a, const void*b){
        Point *p1 = (Point *)a;
        Point *p2 = (Point *)b;
        return (p1->y - p2->y);
    }
    
    float min(float x, float y){
        return (x < y)? x : y;
    }
    ///BF
    float closestPairBF(Point P[], int n){
        float min = std::numeric_limits<float>::max();
        for(int i = 0; i < n; ++i)
            for(int j = i+1; j < n;++j)
                if(distance(P[i], P[j]) < min)
                    min = distance(P[i], P[j]);
        return min;
    }
    
    
    
    
};

#endif