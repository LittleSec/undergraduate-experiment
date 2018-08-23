//
//  Poker.h
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#ifndef Poker_h
#define Poker_h

#include<iostream>
#include<string>
#include"Game21Point.h"

class Player;

class Game21Point;

class Poker{
public:
    Poker(int point,char Ppoint,char suit);//初始化一张扑克牌
    Poker(){};//为了其他类的声明
    void ChangeFlag(bool fl);//改变是否翻牌的bool
    void ChangePoint(int pt);//改变点数，初始化用
    void ChangeRpoint(char rp);//改变片面字母，初始化用
    void ShowPoker();//打印单张扑克牌
    int GetPoint()const;//外部接口
    bool GetIfShow()const;
private:
    int point;//点数
    char Rpoint;//牌面字母
    char suit;//花色
    bool IfShow;//是否翻牌，打印函数先判断一下
};

#endif /* Poker_h */
