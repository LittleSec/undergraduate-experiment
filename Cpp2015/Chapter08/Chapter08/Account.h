#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

class Account{
public:
    Account(double bal = 0);
    void initAccount(double initAcc);
    virtual void credit(double ex_money);//向当前余额加钱
    virtual bool debit(double withdraw_mon);
    double getBalance();//返回当前 balance的值

private:
    double balance;// 余额
};

#endif // ACCOUNT_H_INCLUDED
