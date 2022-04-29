#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CircularQueue.h"
//#include "ArrayStack.h"
#define MAX_VTXS 256

class Node{
    protected:
        int id;
        Node* link;
    public:
        Node(int i, Node* l = nullptr) : id(i), link(l) {}
        ~Node(void){
            if(link != nullptr){
                delete link;
            }
        }
        int getId() { return id; }
        Node* getLink() { return link; }
        void setLink(Node* l) { link = l;}
};

class AdjListGraph{
    protected:
        int size; //그래프 사이즈 = 정점의 개수
        std::string vertices[MAX_VTXS]; // 정점 이름
        Node* adj[MAX_VTXS]; 
    
    public:
        AdjListGraph(void) : size(0) {}
        ~AdjListGraph(void){ reset(); }

        std::string getVertex(int i){ return vertices[i];}
        bool isEmpty(){ return size == 0;}
        bool isFull(){ return size >= MAX_VTXS; }

        void reset(){            
            for (int i = 0; i < size; i++){
                if(adj != nullptr) { delete adj[i]; }
            }
            size = 0;
        }

        void insertVertex(std::string name){
            if(!isFull()){ 
                vertices[size] = name;
                adj[size++] = nullptr; 
            }
            else{ std::cout << "최대 크기를 넘어갔습니다.";}
        }

        void insertEdge(int u, int v){
            //adj[u] = new Node(v, adj[u]);
            // 파일로 읽기 때문에 구지 양방향 안함.

            if(adj[u] == nullptr){
                adj[u] = new Node(v, adj[u]);
            }
            else{
                Node *p = adj[u];
                while(p->getLink() != nullptr){
                    p = p->getLink();
                }
                p->setLink(new Node(v, nullptr));
            }
        }

        void display(){
            std::cout << size << "\n";
            for(int i = 0; i < size; i++){
                std::cout << getVertex(i) << " ";
                for (Node* v = adj[i]; v != nullptr; v = v->getLink()){
                    std::cout << getVertex(v->getId()) << " ";
                }
                std::cout << "\n";
            }
        }

        void load(std::string filename){
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            // 스트림으로 스트링을 바꿔줌
            std::stringstream ls(line);
            int n;
            ls >> n;
            for (int i =0; i < n; i++){
                std::getline(ifs, line);
                std::string str;
                int val;
                std::stringstream ls(line);
                ls >> str;
                // 첫 문자는 정점 이름
                insertVertex(str);
                for(int j = 0; j < n; j++){
                    ls >> val;
                    if(val != 0){
                        insertEdge(i, j);
                    }
                }         
            }
            ifs.close();
        }        

};

class AdjMatGraph{
    protected:
        int size; //그래프 사이즈 = 정점의 개수
        std::string vertices[MAX_VTXS]; // 정점 이름
        int adj[MAX_VTXS][MAX_VTXS]; //인접행렬
    
    public:
        AdjMatGraph(){ reset();}
        ~AdjMatGraph(){}

        std::string getVertex(int i){ return vertices[i];}
        int getEdge(int i, int j){ return adj[i][j]; }
        void setEdge(int i, int j, int val){ adj[i][j] = val; }
        bool isEmpty(){ return size == 0;}
        bool isFull(){ return size >= MAX_VTXS; }

        void reset(){
            size = 0;
            for (int i = 0; i < MAX_VTXS; i++){
                for (int j = 0; j < MAX_VTXS; j++){
                    setEdge(i, j, 0);
                }
            }
        }

        void insertVertex(std::string name){
            if(!isFull()){ vertices[size++] = name; }
            else{ std::cout << "최대 크기를 넘어갔습니다.";}
        }

        void insertEdge(int u, int v){
            setEdge(u, v, 1);
            setEdge(v, u, 1);
        }

        void display(){
            std::cout << size << "\n";
            for(int i = 0; i < size; i++){
                std::cout << getVertex(i) << " ";
                for (int j = 0; j < size; j++){
                    std::cout << getEdge(i, j) << " ";
                }
                std::cout << "\n";
            }
        }

        void load(std::string filename){
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            // 스트림으로 스트링을 바꿔줌
            std::stringstream ls(line);
            int n;
            ls >> n;
            for (int i =0; i < n; i++){
                std::getline(ifs, line);
                std::string str;
                int val;
                std::stringstream ls(line);
                ls >> str;
                // 첫 문자는 정점 이름
                insertVertex(str);
                for(int j = 0; j < n; j++){
                    ls >> val;
                    if(val != 0){
                        insertEdge(i, j);
                    }
                }         
            }
            ifs.close();
        }

        void store(std::string filename){
            std::ofstream ofs(filename);
            ofs << size << "\n";
            for(int i = 0; i < size; i++){
                ofs << getVertex(i) << " ";
                for (int j = 0; j < size; j++){
                    ofs << getEdge(i, j) << " ";
                }
                ofs << "\n";
            }
            ofs.close();
        }

};

class SrchAMGraph : public AdjMatGraph{
    protected:
        bool visited[MAX_VTXS];

    public:
        void resetVisited(){
            for (int i = 0; i < size; i++){
                visited[i] = false;
                //처음엔 연결 안되있다고 초기값
            }
        }
        // 길(링크)이 있는지 여부
        bool isLinked(int u, int v){ return getEdge(u, v) != 0; }

        void DFS(int v){
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            for(int w = 0; w < size; w++){
                if(isLinked(v, w) && visited[w] == false){
                    //경로가 있고 방문기록 없으면
                    DFS(w);
                }
            }
        }

