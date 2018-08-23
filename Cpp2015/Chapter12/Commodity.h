#ifndef COMMODITY_H_INCLUDED
#define COMMODITY_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;

//商品类
//数据成员包括：商品名称（name，string 类型）、标牌价格（price，double类型）、购买数量（num，double类型）。
class Commodity{
public:
    Commodity(string name, double price, double num):name(name),price(price),num(num){};
    virtual double getFinalPrice() = 0; // 购买该商品最终需要支付的金额，要考虑优惠策略
    virtual void showInfo() const = 0;  // 输出该商品的信息：名称、标牌价格、购买数量
//    double operator + (Commodity &C1 ) const{// + 运算符的重载

protected:
    string name;
    double price;
    double num;
};

#endif // COMMODITY_H_INCLUDED
