#include <iostream>
using namespace std;

class Point{
    private:
        int x, y;
    public:
        Point();
        Point(int a, int b);
        void show() {
            cout << "(" << x << ", " << y << ")" << "\n";
        }
};

Point::Point() :Point(0, 0) { }

Point::Point(int a, int b) :x(a), y(b) {}

int main(){
    Point origin;
    Point target(10, 20);
    origin.show();
    target.show();
    return 0;
}