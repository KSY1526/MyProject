#pragma once
#include <iostream>
#include "Student.h"
#define MAX_STACK_SIZE 100

inline int error(const char* str){//const상수.
    std::cerr << str << "\n"; //cerr 에러를 배출해줌
    exit(1); // 비정상 1 정상 0
};

class StudentStack{
    private:
        Student data[MAX_STACK_SIZE];
        int top;
    public:
        StudentStack(){top = -1;}
        ~StudentStack(){}
        bool isEmpty(){return top == -1;}
        bool isFull(){return top == MAX_STACK_SIZE -1;}
        void push(Student e){
            if(isFull()){
                error("스택이 가득 차 있습니다.");
            }
            data[++top] = e;
        }
        Student pop(){
            if(isEmpty()){
                error("스택이 비워있습니다.");
            }
            return data[top--];
        }
        Student peek(){
            if(isEmpty()){
                error("스택이 비워있습니다.");
            }
            return data[top];
        }
        void display(){
            std::cout << "[스택 항목의 수 = " << top + 1 << "] ";
            for (int i = 0; i <= top; i++){
                std::cout << "<" << data[i].contents() << ">";
            }
            std::cout << "\n";
        }
};