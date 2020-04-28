//
// Created by emanuel on 27/4/20.
//

#ifndef FACADE_ACCOUNTNUMBERCHECK_H
#define FACADE_ACCOUNTNUMBERCHECK_H

class AccountNumberCheck{
private:
    int accountNumber = 12345678;
public:
    int getAccountNumber();
    bool accountActive(int accNumberToCheck);
};

#endif //FACADE_ACCOUNTNUMBERCHECK_H
