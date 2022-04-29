#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

inline int error(const char* str){//const상수.
    std::cerr << str << "\n"; //cerr 에러를 배출해줌
    exit(1); // 비정상 1 정상 0
};


bool CheckMatching(string filename){
    ifstream is(filename); // 파일 불러오기
    if (!is.is_open()){
        error("Error: 파일이 제대로 열리지 않았습니다. \n");
    }
    int nLine = 1; // 첫줄 하나 있다고 가정
    int nChar = 0; // 글자수
    stack<char> symbol; // 괄호기호 저장용
    char ch; // 글자 하나씩 입력받는 변수
    while(is.get(ch)){ // 파일 내 한글자씩 계속 입력하기
        if (ch == '\n'){ // 개행문자인 경우
            nLine++; // 줄 갯수 늘려서 기록
        }
        else { nChar++; } // 개행문자 아닌경우 글자수 늘려서 기록

        if (ch == '[' || ch == '{' || ch == '('){ // 여는 문자인경우
            symbol.push(ch); // 스택에 값 삽입
        }
        else if (ch == ']' || ch == '}' || ch == ')'){ // 닫는 문자인경우
            if (symbol.empty()){ // 만약 앞에 여는 문자가 아에 안나왔을경우
                symbol.push(ch); // 스택을 빈공간으로 만들어주지 않고
                break; // 빈공간으로 반복문 탈출할 경우 참값이 나옴
            }
            char prev = symbol.top(); // 스택 맨 위 값 prev변수에 저장
            if((ch == ']' && prev == '[')
                || (ch == '}' && prev == '{')
                || (ch == ')' && prev == '(')){
                // 맞게 들어왔을때
                symbol.pop(); // 스택 내 여는 문자 제거
            }
            else { // 틀리게 들어왔을때
                break; // 스택 내 잘못된 여는 문자를 유지한 채로 반복문 탈출
            }
        }
    }
    is.close();
    cout << filename << " 파일 검사결과: \n";
    if(!symbol.empty()){
        cout << "문제발견 (오류 검출 전 라인수:" << nLine << ", 오류 검출 전 문자수:" << nChar << ")\n";
        // 오류 검출되자 마자 반목문을 탈출하여 nline, nchar 값 체크가 안되기 때문
    }
    else{
        cout << "괄호닫기 정상 (총 라인수:" << nLine << ", 총 문자수:" << nChar << ")\n";
    }
    return symbol.empty();

}

int main(){
    CheckMatching("./lecture5_4/lecture5_4.cpp");
    CheckMatching("./lecture5_1/ArrayStack.h");
    return 0;
}