        void BFS(int v){
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v);
            while(!que.isEmpty()){
                int v = que.dequeue();
                for(int w = 0; w < size; w++){
                    if(isLinked(v, w) && visited[w] == false){
                        visited[w] = true;
                        std::cout << getVertex(w) << " ";
                        que.enqueue(w);
                    }
                }
            }

        }
};

class SrchALGraph : public AdjListGraph{
    protected:
        bool visited[MAX_VTXS];

    public:
        void resetVisited(){
            for (int i = 0; i < size; i++){
                visited[i] = false;
                //처음엔 연결 안되있다고 초기값
            }
        }
        // 길(링크)이 있는지 여부
        bool isLinked(int u, int v){
            for(Node* p = adj[u]; p != nullptr; p = p->getLink()){
                if(p->getId() == v){
                    return true;
                }
            }
            return false;
        }

        void DFS(int v){
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            for(Node* p = adj[v]; p != nullptr; p = p->getLink()){
                if(visited[p->getId()] == false){
                    DFS(p->getId());
                }
            }
        }

        void BFS(int v){
            visited[v] = true;
            std::cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v);
            while(!que.isEmpty()){
                int v = que.dequeue();
                for(Node* w = adj[v]; w != nullptr; w = w->getLink()){
                    int id = w->getId();                    
                    if(visited[id] == false){
                        visited[id] = true;
                        std::cout << getVertex(id) << " ";
                        que.enqueue(id);
                    }
                }
            }

        }
};

class ConnectedComponentGraph : public SrchAMGraph{
    protected:
        int label[MAX_VTXS];
    
    public:
        void labelDFS(int v, int color){
            visited[v] = true;
            label[v] = color;
            std::cout << getVertex(v) << " ";
            for(int w = 0; w < size; w++){
                if(isLinked(v, w) && visited[w] == false){
                    labelDFS(w, color);
                }
            }
        }
        void findConnectedComponent(){
            int count = 0;
            for (int i = 0; i < size; i++){
                if(visited[i] == false){
                    labelDFS(i, ++count);
                }
            }
            std::cout << "\n연결 성분의 수는: " << count << "\n";
            for(int i = 0; i < size; i++){
                std::cout << getVertex(i) << ":" << label[i] << " ";
            }
            std::cout << "\n";
        }


};

class TopoSortGraph : public AdjListGraph{
    public:
        TopoSortGraph(void){}
        ~TopoSortGraph(void){}

        void insertDirEdge(int u, int v){
            adj[u] = new Node(v, adj[u]);
        }

        void TopoSort(){
            CircularQueue q;
            int *inDeg = new int [size];
            // 모든 정점의 in-degree를 담는 변수
            // 연결된 노드들의 갯수 담음
            for(int i = 0; i < size; i++){
                inDeg[i] = 0;
                //초기화
            }

            for(int i = 0; i < size; i++){
                Node * node = adj[i];
                while(node != nullptr){
                    inDeg[node->getId()]++;
                    //몇개나 연결되어있는지
                    node = node->getLink();
                }
            }

            for(int i = 0; i < size; i++){
                if(inDeg[i] == 0){ q.enqueue(i); }
            }

            while(q.isEmpty() == false){
                int w = q.dequeue();
                std::cout << getVertex(w) << " ";
                Node *node = adj[w];
                while(node != nullptr){
                    // 모든 상위 노드 탐색
                    int u = node->getId();
                    inDeg[u]--;
                    // 이 노드 제거되므로 상위노드
                    // 한 차수 낮춤.
                    if(inDeg[u] == 0){
                        q.enqueue(u);
                    }
                    node = node->getLink();
                }
            }
            std::cout << "\n";
            delete[] inDeg;
        }

};


int main(void){/*
    AdjMatGraph g;
    for(int i = 0; i < 4; i++){
        g.insertVertex(std::string(1,'A' +  i));
    }
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    g.insertEdge(1,3);
    g.insertEdge(2,3);
    g.display();
    g.store("graph.txt");
    g.reset();
    g.load("graph.txt");
    g.display();


    AdjListGraph g1;
    g1.load("graph.txt");
    g1.display();

    SrchAMGraph g2;
    g2.load("lecture10/lecture10_1/graph2.txt");
    g2.display();
    std::cout << "DFS => ";
    g2.resetVisited();
    g2.DFS(0);
    std::cout << "\n";

    std::cout << "BFS => ";
    g2.resetVisited();
    g2.BFS(0);


    std::cout << "\n";
    SrchALGraph g3;
    g3.load("lecture10/lecture10_1/graph2.txt");
    g3.display();
    std::cout << "DFS => ";
    g3.resetVisited();
    g3.DFS(0);
    std::cout << "\n";

    std::cout << "BFS => ";
    g3.resetVisited();
    g3.BFS(0);

    ConnectedComponentGraph g4;
    for(int i = 0; i < 5; i++){
        g4.insertVertex(std::string(1, 'A' + i));
    }
    g4.insertEdge(0, 1);
    g4.insertEdge(0, 2);
    g4.insertEdge(3, 4);
    g4.store("graph3.txt");
    std::cout << "연결성분 테스트";
    g4.display();
    g4.resetVisited();
    g4.findConnectedComponent();
    */

    TopoSortGraph g5;

    for(int i = 0; i < 6; i++){
        g5.insertVertex(std::string(1, 'A' + i));
    }
    
    g5.insertDirEdge(0, 2);
    g5.insertDirEdge(0, 3);

    g5.insertDirEdge(1, 3);
    g5.insertDirEdge(1, 4);

    g5.insertDirEdge(2, 3);
    g5.insertDirEdge(2, 5);

    g5.insertDirEdge(3, 5);

    g5.insertDirEdge(4, 5);

    std::cout << "위상정렬 수행: ";
    g5.TopoSort();
    return 0;
}

