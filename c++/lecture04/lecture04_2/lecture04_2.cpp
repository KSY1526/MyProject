#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

struct node{
    int data;
    node * next;
};

class s_linked_list{
    private:
        node *head, *tail;
        int size = 0;
    public:
        s_linked_list(){
            head = nullptr;
            tail = nullptr;
        } // 생성자
        ~s_linked_list(){
            delete_list();
        } // 소멸자

        // 삽입 연산들
        void push_front(int n); // 맨앞추가
        void push_back(int n); // 맨뒤추가
        void insert_node_at(int idx, int n); // 정해진 위치 추가

        // 삭제 연산들
        int pop_front(); //맨앞 제거
        int pop_back(); //맨뒤 제거
        int pop_node_at(int idx); // 특정순서 지움
        void remove_node(int n); // 값과 같은 노드 지움
        void delete_list(); // 연결리스트 삭제

        // 대입연산
        void replace_value_at(int idx, int n); // 인덱스에 n값 대입

        // 기타연산
        int Size(); // 크기 반환
        void display_contents(); // 연결리스트 구조 반환
        int search_value(int n); // n값 인덱스반환

};

void s_linked_list::push_front(int n){
    node * tmp = new node;
    tmp->next = head; // 원래 가리키던 친구
    tmp->data = n;
    head = tmp;
    size++;
}

void s_linked_list::push_back(int n){
    node * tmp = new node;
    tmp->next = nullptr;
    if (head == nullptr){
        head = tmp;
    }
    else{
        tail->next = tmp;
    }
    tail = tmp;
    tmp->data = n;
    size++;
}

void s_linked_list::insert_node_at(int idx, int n){
    if(size < idx || 0 > idx){
        cout << "해당 인덱스가 없습니다. \n";
    }
    else {
        node *ptr = head;
        node *tmp = ptr;
        node *new_node = new node;
        new_node->data = n;
        new_node->next = nullptr;
        for (int i = 0; i < idx; i++){
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = new_node;
        new_node->next = ptr;
        size++;
    }
}

int s_linked_list::pop_front(){
    node *ptr = head;
    int value = head->data;
    head = ptr->next;
    delete ptr;
    size--;
    return value;
}

int s_linked_list::pop_back(){
    node *ptr = head;
    node *tmp = ptr;
    while(ptr->next != nullptr){
        tmp = ptr;
        ptr = ptr->next;
    }
    int value = ptr->data;
    tail = tmp;
    tail->next = nullptr;
    delete ptr;
    size--;
    return value;
}

int s_linked_list::pop_node_at(int idx){
    int value = -1;
    if(size < idx || 0 > idx){
        cout << "해당 인덱스는 존재하지 않습니다. \n";
    }
    else {
        node *ptr = head;
        node *tmp = ptr;
        for (int i = 0; i < idx; i++){
           tmp = ptr;
           ptr = ptr->next;
        }
        value = ptr->data;
        tmp->next = ptr->next;
        if(ptr == tail){ // ptr이 head라면?
            tail = tmp;
        }
        size--;
        delete ptr;
    }
    return value;           

}

void s_linked_list::remove_node(int n){
    node *ptr = head;
    node *tmp = ptr;
    while(ptr != nullptr){
        if(ptr->data == n){
            break;
        }
        else{
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == nullptr){
        cout << n << "값의 노드는 존재하지 않습니다 \n";
    }
    else {
        size--;
        tmp->next = ptr->next;
        if (ptr == tail){
            tail = tmp;
        }
        delete ptr;
    }
}

void s_linked_list::delete_list(){
    node * ptr = head;
    while (ptr != nullptr){
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    cout << "리스트가 삭제되었습니다 \n";
}

void s_linked_list::replace_value_at(int idx, int n){
    node * ptr = head;
    if (size < idx || 0 > idx){
        cout << "해당 인덱스는 존재하지 않습니다. \n";
    }
    else {
        for (int i = 0; i < idx; i++){
            ptr = ptr->next;
        }
        ptr->data = n;
    }
}

int s_linked_list::Size(){
    return size;
}

void s_linked_list::display_contents(){
    node *ptr = head;
    while(ptr != nullptr){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "nullptr" << "\n";
}

int s_linked_list::search_value(int n){
    node *ptr = head;
    int idx = 0;
    bool isFind = false;
    while (ptr != nullptr){
        if (ptr->data == n){
            cout << n << " 은 " << idx << "에 있습니다. \n";
            isFind = true;
            break;
        }
        ptr = ptr->next;
        idx++;
    }
    if (isFind == false){
        cout << n << "은 리스트 안에 없습니다 \n";
        return -1;
    }
    else { 
        return idx;
    }

}



int main(){/*
    s_linked_list sl_list;
    sl_list.push_back(10);
    sl_list.push_back(11);
    sl_list.push_back(14);
    sl_list.push_back(18);
    sl_list.push_back(20);
    sl_list.push_back(27);
    sl_list.display_contents();

    sl_list.insert_node_at(2,7);
    sl_list.display_contents();
    
    sl_list.push_front(15);
    sl_list.display_contents();

    sl_list.search_value(10);
    sl_list.search_value(40);

    std::cout << sl_list.pop_back() << " 은 맨 뒤에서 지워졌습니다. \n";
    sl_list.display_contents();

    std::cout << sl_list.pop_front() << " 은 맨 앞에서 지워졌습니다. \n";
    sl_list.display_contents();

    sl_list.remove_node(7);
    sl_list.display_contents();
    cout << sl_list.Size() << "\n";
*/
    int max_iter = 100000;
    s_linked_list sl_list2;
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
    cout << "단순연결리스트 삽입 실행시간: " << etime << "micro sec. \n";
    
    vector<int> v_list2 = {10,11,14,18,20,27};
    start = chrono::steady_clock::now();
    for (int i = 0; i < max_iter; i++){
        v_list2.insert(v_list2.begin() + 2, 7);
    }
    end = chrono::steady_clock::now();
    etime = chrono::duration_cast<chrono::microseconds>(end-start).count();
    cout << "단순연결리스트 삽입 실행시간: " << etime << "micro sec. \n";
    
    return 0;
}