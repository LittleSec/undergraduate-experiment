//
//  main.cpp
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#include <iostream>
#include <string>
#include"Game21Point.h"
#include"Player.h"
#include"GeneralPlayer.h"
#include"House.h"

using namespace std;

int main()
{
    char again;//是否再来一局的控制字符
    
    cout<<"             Welcome to Blackjack!"<<endl<<endl;
    do{
        int i,N;//i用来循环计数，N是普通玩家的人数，需要用户输入
        string *name;
        Player **players;
        
        cout<<"How many players?(1 - 7)";
        cin>>N;
        
        //游戏只允许1-7个普通玩家玩
        while(N<1 || N>7){
            cout<<"Error Input! Please input again(1 - 7):";
            cin>>N;
        }
        Game21Point game21point(N);//创建游戏系统
        
        //输入玩家名字
        name =new string [N];
        for(i = 0;i < N;i++){
            cout<<"Enter player"<<i+1<<"'s name:";
            cin>>name[i];
        }
        
        //创建玩家对象，包括N个普通玩家和1个庄家
        players = new Player*[N+1];
        for(i = 0;i < N;i++){
            players[i] =new GeneralPlayer(name[i]);
            players[i]->EnterGames(&game21point);
        }
        players[N] = new House;
        players[N]->EnterGames(&game21point);
        
        cout<<endl;
        
        //游戏正式开始
        game21point.Control();
        game21point.referee();
        
        cout<<endl;
        
        //内存释放
        delete []name;
        delete []players;
        
        //容错性
        cout<<"Do you want to play again?(y/n):"<<endl;
        cin>>again;
    }while(again == 'y');
    
    return 0;
}
