#include<iostream>
using namespace std;

int judge(char chess[][20],int hang, int num){
    int i,j,loop=1;
    char newchess[20];

    for(i=0,j=0;i<2*num+1;i++,j++)      //复制格局，因为直接修改形参会改变原始格局
        newchess[i]=chess[hang][j];

    for(i=0;i<2*num+1;i++)      //去E后判断是否为目标格局更容易
        if(newchess[i]=='E'){
            for(j=i;j<2*num;j++)
                newchess[j]=newchess[j+1];
            break;
        }

    for(i=0;i<num;i++)
        if(newchess[i]!='W')
            loop=0;

    if(loop)
        cout<<"This is a target pattern."<<endl;

    return loop;
}

void movement(char chess[][20],int hang,int num,int gap){
    int i,j,Eaddr;
    char t;
    char newchess[20];

    for(i=0;i<2*num+1;i++)      //寻找E的位置
        if(chess[hang][i]=='E')
            break;
    Eaddr=i;

    for(i=0,j=0;i<2*num+1;i++,j++)      //复制格局，因为直接修改形参会改变原始格局
        newchess[i]=chess[hang][j];
    if(Eaddr+gap<=2*num){
        t=newchess[Eaddr];
        newchess[Eaddr]=newchess[Eaddr+gap];
        newchess[Eaddr+gap]=t;
        for(i=0;i<2*num+1;i++)
            cout<<newchess[i];
        cout<<endl;
    }

    for(i=0,j=0;i<2*num+1;i++,j++)      //复制格局，因为直接修改形参会改变原始格局
        newchess[i]=chess[hang][j];
    if(Eaddr-gap>=0){
        t=newchess[Eaddr];
        newchess[Eaddr]=newchess[Eaddr-gap];
        newchess[Eaddr-gap]=t;
        for(i=0;i<2*num+1;i++)
            cout<<newchess[i];
        cout<<endl;
    }
}


int main(){
    int times,i,j,nums[20],loop;
    char chesses[20][20];

    cout<<"Please enter the times you want computer operate:"<<endl;
    cin>>times;
    cout<<"Then ,Please enter the number of chess and what are they:"<<endl;
    for(i=0;i<times;i++){
        cin>>nums[i];
        for(j=0;j<2*nums[i]+1;j++)
            cin>>chesses[i][j];
    }

    for(i=0;i<times;i++){
        cout<<endl<<"Result "<<i+1<<endl;
        loop=judge(chesses,i,nums[i]);
        if(!loop)
            for(j=1;j<=3;j++)
                movement(chesses,i,nums[i],j);
    }

    return 0;
}
