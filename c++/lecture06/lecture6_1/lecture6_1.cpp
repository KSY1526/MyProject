#include <iostream>

#define MAX_QUEUE_SIZE 100

inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

class CircularQueue{
    protected:
        int front; // 맨 앞 -1
        int rear; // 맨 뒤
        int data[MAX_QUEUE_SIZE];
    public:
        CircularQueue(){ front = rear = 0;}
        ~CircularQueue(){}
        bool isEmpty(){return front == rear;}
        bool isFull(){
            return (rear + 1) % MAX_QUEUE_SIZE == front;
        }
        void enqueue(int val){
            if(isFull()){
                error("큐가 포화상태입니다. \n");
            }
            else{
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        int dequeue(){
            if(isEmpty()){
                error("큐가 공백상태입니다. \n");
            }
            else{
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front]; 
            }
        }
        int peek(){
            if(isEmpty()){
                error("큐가 공백상태입니다. \n");
            }
            else{
                return data[(front + 1) % MAX_QUEUE_SIZE]; 
            }
        }
        void display(){
            std::cout << "Queue 안에는: ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            // (논리연산) ? 참 : 거짓
            for (int i = front + 1; i <= maxi; i++){
                std::cout << data[i%MAX_QUEUE_SIZE] << " ";
            }
            std::cout << "\n";
        }
};

class CircularDeque: public CircularQueue{
    public:
        CircularDeque(){}
        ~CircularDeque(){}        
        void addFront(int val){
            if(isFull()){
                error("덱이 포화상태입니다. \n");
            }
            else{
                data[front] = val;
                front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }
        void addRear(int val){enqueue(val);}
        int deleteFront(){return dequeue();}
        int deleteRear(){
            if(isEmpty()){
                error("덱가 공백상태입니다. \n");
            }
            else{
                int result = data[rear];
                rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return result; 
            }
        }
        int getFront(){return peek();}
        int getRear(){
            if(isEmpty()){
                error("덱가 공백상태입니다. \n");
            }
            else{
                return data[rear]; 
            }
        }
        void display(){
            std::cout << "Deque 안에는: ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            // (논리연산) ? 참 : 거짓
            for (int i = front + 1; i <= maxi; i++){
                std::cout << data[i%MAX_QUEUE_SIZE] << " ";
            }
            std::cout << "\n";
        }
};


int main(){
    /*CircularQueue que;
    for (int i = 1; i < 10; i++){
        que.enqueue(i);
    }
    que.display();
    que.dequeue();
    que.dequeue();
    que.dequeue();
    que.display();*/
    CircularDeque que2;
    for (int j = 1; j < 10; j++){
        if (j % 2 == 0){que2.addFront(j);}
        else {que2.addRear(j);}
    }
    que2.display();
    que2.deleteFront();
    que2.deleteFront();
    que2.deleteRear();
    que2.display();
    return 0;
}