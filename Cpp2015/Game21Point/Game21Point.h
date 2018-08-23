//
//  Game21Point.h
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#ifndef Game21Point_h
#define Game21Point_h

#include"Player.h"
#include"Poker.h"

class Player;

class Poker;

class Game21Point{
public:
    Game21Point(int n);
    void EnterGame(Player *pl);
    void CreatePoker();//初始化一副扑克牌
    void ShufflePoker();//洗牌
    void SendCard(Player *pl);//发牌
    void Control();
    void referee();//裁判
    ~Game21Point();
private:
    int N;//玩家数,0~N-1是普通玩家，N是庄家
    Player **players;
    Poker **pk;
    int poker_now;//当前的纸牌序号
    int player_now;//当前的玩家序号
    int point_max;//当前最大点数
    int max_player[7];//最大点数的玩家序号（数组）
    int count1;//最大点数的玩家个数
};

#endif /* Game21Point_h */
