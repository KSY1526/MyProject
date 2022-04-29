#include <iostream>

class ThreadedBinNode{
    protected:
        int data;
        ThreadedBinNode *left;
        ThreadedBinNode *right;

    public:
        bool bThread;
        ThreadedBinNode(int val = 0, ThreadedBinNode *l = nullptr,
         ThreadedBinNode *r = nullptr, bool bTh = false)
            : data(val), left(l), right(r), bThread(bTh){}
        ThreadedBinNode(){}
        void setData(int val){
            data = val;
        }
        void setLeft(ThreadedBinNode *l){
            left = l;
        }
        void setRight(ThreadedBinNode *r){
            right = r;
        }
        int getData(){
            return data;
        }
        ThreadedBinNode *getLeft(){
            return left;
        }
        ThreadedBinNode *getRight(){
            return right;
        }
        bool isLeaf(){
            return left==nullptr && right==nullptr;
        }
};

class ThreadedBinTree{
    private:
       ThreadedBinNode *root;
    public:
        ThreadedBinTree(): root(nullptr){}
        ~ThreadedBinTree(){}
        void setRoot(ThreadedBinNode *node){
            root = node; 
        }
        ThreadedBinNode * getRoot(){
            return root;
        }
        bool isEmpty(){
            return root == nullptr;
        }
        void threadedInorder(){
            if(!isEmpty()){
                std::cout << "트레드 트리 inorder: ";
                ThreadedBinNode *q = root;
                while(q->getLeft()){
                    q = q->getLeft();
                }
                do{
                    std::cout << " [" << q->getData() << "]";
                    q = findSuccessor(q);
                }while(q);
                std::cout << "\n";
            }
            
        }
        ThreadedBinNode *findSuccessor(ThreadedBinNode* p){
            ThreadedBinNode *q = p->getRight();
            if(q == nullptr || p->bThread){ // 쓰레드이면 오른쪽 == 중위수 연결, 널이면(마지막임) 널값반환
                return q;
            }
            while(q->getLeft() != nullptr){ // 오른쪽 자식이 쓰레드형식x 정상적으로 있다면
                q = q->getLeft(); // 오른쪽 자식 왼쪽부분으로 넘겨버림
            }
            return q;
        }
};

int main(){
    ThreadedBinTree tree2;
    //        7
    //    3        6
    //  1   2    4    5
    ThreadedBinNode *n1 = new ThreadedBinNode(1, nullptr, nullptr, true);
    ThreadedBinNode *n2 = new ThreadedBinNode(2, nullptr, nullptr, true);
    ThreadedBinNode *n3 = new ThreadedBinNode(3, n1, n2, false);
    ThreadedBinNode *n4 = new ThreadedBinNode(4, nullptr, nullptr, true);
    ThreadedBinNode *n5 = new ThreadedBinNode(5, nullptr, nullptr, false);
    ThreadedBinNode *n6 = new ThreadedBinNode(6, n4, n5, false);
    ThreadedBinNode *n7 = new ThreadedBinNode(7, n3, n6, false);
    tree2.setRoot(n7);

    n1->setRight(n3);
    n2->setRight(n7);
    n4->setRight(n6);

    tree2.threadedInorder();
    return 0;
}