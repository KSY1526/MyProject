#include <iostream>
#include <random>
#include <ctime> // == time.h
// rand() 아주 안좋음

#define MAX_QUEUE_SIZE 100

//난수만들어내는 방법 빠르고 좋음 가짜난수.
//2^19937-1소수 기반으로 만듬. 파이썬 난수추출기법.
static std::mt19937 gen = std::mt19937((unsigned int)time(NULL));
static std::uniform_real_distribution<> dist(0, 1);

// dist(gen) 랜덤넘버를 만들어줌 rand()는 쓰래기.


inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

struct Customer{
    int id; // 손님 번호
    int tArrival; // 손님 도착 시간
    int tService; // 손님 서비스 시간
    Customer(int i = 0, int tArr = 0, int tServ = 0)
        : id(i), tArrival(tArr), tService(tServ){}
    ~Customer(){}
};

class CustomerQueue{
    private:
        int front;
        int rear;
        Customer data[MAX_QUEUE_SIZE];
    public:
        CustomerQueue(){front = rear = 0;}
        ~CustomerQueue(){}
        bool isEmpty(){return front == rear;}
        bool isFull(){
            return (rear + 1) % MAX_QUEUE_SIZE == front;
        }
        void enqueue(Customer& val){
            if(isFull()){
                error("큐가 포화상태입니다. \n");
            }
            else{
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        Customer& dequeue(){
            if(isEmpty()){
                error("큐가 공백상태입니다. \n");
            }
            else{
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front]; 
            }
        }

};

class BankSimulator{
    private:
        int nSimulation; // 최대 몇번까지 시뮬레이션 할건지
        double probArrival; // 손님이 도착할 확률
        int tMaxService; // 손님이 최대로 쓸수 있는 시간

        int totalWaitTime; //한사람 한사람 대기한 시간 합 결과확인1
        int nCustomers; // 손님이 얼마나 있는지 결과확인2
        int nServedCustomers; // 손님이 얼마나 서비스 받았는지 결과확인3
        CustomerQueue que; // 손님이 대기하는 큐
        bool isNewCustomer(){return dist(gen) < probArrival;}
        // 손님이 있는지. 테스트. 미리 지정한 확률보다 랜덤값이 작으면 생김
        int randServiceTime(){
            return (int)tMaxService*dist(gen) + 1;
            // 1부터 최대 값까지 확률. 최대값이 될 가능성은 없음.
        }   
        void insertCustomer(int arrivalTime){
            Customer a(++nCustomers, arrivalTime, randServiceTime());
            //현재 있는 사람보다 한사람 많은 아이디
            //도착시간 이미 기록, 서비스는 함수로 만듬.
            std::cout << "고객 " << a.id << " 방문 (서비스 시간: " << a.tService << "분) \n";
            que.enqueue(a);
        }      
    public:
        BankSimulator() : nCustomers(0), totalWaitTime(0), nServedCustomers(0){}
        void readSimulationParameters(){
            std::cout << "시뮬레이션 할 최대 시간 (예:10) = ";
            std::cin >> nSimulation;
            std::cout << "단위시간에 도착하는 고객 수 (예: 0.5) = ";
            std::cin >> probArrival;
            std::cout << "한 고객에 대한 최대 서비스 시간 (예: 5) = ";
            std::cin >> tMaxService;
        }
        void run(){
            int clock = 0;
            int serviceTime = -1; // 아무도 없을때 -1
            while(clock < nSimulation){
                clock++;
                std::cout << "현재시각: " << clock << "\n";
                if(isNewCustomer()){
                    insertCustomer(clock);
                }
                if(serviceTime >0){
                    serviceTime--;
                    //개별 고객이 서비스 받는 시각
                }
                else{ // 서비스 받는 사람이 없으면
                    if(que.isEmpty()){continue;}
                    //큐에 값이 없을때(대기손님x) 그냥 진행
                    Customer a = que.dequeue(); // 큐에 값이 있을때
                    nServedCustomers++;
                    totalWaitTime += clock - a.tArrival;
                    // 현재시각에서 손님 도착시간 빼기 기다린 시각
                    std::cout << "고객 " << a.id << " 서비스 시작 \n";
                    std::cout << "대기시간: " << clock - a.tArrival << "분\n";
                    serviceTime = a.tService - 1; // 1분 이미 소요.
                }
            }
        }
        void printStat(){
            std::cout << "--------------------------------\n";
            std::cout << "서비스 받는 고객 수: " << nServedCustomers << "명\n";
            std::cout << "전체 대기 시간: " << totalWaitTime << "분\n";           
            std::cout << "서비스 받는 고객 평균 대기 시간: " << (double)totalWaitTime/nServedCustomers << "분/명\n";
            std::cout << "현재 대기 고객 수: " << nCustomers - nServedCustomers << "명\n";
        }
};

int main(){
    BankSimulator sim;
    sim.readSimulationParameters();
    sim.run();
    sim.printStat();
    return 0;
}