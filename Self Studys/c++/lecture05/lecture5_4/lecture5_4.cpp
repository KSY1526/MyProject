#include <stack>
#include <iostream>

const int MAZE_SIZE = 6;
//0이 가는길, 1이 못가는길
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '1', '1'},
    {'1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '0', '0'},
    {'1', '0', '1', '0', '1', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

struct Location2D{
    int row; //행
    int col; //열
    Location2D(int r = 0, int c = 0){
        row = r;
        col = c;
    }
    // p와 이웃위치인가
    bool isNeighbor(Location2D &p){//레퍼런스
        return ((row == p.row && col == p.col - 1)
            || (row == p.row && col == p.col + 1)
            || (row == p.row - 1 && col == p.col)
            || (row == p.row + 1 && col == p.col)
        );
    }
    // ==연산자 오버로딩(중복) 두 로케이션 변수가 같은지 검증 
    bool operator==(Location2D &p){return row==p.row && col ==p.col;}
};

// 이동할수 있는 위치인지
bool isValidLoc(int r, int c){
    if(r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
    else return map[r][c] == '0' || map[r][c] == 'x';
}

int main(){
    std::stack<Location2D> locStack;
    Location2D entry(1, 0);
    locStack.push(entry);
    while(locStack.empty() == false){
        Location2D here = locStack.top(); //top==peek
        locStack.pop(); // pop은 꺼내진 않음
        int r = here.row;
        int c = here.col;
        std::cout << "(" << r << "," << c << ") ";
        if(map[r][c] == 'x'){
            std::cout << "탈출에 성공했습니다. \n";
            return 0;
        }
        else{
            map[r][c] = '.'; //갔다고 표시
            if(isValidLoc(r-1,c)) locStack.push(Location2D(r-1, c));
            if(isValidLoc(r+1,c)) locStack.push(Location2D(r+1, c));
            if(isValidLoc(r,c-1)) locStack.push(Location2D(r, c-1));
            if(isValidLoc(r,c+1)) locStack.push(Location2D(r, c+1));
        }
    }
    std::cout << "탈출에 실패하였습니다. \n";
    return -1;
}