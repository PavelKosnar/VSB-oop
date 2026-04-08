#include <iostream>
#include "savingsAccount.hpp"

using namespace std;

SavingsAccount::SavingsAccount(Client* c, int id) : Account(c, id) {
    cout << "→ SavingsAccount constructor called (base Account constructor finished)" << endl;
}

SavingsAccount::~SavingsAccount() {
    cout << "→ SavingsAccount destructor called" << endl;
}

bool SavingsAccount::CanWithdraw(int m) {
    return Account::CanWithdraw(m); 
}