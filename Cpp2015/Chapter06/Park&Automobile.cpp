#include<iostream>
#include<string>
using namespace std;

class Park{
public:
    Park(int sp, double income=0):space(sp),income(income){}
    void showInfo();
    int getspace(){return space;}
private:
    int space;//停车位数量
    double income;
};

class Automobile{
public:
    Automobile(string number):car_number(number){}
    void enter(park);
    void leave(park);
private:
    Park park;
    string car_number;//车牌号码
};

class Truck:public Automobile{
    double heavy;//核定载重
public:
    Truck(string num, double heavy):Automobile(num),heavy(heavy){}
    void pay();//用于显示车辆信息并交纳停车费
};

class Car:public Automobile{
    string brand;//品牌
public:
    Car(string num, string brand):Automobile(num),brand(brand){}
    void pay();//用于显示车辆信息并交纳停车费
};

class Bus:public Automobile{
    int carry;//核定载员
public:
    Bus(string num, int carry):Automobile(num),carry(carry){}
    void pay();//用于显示车辆信息并交纳停车费
};

int main(){
    int N;
    cout << "请输入停车位数量：";
    cin >> N;// 输入停车位数量，此处输入2

    Park park(N);// 创建一个停车场对象

    Car car1("鲁B-12345","奥迪A6");  // 创建轿车对象
    car1.enter(park);    // car1进入停车场，分配停车位

    Truck truck("鲁B-23456", 15);  // 创建卡车对象
    truck.enter(park);   // truck进入停车场，分配车位

    car1.leave(park);   // car1离开停车场，缴纳停车费

    Bus bus("鲁B-34567", 50);  // 创建公交车对象
    bus.enter(park);   // bus进入停车场，分配车位

/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park.showInfo();

    Car car2("鲁B-45678","宝马320");  // 创建轿车对象
    car2.enter(park);
// car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配

    bus.leave(park);  // bus离开停车场，缴纳停车费
    truck.leave(park);  // truck离开停车场，缴纳停车费


/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
    park.showInfo();

    return 0;
}
