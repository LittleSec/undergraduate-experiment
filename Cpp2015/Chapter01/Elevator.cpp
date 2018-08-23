#include<iostream>
using namespace std;

void CalculateTime(int steps){
    int floor_f,floor_l;
    int i,cin_times=0;
    int times[100];

    while(steps){
        floor_f=0;
        times[cin_times]=0;

        for(i=0;i<steps;i++){
            cin>>floor_l;
            if(floor_l>floor_f)
                times[cin_times]=times[cin_times]+(floor_l-floor_f)*6;
            else
                times[cin_times]=times[cin_times]+(floor_f-floor_l)*4;
            floor_f=floor_l;
        }
        times[cin_times]=times[cin_times]+5*steps-5;
        cin_times++;

        cin>>steps;
    }

    cout<<"The time we need as follow:"<<endl;

    for(i=0;i<cin_times;i++)
        cout<<times[i]<<endl;
}

int main(){
    int steps;

    cout<<"Please enter the number how many steps and each step you need(0 replace End):"<<endl;
    cin>>steps;

    CalculateTime(steps);

    return 0;
}
