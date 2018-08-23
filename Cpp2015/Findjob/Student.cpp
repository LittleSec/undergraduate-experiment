#include<iostream>
#include<string>
#include"Student.h"
using namespace std;

Student::Student(const string name, Subject *subject):Observer(name){// 在求职中心登记
    subject->addObserver(this);
}

void Student::answerPhone(const string &message){
    cout<<"我叫"<<getName()<<"，我是一名毕业生，我收到了招聘信息："<<message<<endl;
}
