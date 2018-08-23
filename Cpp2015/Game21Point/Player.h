//
//  Player.h
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include<string>
#include"Game21Point.h"
#include"Poker.h"
using namespace std;

class Game21Point;

class Poker;

class Player{
public:
    Player();
    Player(const string name);
    
    void EnterGames(Game21Point *game);//加入游戏
    void SumPokerNum();//计算手中牌的点数
    
    virtual char IfGetPoker()=0;//是否要牌
    virtual void GetNewPoker(Poker *pk)=0;//抽牌
    bool IfOver21()const;//是否大于21点
    
    int GetPokerPoint()const;//外部接口
    string GetPlayerName()const;
    int GetPokerNum()const;
    
    virtual void ShowInfo()=0;//打印基本信息
    
    ~Player(){};
protected:
    Poker **playerPoker; //手中的牌
    int pokerPoint;//手中牌的点数
    int pokerNum;//手中牌的数量
private:
    string name;//玩家姓名
};

#endif /* Player_h */
