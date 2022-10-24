#include <string>
#include <iostream>
using namespace std;

#ifndef SHAPE_H
#define SHAPE_H

struct Shape{
public:
    virtual string get_name() = 0;
    virtual float compute_area() = 0;
    virtual Shape* create() = 0;
    virtual Shape* clone() = 0;
    virtual ~Shape(){};

private:
};

#endif // SHAPE_H