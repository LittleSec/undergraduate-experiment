//
//  GeneralPlayer.h
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#ifndef GeneralPlayer_h
#define GeneralPlayer_h

#include"Player.h"

class GeneralPlayer:public Player{
public:
    GeneralPlayer(const string name);
    
    char IfGetPoker();//是否要牌
    void GetNewPoker(Poker *pk);//抽牌
    
    void ShowInfo();//打印基本信息
    ~GeneralPlayer();
};

#endif /* GeneralPlayer_h */
