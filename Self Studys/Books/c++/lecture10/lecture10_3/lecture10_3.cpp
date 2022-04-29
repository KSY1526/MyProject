#include <iostream>


#define MAX_QUEUE_SIZE 100

inline void error(const char* str){
    std::cerr << str << "\n"; // 에러의 경우는 std::cerr로 출력합니다.
    exit(1);
};

class BinaryNode{
    protected:
        int data;
        BinaryNode *left;
        BinaryNode *right;

    public:
        BinaryNode(int val=0, BinaryNode *l=nullptr, BinaryNode *r=nullptr)
                :data(val), left(l), right(r){}
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
        BinaryNode* getLeft(){
            return left;
        }
        BinaryNode* getRight(){
            return right;
        } 
        bool isLeaf(){
            return left==nullptr && right==nullptr;
        }
};

class CircularQueue{
    protected:
        int front; // 가장 앞 (데이터를 꺼내는 위치)
        int rear; // 가장 뒤 (데이터를 넣는 위치)
        BinaryNode* data[MAX_QUEUE_SIZE];    
    public:
        CircularQueue(){front = rear = 0;}
        ~CircularQueue(){}
        bool isEmpty(){return front == rear;}
        bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;} // 나머지 연산으로 위치를 찾습니다.
        void enqueue(BinaryNode* val){ // 큐 맨 뒤에 데이터를 추가
            if(isFull()){
                error(" Error: 큐가 포화상태입니다\n");
            }
            else{
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        BinaryNode*	dequeue(){ // 큐 맨 앞에서 데이터를 꺼냄
            if(isEmpty()){
                error(" Error: 큐가 공백상태입니다\n");
            }
            else{
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
};

class BinaryTree{
    protected:
        BinaryNode* root;
        // 트리의 순회연산 (2주차)

    public:
        BinaryTree(): root(nullptr){}
        ~BinaryTree(){}

        void setRoot(BinaryNode* node){
            root = node;
        }
        BinaryNode* getRoot(){
            return root;
        }
        bool isEmpty() {
            return root==nullptr;
        }

        void inorder(BinaryNode *node){
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    inorder(node->getLeft());
                }
                std::cout << " [" << node->getData() << "] ";
                if(node->getRight()!= nullptr){
                    inorder(node->getRight());
                }
            }
        }       
        void inorder(){
            std::cout << "inorder: ";
            inorder(root);
            std::cout << "\n";            
        }        
        void preorder(BinaryNode *node){
            if(node != nullptr){
                std::cout << " [" << node->getData() << "] ";
                if(node->getLeft() != nullptr){
                    preorder(node->getLeft());
                }
                if(node->getRight()!= nullptr){
                    preorder(node->getRight());
                }                
            }
        }

        void postorder(BinaryNode *node) {
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    postorder(node->getLeft());
                }
                if(node->getRight()!= nullptr){
                    postorder(node->getRight());
                }
                std::cout << " [" << node->getData() << "] ";
            }
        }

        void preorder(){
            std::cout << "preorder: ";
            preorder(root);
            std::cout << "\n";
        }
        void postorder(){
            std::cout << "postorder: ";
            postorder(root);
            std::cout << "\n";
        }
        
        void levelorder(){
            std::cout << "levelorder: ";
            if(!isEmpty()){
                CircularQueue q;
                q.enqueue(root);
                while (!q.isEmpty()){
                    BinaryNode* n = q.dequeue();
                    if(n != nullptr){
                        std::cout << " [" << n->getData() << "] ";
                        q.enqueue(n->getLeft ());
                        q.enqueue(n->getRight());
                    }
                }
            }
            std::cout << "\n";
        }

        int getCount(){
            return isEmpty() ? 0 : getCount(root);
        }
        
        int getCount(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return 1 + getCount(node->getLeft()) + getCount(node->getRight());
        }
        int	getLeafCount(){
            return isEmpty() ? 0 : getLeafCount(root);
        }
        int getLeafCount(BinaryNode *node) {
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){
                return 1;
            }
            else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
        }
        int	getHeight(){
            return isEmpty() ? 0 : getHeight(root);
        }
        int getHeight(BinaryNode *node) {
            if(node == nullptr){
                return 0;
            }
            int hLeft  = getHeight(node->getLeft());
            int hRight = getHeight(node->getRight());
            return (hLeft>hRight) ? hLeft+1 : hRight+1;
        }
        
        int calcSize(){
            return calcSize(root);
        }
        int calcSize(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
        }

        int evaluate(){ // 수식 계산 함수
            return evaluate(root);
        }
        int evaluate(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()) return node->getData();
            else {
                int op1 = evaluate(node->getLeft());
                int op2 = evaluate(node->getRight());
                switch(node->getData()){
                    case '+': return op1+op2;
                    case '-': return op1-op2;
                    case '*': return op1*op2;
                    case '/': return op1/op2;
                }
                return 0;
            }
        }



};

class BinSrchTree : public BinaryTree{
    public:
        BinSrchTree(void){}
        ~BinSrchTree(void){}

        BinaryNode* search(int key){
            BinaryNode * node = search(root, key);
            if(node != nullptr){
                std::cout << "탐색 성공. Key: " << key << "\n";
            }
            else{
                std::cout << "탐색 실패. Key: " << key << "\n";
            }
            return node;
        }

