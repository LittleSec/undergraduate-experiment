#include<iostream>
#include<string>
#include"JobCenter.h"
using namespace std;

JobCenter::JobCenter(){
    numObserver = 0;
    for (int i = 0; i < 100; i++)
        list[i] = NULL;
    statusChanged = true;
    cout<<"求职中心成立了."<<endl<<endl;
}

void JobCenter::notifyObservers(){// 通知所有的求职者，让他们接收职位需求信息
    if(statusChanged == true){
        cout<<"通知所有求职者 ..."<<endl;
        for(int i = 0; i < numObserver; i++)
            list[i]->answerPhone(message);
    }
}

void JobCenter::addObserver(Observer *pObserver){// 添加求职者对象
	for (int i = 0; i < 100; i++){
		if(list[i] == NULL){
			list[i] = pObserver ;
			numObserver++ ;
			break;
		}
	}
}

void JobCenter::publishMessage(const string message){// 发布职位需求信息
    if(message == this->message){
        cout<<"该信息已经发布过了."<<endl;
        statusChanged = false;
    }
    else{
        this->message = message;
        statusChanged = true;
        cout<<"发布招聘信息："<<message<<endl<<endl;
    }
}

JobCenter::~JobCenter(){
    cout<<"求职中心关闭了."<<endl;
}
