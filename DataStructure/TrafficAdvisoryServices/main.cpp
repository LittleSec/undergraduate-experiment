#include<iostream>
#include<string>
#include<windows.h>
#include"ALGraph.h"

using namespace std;

//（第一维）下标为0代表飞机，下标为1代表火车
ALGraph ALG[2] = {ALGraph(10), ALGraph(20)};
char tool[2][7] = {"Flight", "Train"};
char cityfile[2][10] = {"FCity.txt", "TCity.txt"};
char linefile[2][11] = {"Flight.txt", "Train.txt"};
string Account = "Administrator";//管理员账号名
string Password = "Administrator";//管理员初始秘密

//登录函数
int Login(){
    string account, password;
    cout<<"Please input account:";
    cin>>account;
    cout<<"Please input password:";
    cin>>password;
    if(account == Account && password == Password)
        return 1;
    else
        cout<<"Account or Password Error!"<<endl;
    return 0;
}//Login

//修改密码函数，默认已经登录才会调用
void ChangePassword(){
    string newPassword1 = "1", newPassword2 = "2";
    while(newPassword1 != newPassword2){
        cout<<"Please input new password:";
        cin>>newPassword1;
        cout<<"Please input again:";
        cin>> newPassword2;
        if(newPassword1 != newPassword2)
            cout<<"Different! Please input again!"<<endl;
    }
    cout<<"Change Password OK!"<<endl;
}//ChangePassword

//管理员对图的操作选择界面
void AdminOpraALG(int editor){
    int func = 1;
    string name;
    while(func){
        cout<<"            Now is operations about "<<tool[editor-2]<<endl;
        cout<<"Please choose the function!"<<endl;
        cout<<"    1.Add "<<tool[editor-2]<<" city from the file."<<endl;
        cout<<"    2.Add "<<tool[editor-2]<<" city which you enter."<<endl;
        cout<<"    3.Delete "<<tool[editor-2]<<" city."<<endl;
        cout<<"    4.Add "<<tool[editor-2]<<" from the file."<<endl;
        cout<<"    5.Add "<<tool[editor-2]<<" which you enter."<<endl;
        cout<<"    6.Delete "<<tool[editor-2]<<" ."<<endl;
        cout<<"    7.Show all the cities!"<<endl;
        cout<<"    8.Show all the lines!"<<endl;
        cout<<"    9.Update File!"<<endl;
        cout<<"Enter the num:(0 for AdminOpr)";
        cin>>func;
        cout<<endl;
        if(!func)
            break;
        switch(func){
            case 1:cout<<"1.Add "<<tool[editor-2]<<" city from the file."<<endl;
                ALG[editor-2].AddCityFromFile(cityfile[editor-2]);
                break;
            case 2:cout<<"2.Add "<<tool[editor-2]<<" city which you enter."<<endl;
                cout<<"Please enter the city you want to add:";
                cin>>name;
                ALG[editor-2].AddCity(name);
                break;
            case 3:cout<<"3.Delete "<<tool[editor-2]<<" city."<<endl;
                cout<<"Please enter the city you want to delete:";
                cin>>name;
                ALG[editor-2].DelCity(name);
                break;
            case 4:cout<<"4.Add "<<tool[editor-2]<<" from the file."<<endl;
                ALG[editor-2].AddLineFromFile(linefile[editor-2]);
                break;
            case 5:cout<<"5.Add "<<tool[editor-2]<<" which you enter."<<endl;
                ALG[editor-2].AddLine();
                break;
            case 6:cout<<"6.Delete "<<tool[editor-2]<<" ."<<endl;
                ALG[editor-2].DelLine();
                break;
            case 7:cout<<"7.Show all the cities!"<<endl;
                ALG[editor-2].ShowCity();
                break;
            case 8:cout<<"8.Show all the lines!"<<endl;
                ALG[editor-2].ShowAllLine();
                break;
            case 9:cout<<"9.Update File!"<<endl;
                ALG[editor-2].UpdateFile(cityfile[editor-2], "City");
                ALG[editor-2].UpdateFile(linefile[editor-2], "Line");
                break;
            default:
                break;
        }//switch
        cout<<endl;
    }//while(func)
}//AdminOpraALG

//管理员的选择界面
void AdminOpra(){
    cout<<"           Now is the Administrator!"<<endl<<endl;
    while(!Login())
        cout<<endl<<"Try again:"<<endl;
    cout<<endl<<"Login OK!"<<endl<<endl;
    int editor = 1;
    while(editor){
        cout<<"Please choose your operation:"<<endl;
        cout<<"    1.Change Password"<<endl<<"    2.Operation about Flight"<<endl<<"    3.Operation about Train"<<endl;
        cout<<"Enter the num:(0 for identity):";
        cin>>editor;
        cout<<endl;
        if(!editor)
            break;
        switch(editor){
            case 1:
                ChangePassword();
                break;
            case 2:
            case 3:
                AdminOpraALG(editor);
                break;
            default:
                break;
        }//switch(editor)
        cout<<endl;
    }//while(editor)
    cout<<endl<<"Logout!"<<endl<<endl;
}//AdminOpra

//用户的选择界面
void UserOpra(){
    cout<<"           Now is the User!"<<endl<<endl;
    int t = 1, func = 1;
    while(t){
        cout<<"Please choose your tool!"<<endl;
        cout<<"    1.Flight"<<endl<<"    2.Train"<<endl;
        cout<<"Enter the num:(0 for identity):";
        cin>>t;
        if(!t)
            break;
        cout<<endl;
        while(func){
            cout<<"           Now is operations about "<<tool[t-1]<<endl;
            cout<<"Please choose the function!"<<endl;
            cout<<"    1.Search cheapest way!"<<endl;
            cout<<"    2.Search fastest way!"<<endl;
            cout<<"    3.Show all the cities!"<<endl;
            cout<<"    4.Show all the lines!"<<endl;
            cout<<"Enter the num:(0 for tool)";
            cin>>func;
            if(!func)
                break;
            cout<<endl;
            switch(func){
                case 1:cout<<"1.Search cheapest way!"<<endl;
                    ALG[t-1].SearchShortestPath("Money");
                    break;
                case 2:cout<<"2.Search fastest way!"<<endl;
                    ALG[t-1].SearchShortestPath("Time");
                    break;
                case 3:cout<<"3.Show all the cities!"<<endl;
                    ALG[t-1].ShowCity();
                    break;
                case 4:cout<<"4.Show all the lines!"<<endl;
                    ALG[t-1].ShowAllLine();
                    break;
                default:
                    break;
            }//switch
            cout<<endl;
        }//while(func)
        cout<<endl;
    }//while(tool)
}//UserOpra

int main(){
    int identity = 1;
    while(identity){
        cout<<"==========Welcome to the system!=========="<<endl;
        cout<<"Please choose your identity!"<<endl;
        cout<<"    1.Administrator"<<endl<<"    2.User"<<endl;
        cout<<"Enter the num:(0 for exit):";
        cin>>identity;
        if(!identity)
            break;
        system("cls");
        switch(identity){
            case 1:
                AdminOpra();
                break;
            case 2:
                UserOpra();
                break;
            default:
                break;
        }//switch(identity)
        system("cls");
    }//while(identity)
    cout<<endl<<"Thank you! Goodbye!"<<endl;
    return 0;
}
