#include<iostream>
#include<iomanip>
using namespace std;

struct Rule
{
    double Mi;
    double Ri;
};

void inputRules(struct Rule rules[] , int n){
    int j;
    for( j = 1; j <= n; j++ ){
        cout<<"Please input No. "<<j<<" rule:";
        cin>>rules[j].Mi>>rules[j].Ri;
    }
}

double computeTax(struct Rule rules[], int n, double income){
    double sumtax;
    int i,steps = 0;

    for(i = 0; i < n; i++)
        if(income >= rules[i].Mi && income < rules[i+1].Mi)
            break;
    steps = i;
    sumtax = (income - rules[steps].Mi) * rules[steps].Ri /100;
    for(steps-=1; steps > 0; steps--){
        sumtax = sumtax + (rules[steps+1].Mi - rules[steps].Mi) * rules[steps].Ri /100;
    }

    return sumtax;
}

void printRules(struct Rule rules[], int n){
    int i;
    cout<<"The rules as follow:"<<endl;
    cout<<"Tax Line     Tax rate"<<endl;
    for(i = 1; i <= n; i++)
        cout<<"  "<<rules[i].Mi<<"\t\t"<<rules[i].Ri<<endl;
}

int main(){
    int i;
    double income=1.0;
    struct Rule rules[10] = { {0,0} };

    cout<<"Please enter a number of rules :";
    cin>>i;

    inputRules(rules, i);
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    printRules(rules, i);

    while(income != -1){
        cout<<"Please enter your income:";
        cin>>income;
        if(income == -1)
            break;
        cout<<"Your income is "<<income<<", and you should pay tax:"<<fixed<<setprecision(2)<<computeTax(rules, i, income)<<endl<<endl;
    }

    return 0;
}
