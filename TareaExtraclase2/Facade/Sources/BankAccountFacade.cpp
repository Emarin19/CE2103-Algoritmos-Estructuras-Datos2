//
// Created by emanuel on 27/4/20.
//

#include "../Headers/BankAccountFacade.h"

BankAccountFacade::BankAccountFacade(int newAcctNum, int newSecCode) {
    accountNumber = newAcctNum;
    securityCode = newSecCode;

    welcomeToBank = new WelcomeToBank();
    acctChecker = new AccountNumberCheck();
    codeChecker = new SecurityCodeCheck();
    fundChecker = new FundsCheck();
}

int BankAccountFacade::getAccountNumber() {
    return accountNumber;
}

int BankAccountFacade::getSecurityCode() {
    return securityCode;
}

void BankAccountFacade::withdrawCash(double cashToGet) {
    if(acctChecker->accountActive(getAccountNumber()) &&
    codeChecker->isCodeCorrect(getSecurityCode()) &&
    fundChecker->haveEnoughMoney(cashToGet)){

        std::cout << "Transaction Complete\n" << std::endl;
    }
    else{

        std::cout << "Transaction Failed\n" << std::endl;
    }
}

void BankAccountFacade::depositCash(double cashToDeposit) {
    if(acctChecker->accountActive(getAccountNumber()) &&
       codeChecker->isCodeCorrect(getSecurityCode())){

        fundChecker->makeDeposit(cashToDeposit);
        std::cout << "Transaction Complete\n" << std::endl;

    }
    else{

        std::cout << "Transaction Failed\n" << std::endl;
    }
}
