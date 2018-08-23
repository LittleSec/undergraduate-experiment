//
//  House.h
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#ifndef House_h
#define House_h

#include"Player.h"

class House:public Player{
public:
    House();
    
    char IfGetPoker();//是否要牌
    void GetNewPoker(Poker *pk);//抽牌
    bool IfOver16();
    
    void ShowInfo();//打印基本信息
    ~House();
};

#endif /* House_h */
