#include<iostream>
#include"CheckingAccount.h"
using namespace std;

/*
类 CheckingAccount需要重新定义成员函数 credit和 debit，
当每笔交易完成时，从 balance中减去每笔交易的费用。
重新定义这些函数时应分别使用基类 Account 的相关函数来执行账户余额的更新。
CheckingAccount的 debit函数只有当钱被成功提取时（即提取金额不超过账户余额时）才应收取交易费
*/

/*
定义 Account 的 debit 函数使它返回一个 bool 类型值，表示钱是否被成功提取。
然后利用该值决定是否需要扣除交易费。
如果取款或存款后，账户的余额小于每笔交易的费用，则废弃这次交易，使账户余额恢复到取款或存款之前的值，
并打印“Transaction fee exceeded account balance while debiting”或
“Transaction fee exceeded account balance while crediting” 。
*/

CheckingAccount::CheckingAccount(double bal, double cha):acc(bal),charge(cha){
    initAccount(bal);
}

void CheckingAccount::credit(double ex_money){
    acc.credit(ex_money);

    if(!acc.debit(charge)){
        acc.debit(ex_money);
        cout<<"Transaction fee exceeded account balance while crediting!"<<endl;
    }
    initAccount(acc.getBalance());
}

bool CheckingAccount::debit(double withdraw_mon){
    if(acc.debit(withdraw_mon))
        if(acc.debit(charge)){
            initAccount(acc.getBalance());
            return true;
        }
        else{
            acc.credit(withdraw_mon);
            initAccount(acc.getBalance());
            cout<<"Transaction fee exceeded account balance while debiting"<<endl;
            return false;
        }
    else{
        initAccount(acc.getBalance());
        return false;
    }
}
