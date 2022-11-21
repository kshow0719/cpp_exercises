#include <cmath>
#include <vector>
#include <queue>
#include "find.h"
using namespace std;

// Compare オブジェクト関数
bool Compare::operator()(const Point& first, const Point& second){
    auto first_to_origin = sqrt(pow(first.x, 2) + pow(first.y, 2) + pow(first.z, 2));
    auto second_to_origin = sqrt(pow(second.x, 2) + pow(second.y, 2) + pow(second.z, 2));

    return first_to_origin > second_to_origin;
}

// find_k_closest 関数
vector<Point> find_k_closest(vector <Point> P, int k){
    priority_queue<double, vector<Point>, decltype(Compare())> queue{Compare()};

    for (int i = P.size()-1; i >= 0; i--){
        queue.push(P[i]);
    }

    vector<Point> result;
    for (int i = 0; i < k; i++) {
        result.push_back(queue.top());
        queue.pop();
    }

    return result;
}