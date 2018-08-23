#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<istream>
#include<ostream>
#include<queue>
#include<stack>
#include"ALGraph.h"
using namespace std;

#define MAX_FILE_NAME_LEN 12//最长文件名字
#define ADD_CITY 5//城市列表存储空间配增量
#define INF 30000//默认最大值

istream & operator >> (istream &in, Time &time){//书上P313和314、499
    int day, hour, minute;
    char c1, c2, c3;//识别冒号或连接符
    in>>hour>>c1>>minute>>c2>>c3>>day;
    time.day = day;
    time.minute = minute;
    time.hour = hour;
    return in;
}

ostream & operator << (ostream &out, Time &time){//书上P313和314、499
    cout.fill('0');
    out<<setw(2)<<setiosflags(ios_base::right)<<time.hour<<":"
        <<setw(2)<<time.minute<<resetiosflags(ios_base::right)<<","
        <<setiosflags(ios_base::showpos)<<time.day<<resetiosflags(ios_base::showpos);
        //setiosflags的影响是持久的，需要手动关闭，showpos是加正号
    cout.fill(' ');//也是持久的
    return out;
}

ALGraph::ALGraph(int size){
    CityList = new VNodeDat[size];
    int i;
    for(i = 0; i < size; i++){
        CityList[i].Amount = 0;
        CityList[i].CityOrd = i;
        CityList[i].FirstLine = NULL;
        CityList[i].CityName = "NULL";
    }
    CityNum = 0;
    MaxCityNum = size;//当前城市最大个数
    arcnum = 0;
}//ALGraph

//查询城市编号，成功返回编号，找不到返回-1
int ALGraph::SearchCityNum(const string Cityname){
    int i;
    for(i = 0; i < CityNum; i++)
        if(CityList[i].CityName == Cityname)
            return i;
    return -1;
}//SearchCityNum

//重新开辟城市列表，只考虑增多，不考虑减少
void ALGraph::ReSize(int size){
    if(size <= CityNum)//已经包括size为负数的情况
        return;
    VNodeDat *NewList = new VNodeDat[size];
    int i;
    for(i = 0; i < CityNum; i++)//不是CityNum-1
        NewList[i] = CityList[i];//结构体赋值会整体赋值，前提是后者都要有值。

    for(i = CityNum; i < size; i++){
        NewList[i].Amount = 0;
        NewList[i].CityOrd = i;
        NewList[i].FirstLine = NULL;
        NewList[i].CityName = "NULL";
    }
    delete []CityList;
    CityList = NewList;
}//ReSize

//手动添加城市
void ALGraph::AddCity(const string Cityname){
    if(SearchCityNum(Cityname) != -1){//城市已有
        cout<<"The city has been in the list!"<<endl;
        return ;
    }
    if(CityNum >= MaxCityNum){//空间已满
        MaxCityNum = MaxCityNum + ADD_CITY;//追加空间
        ReSize(MaxCityNum);
        if(!CityList){//重新分配失败
            cout<<"Realloc Failed!"<<endl;
            return;
        }
    }
    CityList[CityNum].CityName = Cityname;
    CityList[CityNum].CityOrd = CityNum;
    CityList[CityNum].FirstLine = NULL;
    CityList[CityNum].Amount = 0;
    CityNum++;
}//AddCity

//从文件中导入城市
void ALGraph::AddCityFromFile(const char FileName[MAX_FILE_NAME_LEN]){
    cout << "从" << FileName << "文件中导入城市！" << endl;
	ifstream fileStream(FileName);
	if (!fileStream) {
		cout << "不能打开文件" << FileName << "，请确认文件是否存在" << endl;
		return ;
	}

	string line;
	int count;
	getline(fileStream, line);
    istringstream strStream(line);
    strStream >> count;
    if(CityNum + count >= MaxCityNum){//空间已满
        MaxCityNum = CityNum + count + ADD_CITY;//追加空间
        ReSize(MaxCityNum);
        if(!CityList){//重新分配失败
            cout << "Realloc Failed!" << endl;
            return;
        }
    }

	while (getline(fileStream, line)) { // 从文本文件中读入1行
		istringstream strStream(line);
		string name;
		strStream >> name;
		AddCity(name);
	}
    cout << "城市导入完毕！" << endl;
    fileStream.close();
}//AddCityFromFile

