#include <iostream>
#include <fstream>
#include <string>

class line{
    protected:
        std::string data;

    public:
        line(std::string line = ""){
            data = line;
        }

        void read(std::istream *is = &std::cin){ // 입력 없으면 입력받음. data에 넣음.
            std::getline(*is, data);
        }

        void display(std::ostream *os = &std::cout){ // 출력방식 입력 없으면 그냥 출력
            *os << data << "\n";
        }

        bool hasData(std::string str){ // 이 라인이 str와 같은지 검사
            return str == data;
        }
};

class node : public line{
    private:
        node* next;
    public:
        node(std::string str = ""): line(str){ // line생성자 같이 불러옴. data = str
            next = nullptr;
        }

        node* getLink(){
            return next;
        }

        std::string getData(){
            return data;
        }

        void setLink(node* target){
            next = target;
        }

        void insertNext(node* newnode){
            if(newnode != nullptr){
                newnode->next = next; 
                next = newnode;
            }
        }

        node* removeNext(){
            node* removed = next;
            if(removed != nullptr){
                next = removed -> next;
            }
            return removed;
        }

};

class hn_s_linked_list{
    protected:
        node origin;
    public:
        hn_s_linked_list(): origin("head node"){}
        ~hn_s_linked_list(){ clear();}

        void clear(); // 리스트 삭제연산
        node* getHead(); // 첫 노드 부르는 연산
        bool isEmpty(); // 공백확인

        node* getEntry(int pos);
        void insert(int pos, node* n);
        void remove(int pos);
        node* find(std::string Value);
        void replace(int pos, node* n);
        size_t size();
        void display();
};

void hn_s_linked_list::clear(){
    while(!isEmpty()){
        remove(0);
    }
}

node* hn_s_linked_list::getHead(){
    return origin.getLink();
} // 첫 노드 부르는 연산

bool hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
}

//pos번째 항목 반환
node* hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for(int i = -1; i < pos; i++, n = n->getLink()){
        if(n==nullptr){
            break;
        }
    }
    return n;
}

void hn_s_linked_list::insert(int pos, node* n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        prev->insertNext(n);
    }
}

void hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        delete prev->removeNext();
    }
}

node* hn_s_linked_list::find(std::string value){
    for(node* p = getHead(); p != nullptr; p = p->getLink()){
        if(p->getData() == value){
            return p;
        }
    }
    return nullptr;
}

void hn_s_linked_list::replace(int pos, node* n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }
}

size_t hn_s_linked_list::size(){
    int count = 0;
    for (node* p = getHead(); p != nullptr; p = p->getLink()){
        count++;
    }
    return count;
}

void hn_s_linked_list::display(){
    std::cout << "전체 항목의 수 " << size() << ", ";
    for (node* p = getHead(); p != nullptr; p = p->getLink()){
        std::cout << p->getData() << " ";
    }
    std::cout << "\n";
}

class LineEditor : public hn_s_linked_list{
    public:
        void Display(std::ostream *os);
        void InsertLine();
        void DeleteLine();
        void ReplaceLine();
        void LoadFile(std::string fname);
        void SaveFile(std::string fname);
};

void LineEditor::Display(std::ostream *os = &std::cout){
    int i = 0;
    std::cout << "전체 항목의 수 " << size() << ", ";
    for (node* p = getHead(); p != nullptr; p = p->getLink(), i++){
        std::cerr << i << " ";
        p->display(os);
    }
}

void LineEditor::InsertLine(){
    int position;
    std::string line;
    std::cout << "  입력행 번호: ";
    std::cin >> position;
    std::cin.sync(); // 버퍼를 비워주는 작업
    std::cin.clear();
    std::cout << "  입력할 내용: ";
    getline(std::cin, line);
    insert(position, new node(line));
}

void LineEditor::DeleteLine(){
    int position;
    std::cout << "  삭제행 번호: ";
    std::cin >> position;
    remove(position);
}

void LineEditor::ReplaceLine(){
    int position;
    std::string line;
    std::cout << "  변경행 번호: ";
    std::cin >> position;
    std::cin.sync(); // 버퍼를 비워주는 작업
    std::cin.clear();
    std::cout << "  변경할 내용: ";
    getline(std::cin, line);
    replace(position, new node(line));
}

void LineEditor::LoadFile(std::string fname){
    std::ifstream ifs(fname);
    std::string line;
    while(std::getline(ifs, line)){
        insert(size(), new node(line));
    }
}

void LineEditor::SaveFile(std::string fname){
    std::ofstream ofs(fname);
    if(ofs.good()){ //다 열여있는 경우
        Display(&ofs);
        ofs.close();
    }
}

int main(){
    LineEditor editor;
    char command;
    do{
        std::cout <<"[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료=> ";
        command = std::getchar();
        std::cin.sync();
        switch(command){
            case 'd':
                editor.DeleteLine();
                break;
            case 'i':
                editor.InsertLine();
                break;
            case 'r':
                editor.ReplaceLine();
                break;
            case 'l':
                editor.LoadFile("./lecture07/lecture7_4/test.txt");
                break;
            case 's':
                editor.SaveFile("./lecture07/lecture7_4/test.txt");
                break;
            case 'p':
                editor.Display();
                break;
            case 'q':
                break;
        }
    } while (command != 'q');
    return 0;
}