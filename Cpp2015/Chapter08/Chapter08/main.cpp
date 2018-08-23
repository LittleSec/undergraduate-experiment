#include<iostream>
#include<iomanip>
#include"Account.h"
#include"CheckingAccount.h"
#include"SavingAccount.h"

using namespace std;



/*创建一个银行账户的继承层次，表示银行的所有客户账户。所有的客户都能
在他们的银行账户存钱，取钱，但是账户也可以分成更具体的类型。例如，一方
面存款账户 SavingsAccount 依靠存款生利，另一方面支票账户 CheckingAccount
对每笔交易（即存款或取款）收取费用。
*/
int main() {
    Account* accounts[3];
    accounts[0] = new SavingAccount(100.0, 3.0);   //余额100元，利息3%
    accounts[1] = new CheckingAccount(100.0, 5.0);  //余额100元，交易费5元
    accounts[2] = new CheckingAccount(50.0, 5.0);   //余额50元，交易费5元

    for (int i = 0; i < 3; i++) {
        cout << "第" << i + 1 << "次循环的结果：" << endl;
        accounts[i]->debit(200.0);
        accounts[i]->debit(40.0);
        accounts[i]->credit(50.0);
        accounts[i]->debit(49.0);
        accounts[i]->debit(43.0);
        accounts[i]->credit(1.0);

        SavingAccount *derivedPtr = dynamic_cast<SavingAccount *> (accounts[i]);
        if(derivedPtr != 0)
            derivedPtr->credit(derivedPtr->calculateInterest());
        cout << fixed << setprecision(2);
        cout << "账户的余额为：" << accounts[i]->getBalance() << endl;
    }
    return 0;
}