//头插线路
void ALGraph::InsertHead(string StartName, LineNode *temp, string EndName){
    LineNode *p, *q;//p在后，q在前，
    int StartNum;
    StartNum = SearchCityNum(StartName);
    if(StartNum == -1){//若无该城市，则新建城市
        AddCity(StartName);
        StartNum = SearchCityNum(StartName);//更新序号，不然插入传参就错了
    }
    if(SearchCityNum(EndName) == -1)//别用ERROR,似乎系统定义的ERROR不只是-1
        AddCity(EndName);

    p = CityList[StartNum].FirstLine;
    if(p == NULL){//原本没有航班的情况
        CityList[StartNum].FirstLine = temp;//不能p = temp
        temp->NextLine = NULL;
    }//if
    else{
        q = p->NextLine;
        while(q != NULL && EndName != q->EndCityName){//把终点城市相同的航线放到一起
            //前后顺序不能倒，而且应该是判断p空而不是p->next
            p = q;
            q = q->NextLine;
        }
        p->NextLine = temp;
        temp->NextLine = q;
    }//else
    CityList[StartNum].Amount++;//航班加一
    arcnum++;//图的弧数加一
}//InsertHead

//手动添加线路
void ALGraph::AddLine(){
    string StartName, EndName;
//=================信息输入===============
    cout<<"请输入起点城市：";
    cin>>StartName;
    cout<<"请输入终点城市：";
    cin>>EndName;
    LineNode *temp = new LineNode;//temp用于开辟空间存入数据
    TrafficLine *info = new TrafficLine;
    temp->EndCityName = EndName;
    cout<<"请输入班次名：";
    cin>>info->LineName;
    cout<<"请输入出发时间：(hh:mm,+d)";
    cin>>info->StartTime;
    cout<<"请输入到达时间：(hh:mm,+d)";
    cin>>info->EndTime;
    info->SpendTime = info->EndTime - info->StartTime;
    cout<<"请输入票价：";
    cin>>info->SpendMoney;
    temp->Info = info;

    InsertHead(StartName, temp, EndName);
}//AddLine

//从文件中的导入线路
void ALGraph::AddLineFromFile(const char FileName[MAX_FILE_NAME_LEN]){
    cout << "从" << FileName << "文件中导入线路！" << endl;
	ifstream fileStream(FileName);
	if (!fileStream) {
		cout << "不能打开文件" << FileName << "，请确认文件是否存在" << endl;
		return;
	}

    string StartName, EndName;
	string catalogue;//文件首行是目录
	getline(fileStream, catalogue);//默认终止字符是换行字符
//   istringstream strStream(catalogue);
//    strStream >> catalogue;
    string line;
    while(getline(fileStream, line)){ // 从文本文件中读入1行
		istringstream strStream(line);
		LineNode *temp = new LineNode;//temp用于开辟空间存入数据
        TrafficLine *info = new TrafficLine;
        temp->Info = info;
        string StartName, EndName;
		strStream >> StartName >> EndName >> info->LineName
                >> info->StartTime >> info->EndTime >> info->SpendTime >> info->SpendMoney;
        info->SpendTime = info->EndTime - info->StartTime;
        temp->EndCityName = EndName;

        InsertHead(StartName, temp, EndName);
	}//while;
	fileStream.close();
	cout << "线路导入完毕！" << endl;
}//AddLineFromFile

