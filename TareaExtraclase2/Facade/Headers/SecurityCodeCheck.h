//
// Created by emanuel on 27/4/20.
//

#ifndef FACADE_SECURITYCODECHECK_H
#define FACADE_SECURITYCODECHECK_H

class SecurityCodeCheck{
private:
    int securityCode = 1234;
public:
    int getSecurityCode();
    bool isCodeCorrect(int secCodeToCheck);
};

#endif //FACADE_SECURITYCODECHECK_H
