#include <iostream>
#include "bank.hpp"

using namespace std;

Bank::Bank(string n) {
    this->name = n;
    this->accounts = new Account*[100];
    this->accountsCount = 0;
    this->clients = new Client*[100];
    this->clientsCount = 0;
}

Bank::~Bank() {
    for (int i = 0; i < clientsCount; i++) {
        delete clients[i];
    }
    delete[] clients;

    for (int i = 0; i < accountsCount; i++) {
        delete accounts[i];
    }
    delete[] accounts;

    clients = nullptr;
    accounts = nullptr;
}

string Bank::GetName() {
    return this->name;
}

int Bank::GetAccountsCount() {
    return this->accountsCount;
}

int Bank::GetClientsCount() {
    return this->clientsCount;
}

Client* Bank::CreateClient(string name) {
    Client* newClient = new Client(this->clientsCount, name);
    this->clients[this->clientsCount++] = newClient;
    return newClient;
}

Account* Bank::CreateAccount(Client* client) {
    Account* newAcc = new Account(client, accountsCount);
    this->accounts[this->accountsCount++] = newAcc;
    return newAcc;
}

Client* Bank::GetClient(int id) {
    if (this->clientsCount <= id) return nullptr;
    return this->clients[id];
}