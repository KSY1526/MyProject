#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student{
    protected:
        int id;
        string name;
        string dept;
    public:
        Student(int i = 0, string nam = "", string dep = ""){
            set(i, nam, dep);
        }
        void set(int i, string nam, string dep){
            id = i;
            name = nam;
            dept = dep;
        }
        void display(){
            cout << "학번: " << id << " 성명: " << name << " 학과: " << dept << "\n";
        }
        string contents(){
            string str;
            str = "학번: " + to_string(id) + " 성명: " + name + " 학과: " + dept;
            return str;
        }
        friend ostream& operator<<(ostream& os, Student& st);

};

ostream& operator<<(ostream& os, Student& st){
    os << st.contents();
    return os;
}
