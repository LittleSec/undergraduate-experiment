#include<iostream>
#include"Clothing.h"
using namespace std;

Clothing::Clothing(string name, double price, double num, string Csize):
    Commodity(name, price, num),Csize(Csize){};

double Clothing::getFinalPrice(){// 购买该商品最终需要支付的金额，要考虑优惠策略
    return (0.9*Commodity::price) * Commodity::num;
}

void Clothing::showInfo() const{// 输出该商品的信息：名称、标牌价格、购买数量
    cout<<Commodity::name<<","<<Commodity::price<<","<<Commodity::num<<","<<Csize<<endl;
}

