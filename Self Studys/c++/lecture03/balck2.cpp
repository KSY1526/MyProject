/*#include <iostream>
#include <string>

class Car{
    protected:
        int speed;
        std::string name;
    public:
        int gear;
        Car(){}
        ~Car(){}
        Car(int s, std::string n, int g): speed(s), gear(g){
            name = n;
        }
        void changeGear(int g= 4){
            gear = g;
        }
        void speedUp(){
            speed += 5;
        }
        void display(){
            std::cout << name << ", 기어: " << gear;
            std::cout << "단, 속도 : " << speed << "\n";
        }
        void whereAmI(){
            std::cout << this << "\n";
        }
};

class SportsCar : public Car{
    public:
        bool bTurbo;
        SportsCar() {}
        SportsCar(int s, std::string n, int g): Car(s,n,g){}
        void setTurbo(bool bTur){
            bTurbo = bTur;
        }
        void speedUp(){
            if(bTurbo){
                speed += 20;
            }
            else{
                Car::speedUp();
            }
        }
};

int main(){
    Car yourCar(80, "your car", 4);
    SportsCar myCar(100, "my car", 4);
    yourCar.display();
    myCar.display();
    yourCar.speedUp();
    myCar.setTurbo(true);
    myCar.speedUp();
    yourCar.display();
    myCar.display();
    yourCar.changeGear(3);
    myCar.changeGear(3);
    yourCar.display();
    myCar.display();
    return 0;
}*/