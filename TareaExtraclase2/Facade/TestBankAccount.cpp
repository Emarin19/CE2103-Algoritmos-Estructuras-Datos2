#include <iostream>
#include "Headers/BankAccountFacade.h"

int main() {
    BankAccountFacade accessingBank(12345678, 1234);
    accessingBank.withdrawCash(50.00);
    accessingBank.withdrawCash(900.00);
    accessingBank.depositCash(200.00);
    return 0;
}
