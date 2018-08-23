#ifndef HOUSEAPP_H_INCLUDED
#define HOUSEAPP_H_INCLUDED
#include<string>
#include"Commodity.h"
class HouseApp:public Commodity{
public:
    HouseApp(string name, double price, double num, double power);
    double getFinalPrice(); // 购买该商品最终需要支付的金额，要考虑优惠策略
    void showInfo() const;  // 输出该商品的信息：名称、标牌价格、购买数量
private:
    double power;
};

#endif // HOUSEAPP_H_INCLUDED
