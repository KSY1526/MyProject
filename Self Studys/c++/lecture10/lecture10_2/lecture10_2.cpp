#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define MAX_VTXS 256
#define INF 9999

class node{
    private:
        int weight;
        int v1;
        int v2;
        node* next;

    public:
        node(int val = INF, int vx1 = -1, int vx2 = -1){
            weight = val;
            v1 = vx1;
            v2 = vx2;
            next = nullptr;
        }
        ~node(){}
        node* getLink() { return next; }
        int getWeight() { return weight; }
        int getSource() { return v1; }
        int getTarget() { return v2; }

        void setLink(node * target) { next = target; }

        void insertNext(node * newnode){
            if(newnode != nullptr){
                newnode->next = next;
                next = newnode;
            }
        } // 노드의 다음자리에 새 노드 넣음

        node* removeNext() {
            node * removed = next;
            if(removed != nullptr){
                next = removed->next;
            }
            return removed;
        } // 노드의 다음자리 노드를 지우는 연산        

};

class o_linked_list{
    protected:
        node origin;

    public:
        o_linked_list(){}
        ~o_linked_list(){ clear();}
        void clear(){
            while(!isEmpty()){
                origin.removeNext();
            }
        }

        bool isEmpty(){
            return getHead() == nullptr;
        }

        node* getHead(){
            return origin.getLink();
        } // 첫 노드를 부르는 연산

        void removeHead(){
            origin.removeNext();
        }

        void orderedInsert(node *n){
            int w = n->getWeight();
            node* prev = &origin;
            node* now = getHead();
            while(now != nullptr){
                int now_w = now->getWeight();
                if(now_w >= w){
                    prev->insertNext(n);
                    return;
                }
                prev = now;
                now = now->getLink();
            }
            prev->insertNext(n);
            //최댓값일때.
            return;
        }

        size_t size(){
            int count = 0;
            for(node* p = getHead(); p != nullptr; p = p->getLink()){
                count++;
            }
            return count;
        }

        void display(){
            std::cout << "항목 수: " << size() << "\n";
            for(node* p = getHead(); p != nullptr; p = p->getLink()){
                std::cout << p->getWeight() << " " << p->getSource() << " ";
                std::cout << p->getTarget() << "\n";
            }
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

class VertexSets{
    protected:
        int parent[MAX_VTXS];
        int size;
        // 루트 노드의 숫자
    public:
        VertexSets(int nSets){
            size = nSets;
            for(int i = 0; i < nSets; i++){
                parent[i] = -1;
                // 자기가 루트라는것
            }
        }

        bool isRoot(int i){
            return parent[i] < 0;
        }

        int findSet(int vertex){
            int id = vertex;
            while(!isRoot(id)){
                id = parent[id];
                // 부모를 계속 찾아감.
            }
            return id;
        }

        void unionSets(int s1, int s2){
            parent[s1] = s2;
            size--;
        }
};

class WGraph : public AdjMatGraph{
    public:
        WGraph(){}
        ~WGraph(){}

        bool hasEdge(int i, int j) { return (getEdge(i, j) < INF); }

        void insertEdge(int u, int v, int weight){
            if (weight >= INF) { weight = INF; }
            setEdge(u, v, weight);
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
                    insertEdge(i, j, val);
                }         
            }
            ifs.close();
        }
};

class WGraphMST : public WGraph{
    public:
        void Kruskal(){
            o_linked_list o_edgelist;
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    if(hasEdge(i, j)){
                        o_edgelist.orderedInsert(new node(getEdge(i,j), i, j));
                    }
                }
            }
            VertexSets set(size);
            int edgeAccpted = 0;
            while(edgeAccpted < size - 1){
                node * e = o_edgelist.getHead();
                int uset = set.findSet(e->getSource());
                int vset = set.findSet(e->getTarget());
                if(uset != vset){
                    std::cout << "An edge added to Mst: " << getVertex(e->getSource());
                    std::cout << " " << getVertex(e->getTarget()) << " " << e->getWeight() << "\n";
                    set.unionSets(uset, vset);
                    edgeAccpted++;
                }
                o_edgelist.removeHead();
                //헤드를 지움
            }
            
        }

        void Prim(){
            bool selected[MAX_VTXS];
            int dist[MAX_VTXS];
            int source_vertex[MAX_VTXS];
            //어느정점에서부터 쟨 거리인지
            for (int i = 0; i < size; i++){
                dist[i] = INF;
                selected[i] = false;
                source_vertex[i] = 0;
            }
            dist[0] = 0;
            for (int i = 0; i < size; i++){
                int u = getMinVertex(selected, dist);
                selected[u] = true;
                if(dist[u] >= INF){
                    return;
                    //그래프 중간에 끊겨있음
                }
                if(u != source_vertex[u]){
                    std::cout << "An edge added to MST: " << getVertex(u) << " ";
                    std::cout << getVertex(source_vertex[u]) << " ";
                    std::cout << getEdge(u, source_vertex[u]) << "\n";
                }
                for(int v = 0; v < size; v++){
                    if(getEdge(u, v) != INF){
                        if(!selected[v] && getEdge(u, v) < dist[v]){
                            // 지금까지 찾던 거리(v안에서)중 최소이면 
                            dist[v] = getEdge(u, v);
                            source_vertex[v] = u;
                        }
                    }
                }
            }

        }

        int getMinVertex(bool* selected, int* dist){
            int minv = 0;
            int mindist = INF;
            for(int v = 0; v < size; v++){
                if(!selected[v] && dist[v] < mindist){
                    mindist = dist[v];
                    minv = v;
                }
            }
            return minv;
        }
        
};

