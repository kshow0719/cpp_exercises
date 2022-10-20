// test_ArrayStack.cpp
#include "ArrayStack.h"

#include "stdio.h"
#include "iostream"
using namespace std;

int main(void) {
    // テスト用の文字列
    string test[6] = {"test0", "test1", "test2", "test3", "test4", "test5"};

    // ******************************* Q1 *****************************************
    cout << "------------ Q1 ------------" << endl;
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


    // ******************************* Q2 *****************************************
    cout << "------------ Q2 ------------" << endl;
    // Copy
    ArrayStack stack3(stack1);
    ArrayStack stack4 = stack2;

    // Assignment
    ArrayStack stack5;
    stack5 = stack1;
    ArrayStack stack6(10);
    stack6 = stack6;

    // COMPLETE 
    // Verify that the content of the stacks 'stack1' and 'stack3', 'stack2' and 'stack4'
    // and 'stack1' and 'stack5' are identical.
    // stack1とstack3のトップを確認
    cout << "Stack1: " << stack1.top() << ", Stack3: " << stack3.top() << endl;
    // stack2とstack4のトップを確認
    cout << "Stack2: " << stack2.top() << ", Stack4: " << stack4.top() << endl;
    // stack1とstack5のトップを確認
    cout << "Stack1: " << stack1.top() << ", Stack5: " << stack5.top() << endl;
    
    // Push several items in 'stack6'.

    // ******************************* Q3 *****************************************
    cout << "------------ Q3 ------------" << endl;

return 0;
}