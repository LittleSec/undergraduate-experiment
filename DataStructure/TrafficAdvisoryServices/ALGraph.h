#ifndef ALGRAPH_H_INCLUDED
#define ALGRAPH_H_INCLUDED

#include<iostream>
#include<cstring>
#include<string>

#define MAX_FILE_NAME_LEN 12//最长文件名字

using namespace std;

//关于时间的格式hour:minute,+day
typedef struct Time{
    int day;
    int hour;
    int minute;

    //重载
    //给出出发时间和到达时间，计算所用时间，默认到达时间“大于”出发时间
    //默认结束时间的天数输入有误，即，本应该加1，但是却加零
    friend Time operator- (Time &et, Time &st){
        Time t = {0, 0, 0};
        t.minute = et.minute - st.minute;//计算分
        if(t.minute < 0){//相当于借位
            t.minute += 60;
            t.hour--;
        }

        t.hour = t.hour + et.hour - st.hour;//计算时
        if(t.hour < 0){
            t.hour += 24;
            t.day--;
        }

        if(et.day <= st.day)//此时如果天数相等，那么说明录入的时候结束时间的天数是错误的
            t.day++;
        t.day = t.day + et.day - st.day;//计算天
        return t;
    }
}Time;

typedef struct InfoType{
    string LineName;//航班或车次号，默认最长为8（算上'\0'）
    Time StartTime, EndTime;//出发、到达时间
    Time SpendTime;//所花费的时间
    float SpendMoney;//所花费的金钱
}TrafficLine;

typedef struct ArcNode{//表结点
    string EndCityName;//该弧所指向的城市，即终点城市
    struct ArcNode *NextLine;//指向下一条弧的指针
    TrafficLine *Info;//该弧相关信息的指针（该线路的信息）
}LineNode;

typedef struct VNode{//头结点
    string CityName;//地名
    int CityOrd;//编号
    LineNode *FirstLine;//指向第一条依附该顶点的弧的指针
    int Amount;//交通工具的班次数
}VNodeDat;

//顶点节点，保存id和到源顶点的估算距离，优先队列需要的类型
struct Node;//用于计算最省钱路径。
struct Node1;//用于计算最省时路径。

class ALGraph{
public:
    ALGraph(int size);
    int SearchCityNum(const string Cityname);//查询城市编号
    void AddCity(const string Cityname);//手动添加城市
    void AddCityFromFile(const char FileName[MAX_FILE_NAME_LEN]);//从文件中导入城市
    void DelCity(const string Cityname);//删除城市
    void InsertHead(string StartName, LineNode *temp, string EndName);//头插线路
    void AddLine();//手动添加线路
    void AddLineFromFile(const char FileName[MAX_FILE_NAME_LEN]);//从文件中的导入线路
    void DelCityLine(int i);//删除以该城市为起点的航班
    void DelLine();//删除线路
    void ReSize(int size);//重新开辟城市列表
    void UpdateFile(const char FileName[MAX_FILE_NAME_LEN], const string type);//同步文件
    void ShowAllLine();//输出所有线路
    void ShowCity();//输出城市
    void Dijkstra_Money(int v0, int *path, Node *dist);//计算最省钱路径
    void Dijkstra_Time(int v0, int *path, Node1 *dist);//计算最省时路径
    void SearchShortestPath(const string type);//调用并打印最短路径
    ~ALGraph();
private:
    VNodeDat *CityList;//城市列表，即头结点数组
    int MaxCityNum;//当前数组的长度
    int CityNum;//城市个数，即图的顶点数
    int arcnum;//图的弧数
};

#endif // ALGRAPH_H_INCLUDED