class WgraphDijkstra : public WGraph{
    protected:
        int path[MAX_VTXS];
        // 어떤 노드(바로직전)를 거처서 최소길이경로가 나왔는가?
        int dist[MAX_VTXS];
        // 그 시점에서의 거리 배열
        bool found[MAX_VTXS];
        // 찾았는지를 판별

    public:
        WgraphDijkstra(){}
        ~WgraphDijkstra(){}

        void PrintDistance(){
            for(int i = 0; i < size; i++){
                std::cout << dist[i] << " ";
            }
        }

        void PrintPath(int start, int end){
            std::cout << "Shortest path" << getVertex(end) << "->";
            std::cout << getVertex(start) << " ";
            std::cout << getVertex(end);
            while(path[end] != start){
                std::cout << "-" << getVertex(path[end]);
                end = path[end];
            }
            std::cout << "-" << getVertex(start) << "\n";
        }

        int chooseVertex(){
            int min = INF;
            int minpos = -1;
            // 거리가 최소인 노드의 인덱스
            for (int i = 0; i < size; i++){
                if(dist[i] < min && !found[i]){
                // 최소값보다 거리가 작고 s그룹내 없으면
                    min = dist[i];
                    minpos = i;
                }
            }
            return minpos;
        }

        void ShortestPath(int start){
            for(int i = 0; i < size; i++){
                dist[i] = getEdge(start, i);
                path[i] = start;
                found[i] = false;
            }
            found[start] = true;
            dist[start] = 0;

            for(int i = 0; i < size; i++){
                std::cout << "STEP " << i+1 << " ";
                PrintDistance();
                int u = chooseVertex();
                // 가장 짧은 노드 구함
                found[u] = true;
                for(int w = 0; w < size; w++){
                    if(!found[w]){
                        if(dist[u] + getEdge(u, w) < dist[w]){
                            dist[w] = dist[u] + getEdge(u, w);
                            path[w] = u;
                        }
                    }
                }
                std::cout << "\n";
            }
        }


};

class WgraphFloyd : public WGraph{
    protected:
        int A[MAX_VTXS][MAX_VTXS];
        //최단경로 메트릭스
        int path[MAX_VTXS][MAX_VTXS];
        // 경로

    public:
        void ShortestPathFloyd(){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    A[i][j] = getEdge(i, j);
                    path[i][j] = j;
                }
            }

            for(int k = 0; k < size; k++){
                for(int i = 0; i < size; i++){
                    for(int j = 0; j < size; j++){
                        if(A[i][k] + A[k][j] < A[i][j]){
                            A[i][j] = A[i][k] + A[k][j];
                            path[i][j] = path[i][k];
                        }
                    }
                }
                printA();
            }
        }

        void printA(){
            std::cout << "Shortest path length matrix: \n";
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    if(A[i][j] == INF){
                        std::cout << "INF ";
                    }
                    else{
                        std::cout << A[i][j] << " ";
                    }
                }
                std::cout << "\n";
            }
        }

        void PrintPath(int start, int end){
            std::cout << "Shortest path" << getVertex(start) << "->";
            std::cout << getVertex(end) << " ";
            std::cout << getVertex(start);
            while(path[start][end] != end){
                std::cout << "-" << getVertex(path[start][end]);
                start = path[start][end];
            }
            std::cout << "-" << getVertex(end) << "\n";
        }
};

int main(void){
    /*WGraphMST g;
    g.load("lecture10/lecture10_2/graph2.txt");
    g.display();

    g.Kruskal();
    std::cout << "\n";
    g.Prim();
*/
    WgraphDijkstra g1;
    g1.load("lecture10/lecture10_2/graph_sp.txt");
    g1.display();

    std::cout << "최단 경로 by dijkstra\n";
    g1.ShortestPath(0);
    for(int i = 0; i < 7; i++){
        g1.PrintPath(0, i);
    }

    WgraphFloyd g2;
    g2.load("lecture10/lecture10_2/graph_sp.txt");
    g2.display();

    std::cout << "최단 경로 by Floyd\n";
    g2.ShortestPathFloyd();

    for(int i = 0; i < 7; i++){
        g1.PrintPath(0, i);
        g2.PrintPath(i, 0);
    }
    return 0;
}
