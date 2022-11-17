#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

double evaluate(const string& input){
    // 配列
    stringstream* devided = new stringstream[100];
    string buff;
    stringstream* inputs = new stringstream;

    // 式の挿入
    *inputs << input;
    double result = 0;

    // 式の分割
    int num = 0;
    while(getline(*inputs, buff, ' ')){
        devided[num] << buff;
        num++;
    }

    //2-Stackの用意
    stack<double> operand;
    stack<string> operation;

    // operand
    double temp_num1 = 0, temp_num2 = 0;

    for(int i = 0; i < num; i++){
        if(devided[i].str() =="("){
            // "("のとき
        }
        else if(devided[i].str() =="+"){
            // "+"のとき
            buff = devided[i].str();
            operation.push(buff);
        }
        else if(devided[i].str() =="-"){
            // "-"のとき
            buff = devided[i].str();
            operation.push(buff);
        }
        else if(devided[i].str() =="*"){
            // "*"のとき
            buff = devided[i].str();
            operation.push(buff);
        }
        else if(devided[i].str() =="/"){
            // "/"のとき
            buff = devided[i].str();
            operation.push(buff);
        }
        else if(devided[i].str() ==")"){
            // ")"のとき
            temp_num1 = operand.top();
            operand.pop();
            temp_num2 = operand.top();
            operand.pop();
            buff = operation.top();
            operation.pop();

            // 計算
            if(buff == "+"){
                operand.push((temp_num2 + temp_num1));
            }
            else if(buff == "-"){
                operand.push((temp_num2 - temp_num1));
            }
            else if(buff == "*"){
                operand.push((temp_num2 * temp_num1));
            }
            else if(buff == "/"){
                operand.push((temp_num2 / temp_num1));
            }
            else{
                cout<<"Operation Error." << endl;
            }
        }
        else{
            if((stod(devided[i].str()))){
                temp_num1 = stod(devided[i].str());
                operand.push(temp_num1);
            }
            else {
                // エラー
                cout<< "Error code." << endl;
                break;
            }
        }
    }
    // 結果の取り出し
    result = operand.top();
    return result;
}