//
//  GeneralPlayer.cpp
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#include<iostream>
#include<iomanip>
#include"GeneralPlayer.h"
using namespace std;

GeneralPlayer::GeneralPlayer(const string name):Player(name){
    playerPoker = new Poker*[11];
    pokerNum = 0;
    pokerPoint = 0;
}

void GeneralPlayer::ShowInfo(){
    cout<<setiosflags(ios_base::left)<<setw(7)<<GetPlayerName()<<":";
    for(int i = 0;i<pokerNum;i++){
        playerPoker[i]->ShowPoker();
        cout<<"     ";
    }
    cout<<"("<<pokerPoint<<")"<<endl;
}

char GeneralPlayer::IfGetPoker(){
    char ask;
    cout<<GetPlayerName()<<", do you want a hit?(y/n):";
    cin>>ask;
    if(ask == 'n'){
        for(int i = 0; i < pokerNum; i++){
            if(playerPoker[i]->GetPoint() == 1){
                if(pokerPoint + 10 <= 21)
                    pokerPoint = pokerPoint + 10;
                break;
            }
        }
    }
    return ask;
}

void GeneralPlayer::GetNewPoker(Poker *pk){
    playerPoker[pokerNum] = pk;
    /*
     玩家手上的牌都是公开的，但扑克牌固有属性是不可见的，所以每次拿到牌都要修改属性
     并且改变属性的牌是手中的牌，而不是原来的扑克牌，也就是说这两步调换算法上没差别，但是改变手中牌的明暗牌属性会更符合现实
     */
    playerPoker[pokerNum]->ChangeFlag(true);
    SumPokerNum();
    pokerNum++;
}

GeneralPlayer::~GeneralPlayer(){
    delete []playerPoker;
}
