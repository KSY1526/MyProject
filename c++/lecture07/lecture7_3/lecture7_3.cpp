#include <iostream>
#include <string>
inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

class node{
    private:
        int data;
        node* next;
    public:
        node(int val = 0){
            data = val;
            next = nullptr;
        }

        node* getLink(){
            return next;
        }

        int getData(){
            return data;
        }

        void setLink(node* target){
            next = target;
        }

        void insertNext(node* newnode){
            if(newnode != nullptr){
                newnode->next = next; 
                next = newnode;
            }
        }

        node* removeNext(){
            node* removed = next;
            if(removed != nullptr){
                next = removed -> next;
            }
            return removed;
        }

};

class hn_s_linked_list{
    protected:
        node origin;
    public:
        hn_s_linked_list(): origin(0){}
        ~hn_s_linked_list(){ clear();}

        void clear(); // 리스트 삭제연산
        node* getHead(); // 첫 노드 부르는 연산
        bool isEmpty(); // 공백확인

        node* getEntry(int pos);
        void insert(int pos, node* n);
        node* remove(int pos);
        node* find(int Value);
        void replace(int pos, node* n);
        size_t size();
        void display();
};

void hn_s_linked_list::clear(){
    while(!isEmpty()){
        delete remove(0);
    }
}

node* hn_s_linked_list::getHead(){
    return origin.getLink();
} // 첫 노드 부르는 연산

bool hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
}

//pos번째 항목 반환
node* hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for(int i = -1; i < pos; i++, n = n->getLink()){
        if(n==nullptr){
            break;
        }
    }
    return n;
}

void hn_s_linked_list::insert(int pos, node* n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        prev->insertNext(n);
    }
}

node* hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        return prev->removeNext();
    }
}

node* hn_s_linked_list::find(int value){
    for(node* p = getHead(); p != nullptr; p = p->getLink()){
        if(p->getData() == value){
            return p;
        }
    }
    return nullptr;
}

void hn_s_linked_list::replace(int pos, node* n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }
}

size_t hn_s_linked_list::size(){
    int count = 0;
    for (node* p = getHead(); p != nullptr; p = p->getLink()){
        count++;
    }
    return count;
}

void hn_s_linked_list::display(){
    std::cout << "전체 항목의 수 " << size() << ", ";
    for (node* p = getHead(); p != nullptr; p = p->getLink()){
        std::cout << p->getData() << " ";
    }
    std::cout << "\n";
}



int main(){/*
    hn_s_linked_list list;
    list.insert(0, new node(10));
    list.insert(0, new node(20));
    list.insert(1, new node(30));
    list.insert(list.size(), new node(40));
    list.insert(2, new node(50));
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, new node(90));
    list.display();

    list.clear();
    list.display();*/
    hn_s_linked_list list2;
    list2.insert(0, new node(1));
    list2.insert(1, new node(2));
    list2.insert(2, new node(3));
    list2.insert(3, new node(4));
    hn_s_linked_list list3;
    for (int i = list2.size() - 1; i >= 0; i--){
        list3.insert(list3.size(), new node(list2.getEntry(i)->getData()));
    }
    list3.display();
    return 0;
}