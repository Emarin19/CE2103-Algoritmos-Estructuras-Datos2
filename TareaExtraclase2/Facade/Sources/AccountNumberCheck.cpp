//
// Created by emanuel on 27/4/20.
//

#include "../Headers/AccountNumberCheck.h"

int AccountNumberCheck::getAccountNumber() {
    return accountNumber;
}

bool AccountNumberCheck::accountActive(int accNumberToCheck) {
    return accNumberToCheck == getAccountNumber();
}
