#include<iostream>
using namespace std;

const int Days=15;
const int LowestTemp=20;   //能够记录的最低温度的绝对值。

void inputTemps(int temp[], int n){
    int i;

    cout<<"Please input the temperatures:"<<endl;
    for(i=0;i<n;i++)
        cin>>temp[i];
}

void displayTemps(int temp[], int n){
    int i,num,space;

    cout<<endl<<"Date    TemperaturesShape"<<endl;
    for(i=0;i<n;i++){
        cout<<" "<<i+1<<"\t";
        if(temp[i]>=0){
            for(space=0;space<LowestTemp;space++)
                cout<<" ";
            cout<<"|";
            for(num=0;num<temp[i];num++)
                cout<<"*";
            cout<<endl;
        }
        else{
            for(space=0;space<LowestTemp+temp[i];space++)
                cout<<" ";
            for(num=0;num<0-temp[i];num++)
                cout<<"*";
            cout<<"|"<<endl;
        }
    }
}

void displayPeaks(int temp[], int n){
    int i,loop=0;     //loop用来记录是否有峰值

    cout<<endl<<"The TemperaturePeaks as follow:"<<endl;
    for(i=1;i<n-1;i++){     //第一天和最后第一天肯定不是峰值。
        if( (temp[i] > temp[i-1]) && (temp[i] > temp[i+1]) ){
            cout<<"Max at day "<<i+1<<" is "<<temp[i]<<endl;
            i++;    //算法精简，因为今天是峰值，明天就一定不是峰值。
            loop++;
        }
    }
    if(!loop)
        cout<<"Sorry,There is no peaks!"<<endl;
}

void displayFlat(int temp[], int n){
    int i,length_f=1,length_l=1;    //f是前者，l是后者，哪个长就把长度记录在后者。

    for(i=0;i<n-1;i++){
        if(temp[i+1]==temp[i])
            length_f++;
        if(temp[i+1]!=temp[i]||i==n-2){
            /*不相等的话就要比较当前长度和之前记录的长度。而且测试样例如果是前面3个同一个数，后面的也是同一个数的话，
            那么长度也就是3，这显然是不对的，所以要到了最后一次循环的时候也要做一次判断！*/
            if(length_f>length_l)
                length_l=length_f;  //由于当时设定length_l记录最长，所以如果当前长的话就要让length_l等于当前的长度。
            length_f=1;             //也正如上述原因，所以如果遇到不相等的温度后要把前者重新置1。
        }
    }

    cout<<endl<<"The length of longest flat is "<<length_l<<endl;
}

void displayMostTime(int temp[], int n){
    int i,j,times_f=1,times_l=1,sametimes;    //同理记录出现次数。
    int nowtemp;                    //记录当前温度。

    for(i=0;i<n;i++){
        if(temp[i]==nowtemp)        //减少循环次数。
            continue;               //别错用break，第一次修改前就用break就错了。
        for(j=i+1;j<n;j++)
        //没必要从头开始对比了，因为会重复循环次数。即使前面有和他相同的，但之前循环所计算的次数已经计算比较了。
            if(temp[j]==temp[i])
                times_f++;
        if(times_f>times_l){		//如果当前次数大于已记录的最大值，则把当前记录为最大值，并记录当前的温度。
            times_l=times_f;
            nowtemp=temp[i];
        }
		times_f=1;
    }


    cout<<endl<<"The temperature appear most times as follow:"<<endl;
    cout<<nowtemp;

	//用于寻找出现次数最多且相同的温度。
	sametimes=times_l;
	for(i=0;i<n;i++){
		if(temp[i]==nowtemp)
            continue;
        for(j=i+1;j<n;j++)
            if(temp[j]==temp[i])
                times_f++;
		if(times_f==sametimes)
			cout<<" , "<<temp[i];
		times_f=1;
	}

	cout<<" appear "<<sametimes<<" times."<<endl;
}

int main(){
    int temps[Days];

    inputTemps(temps, Days);
    displayTemps(temps, Days);
    displayPeaks(temps, Days);
    displayFlat(temps, Days);
    displayMostTime(temps, Days);

    return 0;
}
