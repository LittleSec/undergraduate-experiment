#include<iostream>
#include"Account.h"
using namespace std;

Account::Account(double bal):balance(bal){}

void Account::initAccount(double initAcc){
/*为了派生类中初始化balance时是属于“自己”的，自己的函数通过调用基类函数修改balance值的时，修改的balance也是“自己”的
而不是又默认调用带有默认参数的基类构造函数，使用此时的balance（为0）*/
    balance = initAcc;
}

void Account::credit(double ex_money){//向当前余额加钱
    balance = getBalance() + ex_money;

}

bool Account::debit(double withdraw_mon){
//负责从账户中取钱，并且保证账户不会被透支。如果提取金额大于账户金额，函数将保持 balance 不变，并打印信息“”
    if(withdraw_mon > getBalance()){
        cout<<"Debit amount exceeded account balance!"<<endl;
        return false;
    }
    else{
        balance -= withdraw_mon;
        return true;
    }

}

double Account::getBalance(){//返回当前 balance的值
    return balance;
}

