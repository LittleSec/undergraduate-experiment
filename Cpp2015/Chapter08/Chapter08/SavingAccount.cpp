#include<iostream>
#include"SavingAccount.h"
using namespace std;

SavingAccount::SavingAccount(double bal,double rate){
    initAccount(bal);
    interestrate = rate / 100;
}

double SavingAccount::calculateInterest(){//返回代表账户的利息的一个double值,balance和interestrate的乘积
    return getBalance() * interestrate;
}

