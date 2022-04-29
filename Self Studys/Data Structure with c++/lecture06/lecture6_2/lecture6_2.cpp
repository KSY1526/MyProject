#include <iostream>
#include "SingleLinkedList.h"

inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

class LinkedListQueue : public s_linked_list{
    public:
        LinkedListQueue() : s_linked_list(){}
        ~LinkedListQueue(){}
        bool isEmpty(){return Size() == 0;}
        void enqueue(int e){push_back(e);}
        int dequeue(){
            if(isEmpty()){
                error("큐가 비어있습니다.");
            }
            return pop_front();
        }
        int peek(){
            if(isEmpty()){
                error("큐가 비어있습니다.");
            }
            return head->data;
        }
        void display(){
            std::cout << "큐 안에는 : ";
            node *ptr = head;
            while(ptr != nullptr){
                std::cout << ptr->data << " ";
                ptr = ptr->next;
            }
            std::cout << "\n";
        }
};


int main(){
    LinkedListQueue que;
    for (int i = 1; i < 10; i++){
        que.enqueue(i);
    }
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();
}