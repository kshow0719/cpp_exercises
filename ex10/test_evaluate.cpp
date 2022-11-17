#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include "evaluate.h"
using namespace std;

// テスト
int main(){
    std::string input;
    double result = 0;

    // input
    getline(cin, input);
    // evaluate
    result = evaluate(input);
    // output
    cout << "input = "<< input << ", result = " << result << endl;

    return 0;
}