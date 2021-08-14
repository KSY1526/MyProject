#include <iostream>
#include "LinkedListStack.h"
//#include "includes/ArrayStack.h"
using namespace std;

int main(){
    LinkedlistStack stack;
    for (int i = 0; i < 10; i++){
        stack.push(i);
    }
    stack.display();
    cout << stack.pop() << "\n";
    cout << stack.pop() << "\n";
    cout << stack.pop() << "\n";
    stack.display();

    return 0;
}