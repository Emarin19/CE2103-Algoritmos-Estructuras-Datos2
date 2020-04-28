//
// Created by emanuel on 27/4/20.
//

#include "../Headers/SecurityCodeCheck.h"

int SecurityCodeCheck::getSecurityCode() {
    return securityCode;
}

bool SecurityCodeCheck::isCodeCorrect(int secCodeToCheck) {
    return secCodeToCheck == getSecurityCode();
}
