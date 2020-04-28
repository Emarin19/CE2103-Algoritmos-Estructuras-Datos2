//
// Created by emanuel on 27/4/20.
//

#ifndef FACADE_BANKACCOUNTFACADE_H
#define FACADE_BANKACCOUNTFACADE_H
#include <iostream>
#include "WelcomeToBank.h"
#include "AccountNumberCheck.h"
#include "SecurityCodeCheck.h"
#include "FundsCheck.h"

class BankAccountFacade{
private:
    int accountNumber;
    int securityCode;
    WelcomeToBank *welcomeToBank;
    AccountNumberCheck *acctChecker;
    SecurityCodeCheck *codeChecker;
    FundsCheck *fundChecker;

public:
    BankAccountFacade(int newAcctNum, int newSecCode);
    int getAccountNumber();
    int getSecurityCode();
    void withdrawCash(double cashToGet);
    void depositCash(double cashToDeposit);
};

#endif //FACADE_BANKACCOUNTFACADE_H
