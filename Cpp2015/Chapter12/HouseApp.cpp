#include<iostream>
#include"HouseApp.h"
using namespace std;

HouseApp::HouseApp(string name, double price, double num, double power):
    Commodity(name, price, num),power(power){}

double HouseApp::getFinalPrice(){
    return (Commodity::price - 200) * Commodity::num;
}

void HouseApp::showInfo() const{
    cout<<Commodity::name<<","<<Commodity::price<<","<<Commodity::num<<","<<power<<endl;
}

