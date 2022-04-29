#pragma once
#include "ArrayStackTemplate.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

double calcPostfixExpr(){
    char c;
    double val;
    ArrayStack<double> st;
    while(cin.get(c) && c != '\n'){
        if(c=='+' || c == '-' || c == '*' || c == '/'){
            double val2 = st.pop(); //두번째 연산자
            double val1 = st.pop();
            switch(c){
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
        else if (c >= '0' && c <= '9'){//아스키코드에0~9가 붙어있음
            cin.unget(); // 버퍼로 받았던것 다시 집어넣음
            cin >> val; // 공백 전까지의 값을 더블로 받음.
            st.push(val);
        }
    }
    return st.pop(); //마지막에 남은 값이 결과값
}

double calcPostfixExpr(string str){
    istringstream iss(str); //읽기전용.
    char c;
    double val;
    ArrayStack<double> st;
    while(iss.get(c) && c != '\n'){
        if(c=='+' || c == '-' || c == '*' || c == '/'){
            double val2 = st.pop(); //두번째 연산자
            double val1 = st.pop();
            switch(c){
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
        else if (c >= '0' && c <= '9'){//아스키코드에0~9가 붙어있음
            iss.unget(); // 버퍼로 받았던것 다시 집어넣음
            iss >> val; // 공백 전까지의 값을 더블로 받음.
            st.push(val);
        }
    }
    return st.pop(); //마지막에 남은 값이 결과값
}

//메인 위치에 함수를 복사해서 씀, 속도는 빠르나 용량은 커짐
inline int priority(char op){//함수를 불러오는 위치에 복사를 해줌
    switch(op){
        case '(': case ')' : return 0;
        case '+': case '-' : return 1;
        case '*': case '/' : return 2;
    }
    return -1;
}

string infix2Postfix(){
    char c, op; // c는 읽는 문자, op는 꺼내는 문자
    double val;
    ostringstream oss;
    ArrayStack<char> st;
    while(cin.get(c) && c != '\n'){
        if (c >= '0' && c <= '9'){
            cin.unget(); //글자 다시 버퍼에 놓고 다시 읽어드림
            cin >> val; // 읽은 문자열 val에 넣기
            oss << val << " "; //
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.isEmpty()){
                op = st.pop();
                if (op == '(') break;
                oss << op << " ";
            }
        }
        else if(c=='+' || c == '-' || c == '*' || c == '/'){
            while(!st.isEmpty()){ // 계속 비교함
                op = st.peek();
                if (priority(c) <= priority(op)){// 스택안이 우선순위가 크다면
                    oss << op << " "; // 스택 안에 값을 꺼냄
                    st.pop();
                }
                else break; // 우선순위가 더 높다면 멈춤
            }
            st.push(c); // c는 무조건 스택에 넣음
        }
        
    }
    while(!st.isEmpty()){
        oss << st.pop() << " ";
    }
    return oss.str();
}

string infix2Postfix(string istr){
    char c, op; // c는 읽는 문자, op는 꺼내는 문자
    double val;
    ostringstream oss;
    istringstream iss(istr);
    ArrayStack<char> st;
    while(iss.get(c) && c != '\n'){
        if (c >= '0' && c <= '9'){
            iss.unget(); //글자 다시 버퍼에 놓고 다시 읽어드림
            iss >> val; // 읽은 문자열 val에 넣기
            oss << val << " "; //
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.isEmpty()){
                op = st.pop();
                if (op == '(') break;
                oss << op << " ";
            }
        }
        else if(c=='+' || c == '-' || c == '*' || c == '/'){
            while(!st.isEmpty()){ // 계속 비교함
                op = st.peek();
                if (priority(c) <= priority(op)){// 스택안이 우선순위가 크다면
                    oss << op << " "; // 스택 안에 값을 꺼냄
                    st.pop();
                }
                else break; // 우선순위가 더 높다면 멈춤
            }
            st.push(c); // c는 무조건 스택에 넣음
        }
        
    }
    while(!st.isEmpty()){
        oss << st.pop() << " ";
    }
    return oss.str();
}