//删除线路
//默认删除的线路间的城市是存在的，即默认输入正确
void ALGraph::DelLine(){
    int StartNum;
    string StartName, EndName;
    string linename;

    cout << "请输入起点城市：";
    cin>>StartName;
    cout << "请输入终点城市：";
    cin>>EndName;
    StartNum = SearchCityNum(StartName);
    cout << "该城市间的线路有：" << endl;
    cout << "起点城市 终点城市 班次名 出发时间 到达时间   用时   票价" << endl;;
    LineNode *p, *q;
    int flag = 1;

    p = CityList[StartNum].FirstLine;
    for(; p; p = p->NextLine)
        //若是判断p->next是否为空，逻辑是错误的，因为最后一个结点也要判断
        if(p->EndCityName == EndName){
            cout<<setw(8)<<StartName<<" "<<setw(8)<<EndName<<" "<<setw(6)<<p->Info->LineName<<" "
                <<p->Info->StartTime<<" "<<p->Info->EndTime<<" "<< p->Info->SpendTime<<" "
                <<p->Info->SpendMoney<<endl;
            flag = 0;
        }
    if(flag){//没有符合航班，告知用户没有，头结点为空也在此返回
        cout << "NULL!" << endl;
        return;
    }

    cout << endl;
    cout << "请输入你要删除的航班号：";
    cin>>linename;
    p = CityList[StartNum].FirstLine;
    q = p->NextLine;
    if(!q){//只有一个结点
        if(p->Info->LineName != linename){
            cout<< "没有该班次！" << endl;
            return;
        }
        else{
            CityList[StartNum].FirstLine = q;
            CityList[StartNum].Amount--;
            arcnum--;//图的弧数减一
            delete p->Info;
            delete p;
            return;
        }
    }
    while(q->Info->LineName != linename && q->NextLine){//删除的是q
        p = q;
        q = q->NextLine;
    }
    //跳出循环有两种可能，一是名字相等，二是到头了
    if(q->Info->LineName != linename){//这是到头了的情况
        cout<< "没有该班次！" << endl;
        return;
    }
    else{
        p->NextLine = q;
        CityList[StartNum].Amount--;
        arcnum--;//图的弧数减一
        delete q->Info;
        delete q;
        return;
    }
}//DelLine

//同步文件
void ALGraph::UpdateFile(const char FileName[MAX_FILE_NAME_LEN], const string type){
    cout << "同步数据到" << FileName << "文件！" << endl;
    ofstream fileStream(FileName);
    if (!fileStream) {
		cout << "不能打开文件" << FileName << "，请确认文件是否存在" << endl;
		return;
	}

    int i;
    LineNode *p = NULL;
    if(type == "City"){
        fileStream << CityNum << endl;
        for(i = 0; i < CityNum; i++)
            fileStream << CityList[i].CityName << endl;
        cout << "Update city file ok!" << endl;
    }
    else if(type == "Line"){
        fileStream << "出发城市|到达城市|班次名|出发时间|到达时间||||用时|||票价" << endl;
        for(i = 0; i < CityNum; i++)
            for(p = CityList[i].FirstLine; p != NULL; p = p->NextLine){
                fileStream<<setw(8)<<CityList[i].CityName<<" "<<setw(8)<<p->EndCityName<<" "<<setw(6)<<p->Info->LineName<<" ";
                fileStream.fill('0');
                fileStream<<p->Info->StartTime<<" "<<p->Info->EndTime<<" "<<p->Info->SpendTime<<" "
                    <<setiosflags(ios_base::showpoint)<<p->Info->SpendMoney<<endl;//不用取消，因为只有money是浮点数，该标志只对浮点数有效
                fileStream.fill(' ');
            }
        cout << "Update line file ok!" << endl;
    }
    fileStream.close();
}//UpdateFile

