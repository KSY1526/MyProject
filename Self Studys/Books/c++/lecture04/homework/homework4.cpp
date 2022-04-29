#include <iostream>
using namespace std;

struct node{
    int data;
    node * next;
};

class s_linked_list {
    private:
        node *head, *tail;
        int size;
    public:
        s_linked_list(){ //생성자
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        ~s_linked_list(){ //소멸자
            delete_list(); // 연결리스트 전체 삭제 함수 호출
        }
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
        int search_value(int n); // 주어진 값 인덱스반환

        // 조회연산(추가함수)
        int search_value2(int idx); // 인덱스 넣으면 값  호출함수.    
};

void s_linked_list::push_front(int n){ // 맨 앞 노드 추가
    node * new_node = new node;
    new_node->next = head;
    if (tail == nullptr){ // 만약 첫번째 노드 추가라면
        tail = new_node; // 이 노드가 꼬리 노드이기도 함
    }
    head = new_node;
    new_node->data = n;
    size++;
}

void s_linked_list::push_back(int n){ // 맨 뒤 노드 추가
    node * new_node = new node;
    new_node->next = nullptr;
    if (head == nullptr){ // 만약 첫번째 노드 추가라면
        head = new_node; // 이 노드가 헤드 노드이기도 함
    }
    else {
        tail->next = new_node;
    }
    tail = new_node;
    new_node->data = n;
    size++;
}

void s_linked_list::insert_node_at(int idx, int n){ // 정해진 위치 노드 추가
    if (size < idx || idx < 0){
        cout << "해당 인덱스가 없습니다. \n";
    }
    else if (idx == 0) { // 0번째 인덱스 입력시
        push_front(n); // 첫번째 함수 대입, head 지정 때문에 분류
    }
    else if (idx == size){ //마지막 인덱스 입력시
        push_back(n); // 테일에 값 넣는 함수 대입 tail 지정 때문에 분류
    }
    else{
        node * ptr = head; // 대입 노드 다음노드
        node * tmp = ptr; // 대입 노드 전 노드
        node * new_node = new node;
        for (int i = 0; i < idx; i++){ 
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = new_node;
        new_node->next = ptr;
        new_node->data = n;
        size++;
    }
}


int s_linked_list::pop_front(){  //맨 앞 노드 제거
    node * ptr = head;
    int value = ptr->data;
    head = ptr->next;
    delete ptr;
    size--;
    return value;
}

int s_linked_list::pop_back(){ //맨 뒤 노드 제거
    node * ptr = head;
    node * tmp = ptr;
    while (ptr->next != nullptr){
        tmp = ptr;
        ptr = ptr->next;
    } // ptr = tail, tmp = tail 전 노드
    int value = ptr->data;
    tail = tmp;
    tmp->next = nullptr;
    delete ptr;
    size--;
    return value;
} 

int s_linked_list::pop_node_at(int idx){ // 특정 순서 노드 제거
    int value = -1;
    if(size <= idx || 0 > idx){ // size == idx 는 불가능함. 사이즈와 같은 크기 인덱스 없음.
        cout << "해당 인덱스는 존재하지 않습니다. \n";
    }
    else {
        node * ptr = head;
        node * tmp = ptr;
        for (int i = 0; i < idx; i++){
            tmp = ptr;
            ptr = ptr->next;
        }
        value = ptr->data;
        tmp->next = ptr->next;
        if (ptr == head){
            head = ptr->next;
        }
        if (ptr == tail){
            tail = tmp;
        }
        size--;
        delete ptr;
    }
    return value;
} 

void s_linked_list::remove_node(int n){ // 값과 같은 노드 제거
    node * ptr = head;
    node * tmp = ptr;
    while (ptr != nullptr){ // 값과 같은게 안나오면 ptr을 테일 다음값 까지 돌림. 
        if (ptr->data == n){
            break;
        }
        else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == nullptr){
        cout << n << "값의 노드는 존재하지 않습니다 \n";
    }
    else {
        tmp->next = ptr->next;
        if (ptr == head){
            head = ptr->next;
        }
        if (ptr == tail){
            tail = tmp;
        }
        size--;
        delete ptr;
    }
} 

void s_linked_list::delete_list(){ // 연결리스트 삭제
    node * ptr = head;
    while (ptr != nullptr){
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    cout << "리스트가 삭제되었습니다 \n";
} 


void s_linked_list::replace_value_at(int idx, int n){ // 인덱스에 n값 대입
    node * ptr = head;
    if (size <= idx || 0 > idx){ // size = idx 만족하는 idx 없습니다.
        cout << "해당 인덱스는 존재하지 않습니다. \n";
    }
    else {
        for (int i = 0; i < idx; i++){
            ptr = ptr->next;
        }
        ptr->data = n;
    }
} 


int s_linked_list::Size(){ // 연결 리스트 크기 반환
    return size;
} 

void s_linked_list::display_contents(){ // 연결리스트 구조 반환
    node * ptr = head;
    while(ptr != nullptr){
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "nullptr" << "\n";
} 

int s_linked_list::search_value(int n){ // n값 인덱스반환
    node * ptr = head;
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

// 인덱스에 맞는 데이터 추출 함수
int s_linked_list::search_value2(int idx){
    node * ptr = head;
    if (size <= idx || 0 > idx){ // size = idx 만족하는 idx 없습니다.
        cout << "해당 인덱스는 존재하지 않습니다. \n";
        return -1;
    }
    else {
        for (int i = 0; i < idx; i++){
            ptr = ptr->next;
        }
        return ptr->data;
    }
}


void GenerateList(s_linked_list * generate_list, int n){
    for (int i = 0; i < n; i++){
        generate_list->push_back(i);
    }
}

void CopyLStoDA(int arr[], s_linked_list * linked_list){
    for (int i = 0; i < linked_list->Size(); i++){
        arr[i] = linked_list->search_value2(i);
    }
}

int main(){
    int n;
    cout << "길이를 입력하세요. \n";
    cin >> n;
    s_linked_list * generate_list = new s_linked_list; // ** 반드시 동적할당 필요.
    GenerateList(generate_list, n);
    generate_list->display_contents();
    int * arr = new int[generate_list->Size()]; // 리스트와 같은 크기의 배열 동적할당
    CopyLStoDA(arr, generate_list);
    for (int i = 0; i < generate_list->Size(); i++){
        cout << "Arr[" << i << "] 값은 " << arr[i] << " 입니다. \n";
    }
    return 0;
}