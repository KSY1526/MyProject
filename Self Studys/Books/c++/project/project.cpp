#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <ctime>

#define MAX_VTXS 256
#define Q 0.2// Q확률(실험1 0.2, 실험2 0/0.2, 실험3 0.2)
#define N 500000 // Random Walker가 돌아다니는 횟수(실험1 5000, 실험2 5000, 실험3 500/500000)
#define INF 9999

static std::mt19937 gen = std::mt19937((unsigned int)time(NULL));
static std::uniform_real_distribution<> dist(0, 1);
// dist(gen) 0과 1 사이 수를 랜덤하게 생성해줌




class WageNode{
    protected:
        int id;
        int wage;
        WageNode* link;        
        //가중치 정수라고 가정 
    public:
        WageNode(int i, int wa, WageNode* l = nullptr): id(i), wage(wa), link(l){}
        ~WageNode(void){
            if(link != nullptr){
                delete link;
            }
        }
        int getId() { return id; }
        WageNode* getLink() { return link; }
        void setLink(WageNode* l) { link = l;}
        int getWage() { return wage; }
};

class WageAdjListGraph{
    protected:
        int size; //그래프 사이즈 = 정점의 개수
        std::string vertices[MAX_VTXS]; // 정점 이름
        WageNode* adj[MAX_VTXS]; 
    
    public:
        WageAdjListGraph(void) : size(0) {}
        ~WageAdjListGraph(void){ reset(); }

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

        void insertEdge(int u, int v, int wa){
            //adj[u] = new Node(v, adj[u]);
            // 파일로 읽기 때문에 구지 양방향 안함.

            if(adj[u] == nullptr){
                adj[u] = new WageNode(v, wa, adj[u]);
            }
            else{
                WageNode *p = adj[u];
                while(p->getLink() != nullptr){
                    p = p->getLink();
                }
                p->setLink(new WageNode(v, wa, nullptr));
            }
        }

        void display(){
            std::cout << size << "개 정점이 있습니다. \n";
            for(int i = 0; i < size; i++){
                std::cout << getVertex(i) << " => ";
                for (WageNode* v = adj[i]; v != nullptr; v = v->getLink()){
                    std::cout << getVertex(v->getId()) << "(" << v->getWage() << ")" <<  " ";
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
                    if(val != 0 && val != INF){
                        insertEdge(i, j, val);
                    }
                }         
            }
            ifs.close();
        }        

};

class WagePageBank : public WageAdjListGraph{
    protected:
        int countVertex[MAX_VTXS];
        // Random Walker가 노드에 들린 횟수 기록
    public:
        WagePageBank(){}
        ~WagePageBank(){}
        int RandPoint(int range){            
            return (int)(range* dist(gen));
            // 0에서 range - 1 까지 출력
        }

        int WageNodeSize(WageNode* nod){
            //연결되있는 간선의 가중치의 합을 구하는함수
            WageNode* v = nod;
            int wagenodesize = 0;
            while(v != nullptr){                
                wagenodesize += v->getWage();
                v = v->getLink();
            }
            return wagenodesize;
            // 특정노드가 연결되있는 가중치의 합.
        }

        void RandomWalker(){
            int startPoint = RandPoint(size);
            while(adj[startPoint] == nullptr){
                // 간선이 없는 노드는 선택하지 않음.
                startPoint = RandPoint(size);
            }
            int count = 0; // walking length 횟수를 체크하는 변수
            int nodesize; // 각 인접리스트의 크기를 나타내는 변수
            int point; // 몇번째 인접리스트 값인지 나타내는 변수
            int tem = 0;
            WageNode* select; // 인접리스트에서 선택된 노드.
            for(int i = 0; i < size; i++){
                countVertex[i] = 0;
            }
            while(count < N){
                count++;
                if(dist(gen) < Q){
                    startPoint = RandPoint(size);
                    while(adj[startPoint] == nullptr){
                        // 간선이 없는 노드는 선택하지 않음.
                        startPoint = RandPoint(size);
                    }
                    countVertex[startPoint]++;
                }
                else{                    
                    nodesize = WageNodeSize(adj[startPoint]);
                    // 이부분이 전자(가중치x)와 다름.
                    point = RandPoint(nodesize);
                    select = adj[startPoint];
                    tem = select->getWage();
                    while(point >= tem){
                        select = select->getLink();
                        tem += select->getWage();                        
                    }
                    startPoint = select->getId();
                    countVertex[startPoint]++;                
                }                
            }
            return;
        }

        
};