//删除以该城市为起点的航班
void ALGraph::DelCityLine(int i){
    LineNode *p, *q;
    p = CityList[i].FirstLine;
    if(p == NULL)//空表不用删除
        return;
    while(p->NextLine){
        q = p->NextLine;
        p->NextLine = q->NextLine;
        delete q->Info;
        delete q;
    }//while
    if(p->NextLine == NULL){
        delete p->Info;
        delete p;
    }
}//DelCityLine

//删除城市，并删除以该城市为起点的所有航班和列车
void ALGraph::DelCity(string Cityname){
    int i, j;
    i = SearchCityNum(Cityname);
    if(i == -1){
        cout << "Can't find out the city!" << endl;
        return;
    }
    else{
        DelCityLine(i);//不应该放在for循环里
        for(j = i; j < CityNum - 1; j++)//上移，深复制
            CityList[j] = CityList[j + 1];
        CityNum--;//这两句放错位置了，不该放在for循环里
    }//else
    cout<<"Delete "<<Cityname<<"OK!"<<endl;
}//DelCity

void ALGraph::ShowAllLine(){
    int i;
    LineNode *p;
    if(arcnum == 0){
        cout<<"NULL line in the system!"<<endl;
        return;
    }
    cout<<"There are "<<arcnum<<" line(s) in the system:"<<endl;
    cout<<"出发城市|到达城市|班次名|出发时间|到达时间||||用时|||票价"<<endl;
    for(i = 0; i < CityNum; i++)
        for(p = CityList[i].FirstLine; p ; p = p->NextLine){
            cout<<setw(8)<<CityList[i].CityName<<" "<<setw(8)<<p->EndCityName<<" "<<setw(6)<<p->Info->LineName<<" ";
            cout.fill('0');
            cout<<p->Info->StartTime<<" "<<p->Info->EndTime<<" "<<p->Info->SpendTime<<" "
                <<setiosflags(ios_base::showpoint)<<p->Info->SpendMoney<<endl;//不用取消，因为只有money是浮点数，该标志只对浮点数有效
            cout.fill(' ');
        }
}//ShowAllLine

void ALGraph::ShowCity(){
    int i;
    string a;
    if(CityNum == 0){
        cout<<"NULL City in the system!"<<endl;
        return;
    }
    cout<<"There are "<<CityNum + 1<<" city(s) in the system:"<<endl;
    for(i = 0; i < CityNum; i++)
        cout << i << CityList[i].CityName <<endl;
}//ShowCity

ALGraph::~ALGraph(){
    int i;
    for(i = 0; i < CityNum; i++)
        DelCityLine(i);
    delete []CityList;
}//~ALGraph

//顶点节点，保存城市序号和到源顶点的估算金额，优先队列需要的类型
struct Node{
    int id;//源顶点id
    float money;//估算距离

    //因要实现最小堆，按升序排列，因而需要重载运算符，重定义优先级，以小为先
    friend bool operator < (struct Node a, struct Node b){
        return a.money > b.money;
    }
};

void ALGraph::Dijkstra_Money(int v0, int *path, Node *dist){
    priority_queue<Node>q;//P425
    //path[]记录下标对应节点的父亲节点。
    int visited[MaxCityNum];//该下标对应的顶点是否已经算出最短距离。是则为1
    //初始化
    int i;
    for(i = 0; i < CityNum; i++){
        dist[i].id = i;
        dist[i].money = INF;
        path[i] = -1;       //每个顶点都无父亲节点
        visited[i] = 0;     //都未找到最短路
    }
    dist[v0].money = 0;
    q.push(dist[v0]);
    while(!q.empty()){
        Node cd = q.top();
        q.pop();
        int u = cd.id;

        if(visited[u])
            continue;
        visited[u] = 1;
        LineNode *p = CityList[u].FirstLine;

        while(p){
            int tempv = SearchCityNum(p->EndCityName);
            float tempm = p->Info->SpendMoney;//金钱为权值
            if(!visited[tempv] && dist[tempv].money > dist[u].money + tempm){
                dist[tempv].money = dist[u].money + tempm;
                path[tempv] = u;
                q.push(dist[tempv]);
            }
            p = p->NextLine;
        }//while(p)
    }//while(!q.empty())
}//Dijkstra_Money

