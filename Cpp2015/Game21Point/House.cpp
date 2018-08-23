//
//  House.cpp
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#include<iostream>
#include<iomanip>
#include"House.h"
using namespace std;

//把House当作庄家名字，以便于抽象类的多太实现
House::House():Player("House"){
    playerPoker = new Poker*[11];
    pokerNum = 0;
    pokerPoint = 0;
}

void House::ShowInfo(){
    cout<<setiosflags(ios_base::left)<<setw(7)<<GetPlayerName()<<":";
    for(int i = 0; i < pokerNum; i++){
        playerPoker[i]->ShowPoker();
        cout<<"     ";
    }
    /*
     庄家发牌时，第一张牌是不可见的，但之后这张牌就可见了，
     换句话说，第一次调用该函数时就可以修改第一张牌的翻牌属性
     并且第一次调用该函数时是不需要打印总点数的，因为有张牌是不可见
     */
    if(playerPoker[0]->GetIfShow() == false){
        cout<<endl;
        playerPoker[0]->ChangeFlag(true);
    }
    else
        cout<<"("<<pokerPoint<<")"<<endl;
}

/*
 庄家持牌总点数少于或等于16点，则必须要牌
 若把A算为11时点数总和大于16点，则把A算为11点，否则算为1点。
 */
bool House::IfOver16(){
    for(int i = 0; i < pokerNum; i++)
        if(playerPoker[i]->GetPoint() == 1)
            if(pokerPoint + 10 > 16 && pokerPoint + 10 <= 21)
                //如果把A当11算的时候点数超过21而当1没超过的16的情况，应该算是小于16点的情况，系统会自动为其发牌。
                return true;//最多也就有一张A能看成11，所以检索到有A便可以处理并结束程序
    if(pokerPoint > 16)
        return true;
    else
        return false;
}

char House::IfGetPoker(){
    if(IfOver16() == false)
        return 'y';//小于或等于16点直接返回y，提示系统发牌
    else{
        char ask;
        cout<<GetPlayerName()<<", do you want a hit?(y/n):";
        cin>>ask;
        if(ask == 'n'){
            /*
             A在停止要牌前系统都先当1计算
             若输入的是‘n’，则在此函数处理手上A的牌：所有玩家如果A算为11时总和大于21，则A算为1
             因为同一类的成员，公有成员能直接修改私有成员，若在外部调用测试函数，然后再进行修改则要再重新提供外部修改函数，
             扑克牌类的修改点数函数是用于初始化扑克牌的
             而且准确来说不是修改点数，只是人将其视为其他点数，也就是不应该修改扑克牌本来的属性
             */
            for(int i = 0; i < pokerNum; i++){
                if(playerPoker[i]->GetPoint() == 1){
                    if(pokerPoint + 10 <= 21)
                        pokerPoint = pokerPoint + 10;
                    break;//最多也就有一张A能看成11，所以检索到有A便可以处理并结束程序
                }
            }
        }
        return ask;
    }
}

void House::GetNewPoker(Poker *pk){
    playerPoker[pokerNum] = pk;//先把得到的牌计入玩家手上的扑克牌
    if(GetPokerNum() != 0)//如果是庄家得到的第一（0）张牌，默认对外不可见，其他牌都对外可见
        playerPoker[pokerNum]->ChangeFlag(true);
    /*
     由于SumPokerNum()该函数只负责计数，不负责自增
     自增按照现实来说本应该是此函数实现的，而且如果让SumPokerNum()容易造成数组越界
     若在此函数先自增在调用SumPokerNum()同样容易造成数组越界
     */
    SumPokerNum();
    pokerNum++;
}

House::~House(){
    delete []playerPoker;
}

