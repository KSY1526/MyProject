#pragma once
#include "SingleLinkedList.h"

inline int error(const char* str){//const상수.
    std::cerr << str << "\n"; //cerr 에러를 배출해줌
    exit(1); // 비정상 1 정상 0
};

class LinkedlistStack : public s_linked_list{
    public:
        LinkedlistStack(): s_linked_list(){}
        bool isEmpty(){
            return Size() == 0;
        }
        void push(int e){
            push_front(e);
        }
        int pop(){
            if(isEmpty()){
                error ("스택이 비어 있습니다");
            }
            return pop_front();
        }
        int peek(){
            if(isEmpty()){
                error ("스택이 비어 있습니다");
            }
            return head->data;
        }
        void display(){
            node * ptr = head;
            std::cout << "[전체 스택의 수 = " << Size() << "] ";
            for(int i = 0; i < Size(); i++){
                std::cout << "<" << ptr->data << ">";
                ptr = ptr->next;
            }
            std::cout << "\n";
        }
};