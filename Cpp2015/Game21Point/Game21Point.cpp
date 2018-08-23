//
//  Game21Point.cpp
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#include<iostream>
#include<stdlib.h>
#include"time.h"
#include"Game21Point.h"
using namespace std;

Game21Point::Game21Point(int n){
    int i;
    N = n+1;//这里的N记录的是所有玩家的数量包括庄家和普通玩家，而传过来的是普通玩家的数量，所以要+1
    
    players = new Player*[N];
    //因为不能立刻确定player对象双指针指向哪，为了防止内存混乱，先赋值为NULL
    for(i = 0;i < N;i++)
        players[i] = NULL;
    
    poker_now = 0;
    player_now = 0;
    point_max = 0;
    count1 = 0;
}

void Game21Point::EnterGame(Player *pl){
    players[player_now] = pl;
    player_now++;
}

//初始化一副扑克牌
void Game21Point::CreatePoker(){
    pk = new Poker*[52];
    //初始化点数
    for(int i=0;i<13;i++){
        pk[i] = new Poker(i+1,i+49,4);//方块:D-Diamond，对应有形状字符，ASCII是4
        pk[i+13] = new Poker(i+1,i+49,5);//梅花:C-Club
        pk[i+26] = new Poker(i+1,i+49,3);//红心:H-Heart
        pk[i+39] = new Poker(i+1,i+49,6);//黑桃:S-Spade
    }
    //完善一副扑克牌
    for(int i =0; i< 52; i++){
        if(pk[i]->GetPoint() == 1)
            pk[i]->ChangeRpoint('A');
        else if(pk[i]->GetPoint() == 11){//点数为11的牌面字母是J，在游戏中当10点处理，QK同理
            pk[i]->ChangeRpoint('J');
            pk[i]->ChangePoint(10);
        }
        else if(pk[i]->GetPoint() == 12){
            pk[i]->ChangeRpoint('Q');
            pk[i]->ChangePoint(10);
        }
        else if(pk[i]->GetPoint() == 13){
            pk[i]->ChangeRpoint('K');
            pk[i]->ChangePoint(10);
        }
    }
}

//洗牌原理：随机从0-51中抽取两个数作为扑克牌数组的下标然后交换，其中调用默认复制构造函数，交换1000次，共调用3*1000次
void Game21Point::ShufflePoker(){
    int n=52;
    int i,j,T=1000;
    Poker *tmp;
    srand(unsigned(time(NULL)));
    while(T--)
    {
        i=rand()%n;
        j=rand()%n;
        tmp=pk[i];
        pk[i]=pk[j];
        pk[j]=tmp;
    }
}

/*
 发牌函数原理：参数是一个Player的指针对象，
 调用其要牌函数（该函数形参是一个Poker的指针对象，把当前序号的扑克牌传过给玩家），
 达到给玩家一张扑克牌的目的
 */
void Game21Point::SendCard(Player *pl){
    //理论上应该先判断扑克牌是否到底了，否则当玩家多了的时候有可能越界
    pl->GetNewPoker(pk[poker_now]);
    poker_now++;
}

void Game21Point::Control(){
    //发牌前准备
    CreatePoker();//创造一副（顺序化的）扑克牌
    ShufflePoker();//洗牌
    player_now = 0;//由于玩家纷纷加入游戏后，当前玩家序号不再是一开始，而player_now还作为计数，所以重新初始化该成员变量
    
    //先每个人发牌两张并打印在屏幕上
    for(int i = 0; i < N; i++){
        SendCard(players[i]);
        SendCard(players[i]);
        players[i]->ShowInfo();
    }
    cout<<endl;
    
    /*
     开始控制，由于多态的实现，普通玩家和庄家的操作是一样的
     先从普通玩家开始轮流要牌，最后轮到庄家
     */
    for(;player_now<N;player_now++){
        if(player_now != 0)//提示用户当前最大点数，给是否要牌的决定作一个参考
            cout<<"                    Now, the max point is "<<point_max<<endl;
        players[player_now]->ShowInfo();
        //玩家过多的时候由于屏幕大小有限，之前打印的信息可能要滚上去才能看见，这样给用户带来麻烦，所以打印一次
        
        while(players[player_now]->IfGetPoker()  == 'y'){
            //如果要牌，则发牌并打印
            SendCard(players[player_now]);
            players[player_now]->ShowInfo();
            //判断是否爆牌，爆牌则打印信息并跳出循环，轮到下一个玩家
            if(players[player_now]->IfOver21()){
                cout<<players[player_now]->GetPlayerName()<<" busts."<<endl;
                break;
            }
        }
        //玩家停止要牌后，判断是否为当前最大点数，是，则记录最大点数到系统，不是则继续轮流下一个玩家，本操作不处理庄家
        if(!players[player_now]->IfOver21() && player_now != N-1)
        {
            cout<<"Now, "<<players[player_now]->GetPlayerName()<<"'s point is "<<players[player_now]->GetPokerPoint()<<endl;
            //打印信息是为了对A的处理结果进行显示
            if(players[player_now]->GetPokerPoint() > point_max)
                point_max = players[player_now]->GetPokerPoint();
        }
        cout<<endl;
    }
    //所有玩家轮流完后，记录最大点数的玩家序号，不处理庄家
    for(player_now = 0;player_now < N-1;player_now++){
        if(players[player_now]->GetPokerPoint() == point_max){
            max_player[count1] = player_now;
            count1++;
        }
    }
}

void Game21Point::referee(){
    //因为庄家是轮流到最后的，所以此时的players[player_now]就是庄家
    //庄家爆牌了
    if(players[player_now]->IfOver21()){
        //普通玩家有没有爆牌的，则普通玩家赢
        if(point_max != 0){
            cout<<players[max_player[0]]->GetPlayerName();
            if(count1 > 1)
                for(int i = 1; i < count1; i++)
                    cout<<", "<<players[max_player[i]]->GetPlayerName();
            cout<<" wins.("<<point_max<<")"<<endl;
        }
        //所有普通玩家都爆牌了
        else
            cout<<"It's a draw."<<endl;
    }
    //庄家没爆牌
    else{
        //庄家点数大于系统记录的普通玩家最大点数，则普通玩家赢
        if(players[player_now]->GetPokerPoint() > point_max)
            cout<<"House wins.("<<players[player_now]->GetPokerPoint()<<")"<<endl;
        //等于则平局
        else if(players[player_now]->GetPokerPoint() == point_max)
            cout<<"It's a draw."<<endl;
        else{
            if(point_max != 0){
                cout<<players[max_player[0]]->GetPlayerName();
                if(count1 > 1)
                    for(int i = 1; i < count1; i++)
                        cout<<", "<<players[max_player[i]]->GetPlayerName();
                cout<<" wins.("<<point_max<<")"<<endl;
            }
        }
    }
}

Game21Point::~Game21Point(){
    delete []players;
    delete []pk;
}
