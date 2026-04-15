#include <iostream>
#include "account.hpp"

using namespace std;

double Account::defaultInterestRate = 2.5;
int Account::objectsCount = 0;

Account::Account(Client* c, int id) {
    this->client = c;
    this->partner = nullptr;
    this->id = id;
    this->balance = 0;
    this->creditCards = new CreditCard*[5];
    this->creditCardsCount = 0;
    this->interestRate = defaultInterestRate;
    Account::objectsCount++;
}

Account::~Account() {
    if (creditCards != nullptr) {
        for (int i = 0; i < creditCardsCount; i++) {
            delete creditCards[i];
        }
        delete[] creditCards;
    }

    client = nullptr;
    partner = nullptr;
    creditCards = nullptr;
    creditCardsCount = 0;
    Account::objectsCount--;

    cout << "Account Destructor" << endl;
}

int Account::GetID() {
    return this->id;
}

double Account::GetBalance() {
    return this->balance;
}

void Account::AddMoney(double m) {
    this->balance += m;
}

bool Account::SendMoney(Account* a, double m) {
    if (a == nullptr || this->balance < m) return false;
    this->balance -= m;
    a->AddMoney(m);
    return true;
}

Client* Account::CreatePartner(Client* c) {
    this->partner = c;
    return c;
}

CreditCard* Account::CreateCreditCard(int num, string n, Client* c, string e, int s, double b) {
    CreditCard* newCard = new CreditCard(num, n, c, e, s, b);
    this->creditCards[this->creditCardsCount++] = newCard;
    return newCard;
}

void Account::SetDefaultInterestRate(double rate) {
    if (rate >= 0) defaultInterestRate = rate;
}

double Account::GetInterestRate() const {
    return this->interestRate;
}

void Account::ApplyInterest() {
    if (interestRate > 0) {
        int interest = this->balance * this->interestRate / 100.0;
        this->balance += interest;
    }
}

int Account::GetObjectsCount() {
    return Account::objectsCount;
}

void Account::SetBalance(double a) {
    this->balance = a;
}

bool Account::CanWithdraw(double m) {
    return this->balance >= m;
}

bool Account::Withdraw(double m) {
    if (this->CanWithdraw(m)) {
        this->balance -= m;
        return true;
    }
    return false;
}