        BinaryNode* search(BinaryNode * n, int key){
            if(n == nullptr){
                return nullptr;
            }
            if(key == n->getData()){
                return n;
            }
            else if(key < n->getData()){
                return search(n->getLeft(),key);
            }
            else{
                return search(n->getRight(),key);
            }
        }

        void insert(BinaryNode* n){
            if(n == nullptr){
                return;
            }
            if(isEmpty()){
                root = n;
            }
            else{
                insert(root, n);
            }
        }


        void insert(BinaryNode* r, BinaryNode* n){
        //r : 현재 탐색중인 노드, n : 집어넣은 노드
            if(n->getData() == r->getData()){
                return;
                //중복허용 x
            }
            else if(n->getData() < r->getData()){
                if(r -> getLeft() == nullptr){
                    r->setLeft(n);
                }
                else{
                    insert(r->getLeft(),n);
                }
            }
            else{
                if(r->getRight() == nullptr){
                    r->setRight(n);
                }
                else{
                    insert(r->getRight(),n);
                }
            }
        }


        void remove(int data){
            // 주 위치를 찾는 함수
            if(isEmpty()){
                return;
            }
            BinaryNode* parent = nullptr;
            BinaryNode* node = root;
            while(node != nullptr && node->getData() != data){
                parent = node;
                node = (data < node->getData()) ? node->getLeft() : node->getRight();
            }
            if(node == nullptr){
                //반목문 탈출조건 첫번째임
                //1.계속찾앗는데 노드x, 2.찾음
                std::cout << "Key " << data << " does not exist";
            }
            else{
                remove(parent, node);
            }
        }

        void remove(BinaryNode* parent, BinaryNode* node){
            //1번 : 삭제위치가 단말노드인 경우 그냥 지움
            if(node->isLeaf()){
                if(parent==nullptr){ //node = 루트.
                    root=nullptr;
                }
                else{
                    if(parent->getLeft() == node){
                        parent->setLeft(nullptr);
                    }
                    else{
                        parent->setRight(nullptr);
                    }
                }
            }
            //2번 : 삭제위치 한쪽자식있는경우 그냥 연결
            // parent->node->child
            else if(node->getLeft() == nullptr || node->getRight() == nullptr){
                BinaryNode* child = (node->getRight() != nullptr) ? node->getRight() : node->getLeft();
                if(node == root){
                    root = child;
                }
                else{
                    if(parent->getLeft() == node){
                        parent->setLeft(child);
                    }
                    else{
                        parent->setRight(child);
                    }
                }
            }
            //3번 : 양쪽서브트리가 다 있는경우
            //오른쪽트리를 기준으로 작업.
            else{
                BinaryNode* succp = node; //계승자의 부모
                BinaryNode* succ = node->getRight();//계승자
                while(succ->getLeft() != nullptr){
                    succp = succ;
                    succ = succ->getLeft();
                    //오른쪽트리에서 가장 작은 노드 찾음
                }
                if(succp->getLeft() == succ){
                    succp->setLeft(succ->getRight());
                    //계승자의 부모는 계승자 대신 다른 자식을 찾음.
                    //계승자는 왼쪽 자식이 없음.
                }
                else{
                    //후계노드가 삭제할 노드의 바로 오른쪽자식인경우
                    //오른쪽 자식의 왼쪽 자식노드가 없는경우
                    succp->setRight(succ->getRight());
                }
                node->setData(succ->getData());
                node = succ;
                //계승자를 노드로 바꿈. 실제로 계승자가 사라짐.
            }
            delete node;
        }
};





int main(){
    BinSrchTree tree;
    // 삽입 연산 테스트
    tree.insert(new BinaryNode(35));
    tree.insert(new BinaryNode(18));
    tree.insert(new BinaryNode(7));
    tree.insert(new BinaryNode(26));
    tree.insert(new BinaryNode(12));
    tree.insert(new BinaryNode(3));
    tree.insert(new BinaryNode(68));
    tree.insert(new BinaryNode(22));
    tree.insert(new BinaryNode(30));
    tree.insert(new BinaryNode(99));

    std::cout << "노드의 수: " << tree.getCount() << "\n";
    std::cout << "단말의 수: " << tree.getLeafCount() << "\n";
    std::cout << "트리의 높이: " << tree.getHeight() << "\n";

    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.levelorder();

    tree.search(26);
    tree.search(25);

    // 삭제 연산 테스트
    std::cout << "삭제 case 1: 노드 3 삭제\n";
    tree.remove(3);
    tree.inorder();
    std::cout << "삭제 case 2: 노드 68 삭제\n";
    tree.remove(68);
    tree.inorder();
    std::cout << "삭제 case 3: 노드 18 삭제\n";
    tree.remove(18);
    tree.inorder();
    std::cout << "삭제 case 3: 노드 35 (루트 노드) 삭제\n";
    tree.remove(35);
    tree.inorder();

    // 최종 트리 정보 출력
    std::cout << "노드의 수: " << tree.getCount() << "\n";
    std::cout << "단말의 수: " << tree.getLeafCount() << "\n";
    std::cout << "트리의 높이: " << tree.getHeight() << "\n";
    return 0;
}