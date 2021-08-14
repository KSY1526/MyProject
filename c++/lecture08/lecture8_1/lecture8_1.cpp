#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

template<typename T>
struct node{
    T data;
    node<T> *next = nullptr;
    node<T> *prev = nullptr;
};

template<typename T>
class d_linked_list{
    protected:
        node<T> *head, *tail;
        int length = 0;
    public:
        d_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~d_linked_list(){
            delete_list();
        }

        //삽입연산들
        void push_front(T n); //맨앞추가
        void push_back(T n); //맨뒤추가
        void insert_node_at(int idx, T n);//순서정해서추가

        //삭제연산들
        T pop_front();
        T pop_back();
        T pop_node_at(int idx);
        void delete_list();

        //조회연산들
        T front();
        T back();
        int size();
        void display_contents();

        
};

template<typename T>
void d_linked_list<T>::push_front(T n){
    node<T> *ptr = new node<T>;
    ptr->data = n;
    ptr->next = head;
    if (head == nullptr){
        head = ptr;
        tail = ptr;
    }
    else{
        head->prev = ptr;
        head = ptr;
    }
    length++;
}

template<typename T>
void d_linked_list<T>::push_back(T n){
    node<T> *ptr = new node<T>;
    ptr->data = n;
    ptr->prev = tail;
    if(tail == nullptr){
        head = ptr;
        tail = ptr;
    }
    else{
        tail->next = ptr;
        tail = ptr;
    }
    length++;
}

template<typename T>
void d_linked_list<T>::insert_node_at(int idx, T n){
    if(length < idx || 0 > idx){
        std::cout << "해당 인덱스가 없습니다 \n";
    }
    else if(idx <= length/2){
        node<T> *new_node = new node<T>;
        new_node->data = n;
        node<T> *ptr = head;
        if(idx == 0){
            push_front(n);
        }        
        else{
            for(int i = 0; i < idx; i++){
                ptr = ptr->next;
            }
            new_node->next = ptr;
            if(ptr != nullptr){
                new_node->prev = ptr->prev;
                ptr->prev = new_node;
                if(new_node->prev != nullptr){ // ?
                    new_node->prev->next = new_node;
                }
            }
            
        }
        length++;
    }
    else{
        node<T> *new_node = new node<T>;
        new_node->data = n;
        node<T> * ptr = tail;      
        for(int i = 0; i < length - idx; i++){
            ptr = ptr->prev;
        }
        new_node->next = ptr;
        if(ptr != nullptr){
            new_node->prev = ptr->prev;
            ptr->prev = new_node;
            if(new_node->prev != nullptr){ // ?
                new_node->prev->next = new_node;
            }
        }        
        length++;
    }
}

template<typename T>
T d_linked_list<T>::pop_front(){
    if(length <= 0){
        std::cout << "비어있습니다 \n";
    }
    else {
        node<T> *ptr = head;
        T value = head -> data;
        head = ptr->next;
        if (head == nullptr){//비었을때
            tail = nullptr;
        }
        else{
            head->prev = nullptr;
            if(head->next == nullptr){ //하나남았을때
                tail = head;
            } 
        }
        delete ptr;
        length--;
        return value;
    }
}

template<typename T>
T d_linked_list<T>::pop_back(){
    if(length <= 0){
        std::cout << "비어있습니다 \n";
    }
    else {
        node<T> *ptr = tail;
        T value = tail -> data;
        tail = ptr->prev;
        if (tail == nullptr){//비었을때
            head = nullptr;
        }
        else{
            tail->next = nullptr;
            if(tail->prev == nullptr){ //하나남았을때
                head = tail;
            } 
        }
        delete ptr;
        length--;
        return value;
    }
}

template<typename T>
T d_linked_list<T>::pop_node_at(int idx){
    T value;
    if(length < idx || 0 > idx){
        std::cout << "해당 인덱스가 없습니다 \n";
    }
    else if(idx <= length/2){
        if(idx == 0){
            pop_front();
        }        
        else{
            node<T> *ptr = head;
            for(int i = 0; i < idx; i++){
                ptr = ptr->next;
            }
            if(ptr == tail){ // 길이가 1 인덱스0
                return pop_back();
            }
            value = ptr->data;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            length--;
            delete ptr;
        }
    }
    else{
        node<T> *ptr = tail;
        for(int i = 0; i < length - idx; i++){
            ptr = ptr->prev;
        }
        if(ptr == tail){ // 길이가 1 인덱스0
            return pop_back();
        }
        else{
            value = ptr->data;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            length--;
            delete ptr;
        }
        
    }
    return value;
}

template<typename T>
void d_linked_list<T>::delete_list(){
    node<T> *ptr = head;
    while(ptr != nullptr){
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
}

template<typename T>
T d_linked_list<T>::front(){
    if(length <= 0){
        std::cout << "비어있습니다 \n";
    }
    else {
        return head->data;
    }
}

template<typename T>
T d_linked_list<T>::back(){
    if(length <= 0){
        std::cout << "비어있습니다 \n";
    }
    else {
        return tail->data;
    }
}

template<typename T>
int d_linked_list<T>::size(){
    return length;
}

template<typename T>
void d_linked_list<T>::display_contents(){
    node<T> * ptr = head;
    std::cout << "From head: nullptr->";
    while(ptr != nullptr){
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
    std::cout << "nullptr\n";

    ptr = tail;
    std::cout << "From tail: nullptr->";
    while(ptr != nullptr){
        std::cout << ptr->data << "->";
        ptr = ptr->prev;
    }
    std::cout << "nullptr\n";
}

int main(){
    /*
    d_linked_list<int> list1;
    for(int i = 0; i < 5; i++){
        list1.push_front(i);
        list1.push_back(i);
        list1.insert_node_at(list1.size() - 1, i);
        list1.display_contents();
    }

    for(int i = 0; i < 5; i++){
        list1.pop_front();
    }
    list1.display_contents();

    for(int i = 0; i < 5; i++){
        list1.pop_node_at(list1.size() - 1);
    }
    list1.display_contents();
    */
    int max_iter = 100000;
    d_linked_list<int> sl_list2;
    sl_list2.push_back(10);
    sl_list2.push_back(11);
    sl_list2.push_back(14);
    sl_list2.push_back(18);
    sl_list2.push_back(20);
    sl_list2.push_back(27);

    auto start = chrono::steady_clock::now();
    for (int i = 0; i < max_iter; i++){
        sl_list2.insert_node_at(2,7);
    }
    auto end = chrono::steady_clock::now();
    auto etime = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout << "이중연결리스트 삽입 실행시간: " << etime << "micro sec. \n";
    
    vector<int> v_list2 = {10,11,14,18,20,27};
    start = chrono::steady_clock::now();
    for (int i = 0; i < max_iter; i++){
        v_list2.insert(v_list2.begin() + 2, 7);
    }
    end = chrono::steady_clock::now();
    etime = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout << "이중연결리스트 삽입 실행시간: " << etime << "micro sec. \n";
    return 0;
}