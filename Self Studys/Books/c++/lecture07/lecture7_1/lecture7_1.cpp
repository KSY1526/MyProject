#include <iostream>
#include <chrono>
#define MAX_LIST_SIZE 100000

inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

class ArrayList{
    private:
        int data[MAX_LIST_SIZE];
        size_t length;
        //size_t == unsigned int 시스템에 따라 다름
        //32비트 os에서는 uint32_t
        //64비트 os에서는 uint64_t
    public:
        ArrayList(){length = 0;}
        ~ArrayList(){}
        void insert(int pos, int e){
            if(!isFull() && pos >= 0 && pos <= length){
                for(int i = length; i > pos; i--){
                    data[i] = data[i - 1];
                }
                data[pos] = e;
                length++;
            }
            else {
                std::cout << "포화상태 또는 삽입 위치가 잘못되었습니다.\n";
            }
        }
        
        void remove(int pos){
            if(!isEmpty() && pos >= 0 && pos < length){
                for(int i = pos + 1; i < length; i++){
                    data[i-1] = data[i];
                }
                length--;
            }
            else {
                std::cout << "공백상태 또는 삭제 위치가 잘못되었습니다.\n";
            }
        }

        int getEntry(int pos){
            return data[pos];
        }

        bool isEmpty(){
            return length == 0;
        }

        bool isFull(){
            return length == MAX_LIST_SIZE;
        }

        bool find(int item){
            for(int i = 0; i < length; i++){
                if(data[i] == item){
                    return true;
                }
            }
            return false; 
        }

        void replace(int pos, int e){
            if(!isEmpty() && pos >= 0 && pos < length){
                data[pos] = e;
            }
            else {
                std::cout << "공백상태 또는 치환 위치가 잘못되었습니다.\n";
            }
        }

        int size(){
            return length;
        }

        void display(){
            std::cout << "Array List의 총 항목수: " << length;
            for(int i = 0; i < length; i++){
                std::cout << " [" << data[i] << "]";
            }
            std::cout << "\n";
        }

        void clear(){
            length = 0;
        }
};





int main(){/*
    ArrayList list;
    list.insert(0,10);
    list.insert(0,20);
    list.insert(1,30);
    list.insert(list.size(),40);
    list.insert(2,50);
    list.display();

    list.remove(2);
    list.remove(list.size() -1);
    list.remove(0);
    list.replace(1,90);
    list.display();*/
    ArrayList list2;
    auto end = std::chrono::steady_clock::now();
    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i < 10000; i++){
        list2.insert(list2.size(),0);
        if(i%1000 == 999){
            end = std::chrono::steady_clock::now();
            std::cout << i << "번째 삽입: ";
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << "\n";
            start = std::chrono::steady_clock::now();
        }
    }
    
    start = std::chrono::steady_clock::now();
    for(int i = 0; i < 10000; i++){
        list2.remove(list2.size()-1);
        if(i%1000 == 999){
            end = std::chrono::steady_clock::now();
            std::cout << i << "번째 삭제: ";
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << "\n";
            start = std::chrono::steady_clock::now();
        }
    }




    return 0;
}