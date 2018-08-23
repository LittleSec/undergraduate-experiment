#include"Account.h"
#ifndef SAVINGACCOUNT_H_INCLUDED
#define SAVINGACCOUNT_H_INCLUDED

class SavingAccount:public Account{
/*应继承成员函数 credit和 debit，不需要重新定义。
构造函数应接受初始余额值和初始利率值
*/
public:
    SavingAccount(double bal,double rate);

    double calculateInterest();//返回代表账户的利息的一个double值,balance和interestrate的乘积
private:
    double interestrate;//表示这个账户的比率（百分比）
};

#endif // SAVINGACCOUNT_H_INCLUDED
