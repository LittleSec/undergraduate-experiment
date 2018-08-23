#ifndef CLOTHING_H_INCLUDED
#define CLOTHING_H_INCLUDED
#include<string>
#include"Commodity.h"
//服装类包含数据成员：尺码（size，string类型）
class Clothing:public Commodity{
public:
    Clothing(string name, double price, double num, string Csize);
    double getFinalPrice(); // 购买该商品最终需要支付的金额，要考虑优惠策略
    void showInfo() const;  // 输出该商品的信息：名称、标牌价格、购买数量
private:
    string Csize;
};

#endif // CLOTHING_H_INCLUDED
