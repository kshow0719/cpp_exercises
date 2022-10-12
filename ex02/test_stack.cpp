// test_stack.cpp
// Insert the relevant headers here 

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

using namespace std;

int main(void) {
    Point xy, result;
    Stack stack;
    int num;

    // テストのためのランダムを現在時刻で初期化
    srand((unsigned int)time(NULL));

    // スタックが空であるかどうかの確認
    if(stack.empty()) cout << "The stack is empty." << endl;
    else cout << "The stack is not empty." << endl;

    // 要素数を1から100でランダム生成
    num = rand() % 100 + 1;

    // スタックにランダム生成した(0 ~ 99)要素を追加する
    for(int i = 0; i < num; i++){
        xy = {rand() % 100, rand() % 100};
        stack.push(xy);
    }

    // スタックのサイズを確認
    // -1で初期化されるため、最大で99
    cout << "Stack size is " << stack.size() << "." << endl;

    // スタックが一杯であるかどうかの確認
    if(stack.full()) cout << "The stack is full." << endl;
    else cout << "The stack is not full." << endl;

    // スタックの頂点の要素にアクセスする
    result = stack.top();
    printf("x = %d, y = %d\n",result.x, result.y);

    // スタックから要素を取り出す
    stack.pop();

    // スタックの頂点の要素にアクセスする
    // 前回と変わるはず
    result = stack.top();
    printf("x = %d, y = %d\n",result.x, result.y);
}