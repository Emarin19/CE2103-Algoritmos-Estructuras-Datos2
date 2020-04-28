cmake_minimum_required(VERSION 3.16)
project(Facade)

set(CMAKE_CXX_STANDARD 14)

add_executable(Facade TestBankAccount.cpp Sources/WelcomeToBank.cpp Headers/WelcomeToBank.h Sources/AccountNumberCheck.cpp Headers/AccountNumberCheck.h Sources/SecurityCodeCheck.cpp Headers/SecurityCodeCheck.h Sources/FundsCheck.cpp Headers/FundsCheck.h Sources/BankAccountFacade.cpp Headers/BankAccountFacade.h)