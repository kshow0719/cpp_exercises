#include <string>
#include <iostream>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

struct Point {
    float x; 
    float y; 
};

class Shape{
public:
    virtual string get_name() const = 0;
    virtual float compute_area() const = 0;
    virtual Shape* create() const = 0;
    virtual Shape* clone() const = 0;
    virtual ~Shape(){};

private:
};

#endif // SHAPE_H