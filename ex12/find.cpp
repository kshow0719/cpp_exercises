#include <cmath>
#include <vector>
#include <queue>
#include "find.h"
using namespace std;

bool Compare::operator()(const Point& first, const Point& second){
    auto first_to_origin = sqrt(pow(first.x, 2) + pow(first.y, 2) + pow(first.z, 2));
    auto second_to_origin = sqrt(pow(second.x, 2) + pow(second.y, 2) + pow(second.z, 2));

    return first_to_origin < second_to_origin;
}