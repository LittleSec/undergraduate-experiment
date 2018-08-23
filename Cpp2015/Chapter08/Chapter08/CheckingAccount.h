#include"Account.h"
#ifndef CHECKINGACCOUNT_H_INCLUDED
#define CHECKINGACCOUNT_H_INCLUDED

class CheckingAccount:public Account{
/*构造函数应接受初始余额值和交易费用值
需要重新定义成员函数 credit和 debit，当每笔交易完成时，从 balance中减去每笔交易的费用
重新定义这些函数时应分别使用基类 Account 的相关函数来执行账户余额的更新
debit函数只有当钱被成功提取时（即提取金额不超过账户余额时）才应收取交易费
*/
public:
    CheckingAccount(double bal, double cha);
    virtual void credit(double ex_money);
    virtual bool debit(double withdraw_mon);
private:
    Account acc;
    double charge;//表示每笔交易的费用
};

#endif // CHECKINGACCOUNT_H_INCLUDED
