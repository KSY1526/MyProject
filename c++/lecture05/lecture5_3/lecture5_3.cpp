#include "EvalMathEq.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    cout << "수식입력 (postfix): \n";
    double res = calcPostfixExpr();
    cout << "계산 결과 = " << res << "\n";
    string input = "30 20 100 + *";
    cout << "입력된 수식 (postfix): " << input << "\n";
    res = calcPostfixExpr(input);
    cout << "계산 결과 = " << res << "\n";


    cout << "수식입력 (infit): \n";
    string res2 = infix2Postfix();
    cout << "변환 결과 = " << res2 << "\n";
    string input2 = "30 + 20 * 100";
    cout << "미리 입력된 수식 (infix): " << input2 << "\n";
    res2 = infix2Postfix(input2);
    cout << "변환 결과 = " << res2 << "\n";
    /*
    string input3 = "30 + 20 * 100";
    cout << "미리 입력된 수식 (infix): " << input3 << "\n";
    string res3 = infix2Postfix(input3);
    cout << "변환 결과 = " << res3 << "\n";
    double res4 = calcPostfixExpr(res3);
    cout << "수식 계산 결과 = " << res4 << "\n";*/
    return 0;
}