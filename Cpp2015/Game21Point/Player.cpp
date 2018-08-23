//
//  Player.cpp
//  Game21Point
//
//  Created by 小婊砸 on 2017/8/30.
//  Copyright © 2017年 LittleSec. All rights reserved.
//

#include<iostream>
#include<string>
#include"Player.h"
using namespace std;

Player::Player(){}

Player::Player(const string name){
    this->name = name;
}

void Player::EnterGames(Game21Point *game){
    game->EnterGame(this);
}

string Player::GetPlayerName()const{
    return name;
}

void Player::SumPokerNum(){
    pokerPoint += playerPoker[pokerNum]->GetPoint();
}

bool Player::IfOver21()const{
    if(pokerPoint > 21)
        return true;
    else
        return false;
}

int Player::GetPokerPoint()const{
    return pokerPoint;
}

int Player::GetPokerNum()const{
    return pokerNum;
}

