#ifndef PARK&AUTOMOBILE_H_INCLUDED
#define PARK&AUTOMOBILE_H_INCLUDED

class Park{
public:
    void showInfo();

private:
    static int space;
};

#endif // PARK&AUTOMOBILE_H_INCLUDED


停车场（Park）有 N 个停车位（Space） ，每个停车位可以停放不同类型
的汽车（Automobile） ，包括卡车（Truck） 、轿车（Car） 、公交车（Bus） ，但同一
时刻一个停车位只能停放 0 或 1 辆汽车。如果没有空余停车位，显示提示信息，
但不会为车辆安排停车位。
2．程序模拟车辆停车的情况：新来车辆时如果有空位，按顺序为该车分配
停车位；车辆开走时，应交纳停车费。
3．停车场可以显示当前停放的车辆的车牌号码，以及当前的全部停车费收
入（income） 。
4．定义汽车基类 Automobile，包括车牌号码（字符串）成员数据。
5．定义派生类 Truck、Car、Bus。这些车辆除了拥有车牌号码之外，还各自
拥有不同的属性。Truck 还包括载重量属性（浮点数，单位吨） ；Car还拥有品牌
属性（字符串） ，Bus还包括核定载员数量（整型） 。
2
此外，每个派生类中要实现 pay()函数，用于显示车辆信息并交纳停车费。
其中，Truck 收费 3元/次，Car收费 1元/次，Bus收费 2元/次。
（2）问题要求
编写程序， 测试上述所要求的各种功能。 要求创建新的工程项目 ParkManager，
添加必要的源文件和头文件，并在程序适当的位置中编写注释。
