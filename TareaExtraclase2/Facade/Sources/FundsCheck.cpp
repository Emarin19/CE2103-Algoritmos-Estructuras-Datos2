//
// Created by emanuel on 27/4/20.
//

#include "../Headers/FundsCheck.h"
#include <iostream>

double FundsCheck::getCashInAccount() {
    return cashInAccount;
}

void FundsCheck::decreaseCashInAccount(double cashWithdrawn) {
    cashInAccount -= cashWithdrawn;
}

void FundsCheck::increaseCashInAccount(double cashDeposited) {
    cashInAccount += cashDeposited;
}

void FundsCheck::makeDeposit(double cashToDeposit) {
    increaseCashInAccount(cashToDeposit);
    std::cout << "Deposit complete: Current Balance is " << getCashInAccount() << std::endl;
}

bool FundsCheck::haveEnoughMoney(double cashToWithdrawal) {
    if(cashToWithdrawal > getCashInAccount()){
        std::cout << "Error: You don't have enough money" << std::endl;
        std::cout << "Current Balance: " << getCashInAccount() << std::endl;
        return false;
    }
    else{
        decreaseCashInAccount(cashToWithdrawal);
        std::cout << "Withdrawal complete: Current balance is " << getCashInAccount() << std::endl;
        return true;
    }
}