class starwars : public WagePageBank{
    public:
        void NodeNameLoad1(std::string filename){
            //스타워즈 정점 입력
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::stringstream ls(line);
            int n;
            ls >> n;
            for (int i = 0; i < n; i++){
                std::getline(ifs, line);
                insertVertex(line);            
            }
            ifs.close();
        }

        void LinkLoad1(std::string filename){
            //스타워즈 간선 입력
            std::ifstream ifs(filename);
            std::string line;
            std::getline(ifs, line);
            std::stringstream ls(line);
            int n, source, target, wa;
            ls >> n;
            for (int i = 0; i < n; i++){
                std::getline(ifs, line);
                std::stringstream ls(line);
                ls >> source;
                ls >> target;
                ls >> wa;
                insertEdge(source, target, wa);
                insertEdge(target, source, wa);             
            }
            ifs.close();
        }
        void PageBackDisplay(){
            std::string * ver = vertices;
            int * count = countVertex;
            int maxx = count[0];
            int tem;
            std::string temm;
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(count[j] < count[i]){
                        tem = count[i];
                        count[i] = count[j];
                        count[j] = tem;
                        temm = ver[i];
                        ver[i] = ver[j];
                        ver[j] = temm;
                    }
                }
                
            }
            for(int i = 0; i < size; i++){
                std::cout << ver[i] << " " << (double)count[i] / N  << "% \n";
            }
            
        }

        void PageBackDisplay2(){
            std::string * ver = vertices;
            int *count = countVertex;            
            int maxx = count[0];
            int tem;
            std::string temm;
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(count[j] < count[i]){
                        tem = count[i];
                        count[i] = count[j];
                        count[j] = tem;
                        temm = ver[i];
                        ver[i] = ver[j];
                        ver[j] = temm;
                    }
                }
                
            }
            // 상위 5개만 뽑아냄
            for(int i = size -1; i > size - 6; i--){
                std::cout << ver[i] << " " << (double)count[i] / N  << "% \n";
            }
            std::cout << "\n";
        }
};



int main(void){
    //실험 1
    starwars g;
    g.NodeNameLoad1("project/starwarsnode.txt");
    g.LinkLoad1("project/starwarslink.txt");
    g.display();
    g.RandomWalker();
    g.PageBackDisplay();
    
    std::cout << "\n";
    // 실험 2, 3 (n과 q값을 바꿔줘야함)
    starwars g1;
    g1.NodeNameLoad1("project/starwarsnode.txt");
    g1.LinkLoad1("project/starwarslink.txt");
    g1.RandomWalker();
    g1.PageBackDisplay2();

    starwars g2;
    g2.NodeNameLoad1("project/starwarsnode.txt");
    g2.LinkLoad1("project/starwarslink.txt");
    g2.RandomWalker();
    g2.PageBackDisplay2();

    starwars g3;
    g3.NodeNameLoad1("project/starwarsnode.txt");
    g3.LinkLoad1("project/starwarslink.txt");
    g3.RandomWalker();
    g3.PageBackDisplay2();

    starwars g4;
    g4.NodeNameLoad1("project/starwarsnode.txt");
    g4.LinkLoad1("project/starwarslink.txt");
    g4.RandomWalker();
    g4.PageBackDisplay2();    
    return 0;
}