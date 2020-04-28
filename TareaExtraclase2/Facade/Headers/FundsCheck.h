//
// Created by emanuel on 27/4/20.
//

#ifndef FACADE_FUNDSCHECK_H
#define FACADE_FUNDSCHECK_H

class FundsCheck{
private:
    double cashInAccount = 1000.00;
public:
    double getCashInAccount();
    void decreaseCashInAccount(double cashWithdrawn);
    void increaseCashInAccount(double cashDeposited);
    void makeDeposit(double cashToDeposit);
    bool haveEnoughMoney(double cashToWithdrawal);
};

#endif //FACADE_FUNDSCHECK_H
