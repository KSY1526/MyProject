#include <iostream>

#define MAX_QUEUE_SIZE 100

inline void error(const char* str){
    std::cerr << str << "\n";
    exit(1);
};

class BinaryNode{
    protected:
        int data;
        BinaryNode *left;
        BinaryNode *right;
    
    public:
        BinaryNode(int val = 0, BinaryNode *l = nullptr, BinaryNode *r = nullptr)
            : data(val), left(l), right(r){}
        ~BinaryNode(){}
        void setData(int val){
            data = val;
        }
        void setLeft(BinaryNode *l){
            left = l;
        }
        void setRight(BinaryNode *r){
            right = r;
        }
        int getData(){
            return data;
        }
        BinaryNode *getLeft(){
            return left;
        }
        BinaryNode *getRight(){
            return right;
        }
        bool isLeaf(){
            return left==nullptr && right==nullptr;
        }
};

class CircularQueue{
    protected:
        int front; // 맨 앞 -1
        int rear; // 맨 뒤
        BinaryNode* data[MAX_QUEUE_SIZE];
    public:
        CircularQueue(){ front = rear = 0;}
        ~CircularQueue(){}
        bool isEmpty(){return front == rear;}
        bool isFull(){
            return (rear + 1) % MAX_QUEUE_SIZE == front;
        }
        void enqueue(BinaryNode* val){
            if(isFull()){
                error("큐가 포화상태입니다. \n");
            }
            else{
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        BinaryNode* dequeue(){
            if(isEmpty()){
                error("큐가 공백상태입니다. \n");
            }
            else{
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front]; 
            }
        }
        BinaryNode* peek(){
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

class BinaryTree{
    private:
        BinaryNode *root;
    public:
        BinaryTree(): root(nullptr){}
        ~BinaryTree(){}
        void setRoot(BinaryNode *node){
            root = node; 
        }
        BinaryNode * getRoot(){
            return root;
        }
        bool isEmpty(){
            return root == nullptr;
        }

        void preorder(BinaryNode *node){
            if(node != nullptr){
                std::cout << " [" << node->getData() << "]";
                if(node->getLeft() != nullptr){
                    preorder(node->getLeft());
                }                
                if(node->getRight() != nullptr){
                    preorder(node->getRight());
                }
            }
        }
        void preorder(){
            std::cout << "preorder: ";
            preorder(root);
        }

        void inorder(BinaryNode *node){
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    inorder(node->getLeft());
                }
                std::cout << " [" << node->getData() << "]";
                if(node->getRight() != nullptr){
                    inorder(node->getRight());
                }
            }
        }
        void inorder(){
            std::cout << "inorder: ";
            inorder(root);
        }

        void postorder(BinaryNode *node){
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    postorder(node->getLeft());
                }                
                if(node->getRight() != nullptr){
                    postorder(node->getRight());
                }
                std::cout << " [" << node->getData() << "]";
            }
        }
        void postorder(){
            std::cout << "postorder: ";
            postorder(root);
        }
        
        void levelorder(){
            std::cout << "levelorder: ";
            if(!isEmpty()){
                CircularQueue q;
                q.enqueue(root);
                while(!q.isEmpty()){
                    BinaryNode * n = q.dequeue();
                    if(n != nullptr){
                        std::cout << " [" << n->getData() << "]";
                        q.enqueue(n->getLeft());
                        q.enqueue(n->getRight());
                    }
                }
            }
        }

        int getCount(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return 1 + getCount(node->getLeft()) + getCount(node->getRight()); 
        }
        int getCount(){
            return isEmpty() ? 0 : getCount(root);
        }

        int getLeafCount(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){
                return 1;
            }
            return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
        }
        int getLeafCount(){
            return isEmpty() ? 0 : getLeafCount(root);
        }

        int getHeight(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            int hLeft = getHeight(node->getLeft());
            int hRight = getHeight(node->getRight());
            return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
        }
        int getHeight(){
            return isEmpty() ? 0 : getHeight(root);
        }

        int evaluate(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){
                return node->getData();
            }
            else {
                int op1 = evaluate(node->getLeft());
                int op2 = evaluate(node->getRight());
                switch (node->getData()){
                    case '+' : return op1+op2;
                    case '-' : return op1-op2;
                    case '*' : return op1*op2;
                    case '/' : return op1/op2;
                }
                return 0;
            }
        }
        int evaluate(){
            return evaluate(root);
        }

        int calcSize(BinaryNode * node){
            if(node == nullptr){
                return 0;
            }
            return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
        }
        int calcSize(){
            return calcSize(root);
        }
};

int main(){
    BinaryTree tree;
    //        a1
    //      b2    c3
    //    d4  e5 f6
    BinaryNode *d = new BinaryNode(4, nullptr, nullptr);
    BinaryNode *e = new BinaryNode(5, nullptr, nullptr);
    BinaryNode *b = new BinaryNode(2, d, e);
    BinaryNode *f = new BinaryNode(6, nullptr, nullptr);
    BinaryNode *c = new BinaryNode(3, f, nullptr);
    BinaryNode *a = new BinaryNode(1, b, c);
    tree.setRoot(a);
    tree.preorder();
    std::cout << "\n";
    tree.inorder();
    std::cout << "\n";
    tree.postorder();
    std::cout << "\n";
    tree.levelorder();
    std::cout << "\n";

    std::cout << "노드의 수 : " << tree.getCount() << "\n";
    std::cout << "잎 노드의 수 : " << tree.getLeafCount() << "\n";
    std::cout << "트리의 높이 : " << tree.getHeight() << "\n";
    BinaryTree tree2;
    //        +
    //    *        -
    //  3   2    5    6
    BinaryNode *n1 = new BinaryNode(3, nullptr, nullptr);
    BinaryNode *n2 = new BinaryNode(2, nullptr, nullptr);
    BinaryNode *n3 = new BinaryNode('*', n1, n2);
    BinaryNode *n4 = new BinaryNode(5, nullptr, nullptr);
    BinaryNode *n5 = new BinaryNode(6, nullptr, nullptr);
    BinaryNode *n6 = new BinaryNode('-', n4, n5);
    BinaryNode *n7 = new BinaryNode('+', n3, n6);
    tree2.setRoot(n7);
    std::cout << "계산 결과: " << tree2.evaluate() << "\n";

    BinaryTree tree3;
    //            0
    //       50        100
    //               200  500  
    BinaryNode *m4 = new BinaryNode(200, nullptr, nullptr);
    BinaryNode *m5 = new BinaryNode(500, nullptr, nullptr);
    BinaryNode *m3 = new BinaryNode(100, m4, m5);
    BinaryNode *m2 = new BinaryNode(50, nullptr, nullptr);
    BinaryNode *m1 = new BinaryNode(0, m2, m3);
    tree3.setRoot(m1);
    std::cout << "용량 계산 결과: " << tree3.calcSize() << "\n";
    return 0;
}