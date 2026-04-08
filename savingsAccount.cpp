#include <iostream>
#include "savingsAccount.hpp"

using namespace std;

SavingsAccount::SavingsAccount(Client* client, int id, double c) : Account(client, id) {
    this->credit = c;
    //cout << "SavingsAccount constructor called" << endl;
}

SavingsAccount::SavingsAccount(Client* client, int id, double c, double interest) : Account(client, id) {
    this->credit = c;
    cout << "SavingsAccount overload constructor called" << endl;
}

SavingsAccount::~SavingsAccount() {
    //cout << "SavingsAccount destructor called" << endl;
}

bool SavingsAccount::CanWithdraw(double m) {
    return (this->GetBalance() + this->credit >= m);
}

bool SavingsAccount::Withdraw(double m) {
    if (this->CanWithdraw(m)) {
        this->balance -= m;
        return true;
    }
    return false; 
}