#include<iostream>
#include<string>
#include"Automobile.h"
#include"Park.h"
#include"Car.h"
#include"Bus.h"
#include"Truck.h"

using namespace std;

int main() {
    int N;
    cout << "请输入停车位数量：";
    cin >> N;// 输入停车位数量，此处输入2

    Park park(N);// 创建一个停车场对象

    Automobile *auto1 = new Car("鲁B-12345", "奥迪A6");  // 创建轿车对象
    Automobile *auto2 = new Truck("鲁B-23456", 15);      // 创建卡车对象
    Automobile *auto3 = new Bus("鲁B-34567", 50);        // 公交车对象
    Automobile *auto4 = new Car("鲁B-45678", "宝马320");// 创建轿车对象

    auto1->enter(&park);   // car进入停车场，分配停车位
    auto2->enter(&park);   // truck进入停车场，分配车位
    auto1->leave(&park);   // car离开停车场，缴纳停车费
    auto3->enter(&park);   // bus进入停车场，分配车位

/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/

    park.showInfo();

    auto4->enter(&park);      // car进入停车场，分配停车位
// car进入停车场，分配停车位。因为没有空余停车位，所以无法分配

    auto3->leave(&park);  // bus离开停车场，缴纳停车费
    auto2->leave(&park);  // truck离开停车场，缴纳停车费

/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park.showInfo();

    return 0;
}