//顶点节点，保存城市序号和到源顶点的估算时间，优先队列需要的类型
struct Node1{
    int id;//城市序号id
    int tt;//估算时间
    Time et;//到达时间
    //因要实现最小堆，按升序排列，因而需要重载运算符，重定义优先级，以小为先
    friend bool operator < (struct Node1 a, struct Node1 b){
        return a.tt > b.tt;
    }
};

int TransformMinute(const Time &t){
    return ((t.day * 24 + t.hour) * 60 + t.minute);
}//TransformMinute

void ALGraph::Dijkstra_Time(int v0, int *path, Node1 *dist){
    priority_queue<Node1>q1;
    //path[]记录下标对应节点的父亲节点。
    int visited[MaxCityNum];//该下标对应的顶点是否已经算出最短距离。是则为1
    //初始化
    int i;
    for(i = 0; i < CityNum; i++){
        dist[i].id = i;
        dist[i].tt = INF;
        dist[i].et = {0, 0, 0};
        path[i] = -1;       //每个顶点都无父亲节点
        visited[i] = 0;     //都未找到最短路
    }
    dist[v0].tt = 0;
    q1.push(dist[v0]);
    while(!q1.empty()){
        Node1 cd = q1.top();
        q1.pop();
        int u = cd.id;

        if(visited[u])
            continue;
        visited[u] = 1;

        LineNode *p = CityList[u].FirstLine;
        while(p){
            int tempv = SearchCityNum(p->EndCityName);
            int tempt = TransformMinute(p->Info->SpendTime);//时间为权值
            Time st = p->Info->StartTime;//本条线的开始时间
            if(u != v0){//起点到任何点都没有换乘时间这一说法
                int change = TransformMinute(st - dist[u].et);//换乘时间
                tempt += change;
            }
            if(!visited[tempv] && dist[tempv].tt > dist[u].tt + tempt){
                dist[tempv].tt = dist[u].tt + tempt;
                dist[tempv].et = p->Info->EndTime;
                path[tempv] = u;
                q1.push(dist[tempv]);
            }
            p = p->NextLine;
        }//while(p)
    }//while(!q1.empty())
}//ALGraph::Dijkstra_Time

