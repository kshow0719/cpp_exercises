// test_ArrayStack.cpp
#include "ArrayStack.h"

#include "stdio.h"
#include "iostream"
using namespace std;

int main(void) {
    // テスト用の文字列
    string test[6] = {"test0", "test1", "test2", "test3", "test4", "test5"};

    // Create an instance of ArrayStack named stack1 
    //   using the default constructor
    // Push several items in this stack.
    // stack1の生成
    ArrayStack stack1;
    // stack1に要素をpushする
    for (int i = 0; i < 6; i++){
        stack1.push(test[i]);
    }
    // stack1のtopを確認
    cout << stack1.top() << endl;

    // Create another instance of ArrayStack named stack2
    //   using the other constructor, specify an original size of 5
    // Push several items in this stack.
    // stack2の生成
    ArrayStack stack2(3);
    // stack2に要素をpushする
    for (int i = 0; i < 3; i++){
        stack2.push(test[i]);
    }
    // stack2のtopを確認
    cout << stack2.top() << endl;

return 0;
}