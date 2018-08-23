//
//  Poker.cpp
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#include<iostream>
#include"Poker.h"
using namespace std;

Poker::Poker(int point,char Rpoint,char suit){
    this->point = point;
    this->Rpoint = Rpoint;
    this->suit = suit;
    IfShow = false;//扑克牌初始应为不可见
}

void Poker::ChangeFlag(bool fl){
    IfShow = fl;
}

void Poker::ChangePoint(int pt){
    point = pt;
}

void Poker::ChangeRpoint(char rp){
    Rpoint = rp;
}

int Poker::GetPoint()const{
    return point;
}

void Poker::ShowPoker(){
    if(IfShow == true){
        if(Rpoint == 58)//点数为10的纸牌牌面字母是‘:’，对应的ASCII码是58
            cout<<suit<<point;//若不对此判断，则4张牌面为10的牌输出都是':花色'
        else
            cout<<suit<<Rpoint;
    }
    else
        cout<<"XX";
}

bool Poker::GetIfShow()const{
    return IfShow;
}

