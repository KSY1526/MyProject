#include <iostream>



void hanoiTower(int n, char from, char tmp, char to){
    if(n == 1){
        std::cout << "원판 1을 " << from << "에서 " << to << "로 옮깁니다. \n";
    }
    else{
        hanoiTower(n-1, from, to, tmp);
        std::cout << "원판 " << n << "을 " << from << "에서 " << to << "로 옮깁니다. \n";
        hanoiTower(n-1, tmp, from, to);
    }   
}


int main(){
    hanoiTower(10, 'A', 'B', 'C');
    return 0;
}