void ALGraph::SearchShortestPath(const string type){
    string StartCity, EndCity;
    int StartNum, EndNum;
    cout<<"Please enter start city:";
    cin>>StartCity;
    StartNum = SearchCityNum(StartCity);
    while(StartNum == -1){
        cout<<"Can not find out the city!"<<endl;
        ShowCity();
        cout<<"Please enter again:";
        cin>>StartCity;
        StartNum = SearchCityNum(StartCity);
    }

    cout<<"Please enter end city:";
    cin>>EndCity;
    EndNum = SearchCityNum(EndCity);
    while(EndNum == -1){
        cout<<"Can not find out the city!"<<endl;
        ShowCity();
        cout<<"Please enter again:";
        cin>>EndCity;
        EndNum = SearchCityNum(EndCity);
    }

    int path[MaxCityNum];
    int t_m = 0;//时间，分钟
    float m_y = 0;//费用，元

    if(type == "Money"){
        Node dist[MaxCityNum];
        Dijkstra_Money(StartNum, path, dist);
        m_y = dist[EndNum].money;
    }
    else{
        Node1 dist[MaxCityNum];
        Dijkstra_Time(StartNum, path, dist);
        t_m = dist[EndNum].tt;
    }

    if(path[EndNum] == -1){
        cout<<"Sorry, NULL!"<<endl;
        return;
    }
    else{
        stack<int>s;//p424
        int step = EndNum;
        while(step != StartNum){
            s.push(step);
            step = path[step];
        }
        int father = step, child;

        if(type == "Money"){//输出最省钱的
            cout<<"最省钱路径："<<endl;
            int tt = 0;//总共需要的时间
            Time et = {0, 0, 0};
            while(!s.empty()){
                child = s.top();
                s.pop();
                LineNode *p = CityList[father].FirstLine;
                float mm = INF;//当前记录到的最少金钱，不是总金钱
                int i = 0, count;//指针移动的次数，方便定位
                while(p){
                    if(p->EndCityName == CityList[child].CityName && mm >= p->Info->SpendMoney){
                        mm = p->Info->SpendMoney;
                        count = i;
                    }
                    p = p->NextLine;
                    i++;
                }//while(p)
                p = CityList[father].FirstLine;
                i = 0;
                while(i++ != count)
                    p = p->NextLine;
                tt += TransformMinute(p->Info->SpendTime);
                if(father != StartNum){
                    tt = tt + TransformMinute(p->Info->StartTime - et);
                    cout << "需要中转等待 " << TransformMinute(p->Info->StartTime - et) << "分钟！"  << endl;
                }
                cout<<setw(8)<<CityList[father].CityName<<" "<<setw(8)<<p->EndCityName<<" "<<setw(6)<<p->Info->LineName<<" ";
                cout.fill('0');
                cout<<p->Info->StartTime<<" "<<p->Info->EndTime<<" "<<p->Info->SpendTime<<" "
                    <<setiosflags(ios_base::showpoint)<<p->Info->SpendMoney<<endl;//不用取消，因为只有money是浮点数，该标志只对浮点数有效
                cout.fill(' ');

                et = p->Info->EndTime;
                father = child;
            }//while(!s.empty())
            cout<<"一共花费"<<m_y<<"元和"<<tt<<"分钟！"<<endl;
        }//输出最省钱的
        else{//输出最省时的
            cout<<"最省时间路径："<<endl;
            float mm = 0;//总共需要的钱
            Time et = {0, 0, 0};
            while(!s.empty()){
                child = s.top();
                s.pop();
                LineNode *p = CityList[father].FirstLine;
                int tt = INF, ot = 0;//tt当前记录到的最少时间，不是总时间；ot是该条线的真正时间（算上换乘）
                int i = 0, count;//指针移动的次数，方便定位
                while(p){
                    if(p->EndCityName == CityList[child].CityName){
                        if(!s.empty() && child != EndNum)
                            ot = TransformMinute(p->Info->SpendTime) + TransformMinute(p->Info->StartTime - et);
                        else
                            ot = TransformMinute(p->Info->SpendTime);
                        if(tt >= ot){
                            tt = ot;
                            count = i;
                        }
                    }
                    p = p->NextLine;
                    i++;
                }//while(p)
                p = CityList[father].FirstLine;
                i = 0;
                while(i++ != count)
                    p = p->NextLine;
                mm += p->Info->SpendMoney;
                if(father != StartNum)
                    cout << "需要中转等待 " << TransformMinute(p->Info->StartTime - et) << "分钟！" <<endl;
                cout<<setw(8)<<CityList[father].CityName<<" "<<setw(8)<<p->EndCityName<<" "<<setw(6)<<p->Info->LineName<<" ";
                cout.fill('0');
                cout<<p->Info->StartTime<<" "<<p->Info->EndTime<<" "<<p->Info->SpendTime<<" "
                    <<setiosflags(ios_base::showpoint)<<p->Info->SpendMoney<<endl;//不用取消，因为只有money是浮点数，该标志只对浮点数有效
                cout.fill(' ');

                et = p->Info->EndTime;
                father = child;
            }//while(!s.empty())
            cout<<"一共花费"<<mm<<"元和"<<t_m<<"分钟！"<<endl;
        }//输出最省时的
    }//有路径
}//SearchShortestPath
