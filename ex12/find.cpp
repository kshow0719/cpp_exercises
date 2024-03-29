#include <cmath>
#include <vector>
#include <queue>
#include "find.h"
using namespace std;

// Compare オブジェクト関数
bool Compare::operator()(const Point& first, const Point& second){
    auto first_to_origin = sqrt(pow(first.x, 2) + pow(first.y, 2) + pow(first.z, 2));
    auto second_to_origin = sqrt(pow(second.x, 2) + pow(second.y, 2) + pow(second.z, 2));

    return first_to_origin < second_to_origin;
}

// find_k_closest 関数
vector<Point> find_k_closest(vector <Point> P, int k){
    priority_queue<double, vector<Point>, decltype(Compare())> queue{Compare()};

    for (int i = P.size()-1; i >= 0; i--){
        queue.push(P[i]);
    }

    // 変更処理
    vector<Point> temp;
    for (int i = P.size()-1; i >= 0; i--){
        temp.push_back(queue.top());
        queue.pop();
    }
    vector<Point> result(temp.end()-1-k, temp.end());

    return result;
}

// 関数 find_k_closest_lambda()
vector<Point> find_k_closest_lambda(vector <Point> P, int k){
    auto Compare = [](const Point& first, const Point& second) -> bool{
        auto first_to_origin = sqrt(pow(first.x, 2) + pow(first.y, 2) + pow(first.z, 2));
        auto second_to_origin = sqrt(pow(second.x, 2) + pow(second.y, 2) + pow(second.z, 2));
        return first_to_origin < second_to_origin;
    };
    priority_queue<double, vector<Point>, decltype(Compare)>queue{Compare};

    for (int i = P.size()-1; i >= 0; i--){
        queue.push(P[i]);
    }

    // 変更処理
    vector<Point> temp;
    for (int i = P.size()-1; i >= 0; i--){
        temp.push_back(queue.top());
        queue.pop();
    }
    vector<Point> result(temp.end()-1-k, temp.end());

    return result;
}