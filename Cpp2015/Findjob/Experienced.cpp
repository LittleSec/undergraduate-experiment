#include<iostream>
#include<string>
#include"Experienced.h"
using namespace std;

Experienced::Experienced(const string name, Subject *subject):Observer(name){// 在求职中心登记
    subject->addObserver(this);
}

void Experienced::answerPhone(const string &message){
    cout<<"我叫"<<getName()<<"，我有工作经验，待遇要好。我收到了招聘信息："<<message<<endl;
}

