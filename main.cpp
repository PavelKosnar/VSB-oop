#include <iostream>
#include <string>
#include "bank.hpp"
#include "client.hpp"
#include "account.hpp"
#include "address.hpp"
#include "creditCard.hpp"
#include "savingsAccount.hpp"

using namespace std;

int main() {
    Bank* bank = new Bank("International Bank");
    cout << "=== Banka: " << bank->GetName() << " ===" << endl << endl;

    const int NUM = 20;
    Client* clients[NUM];
    Account* accounts[NUM];

    for (int i = 0; i < NUM; i++) {
        string name = "Client " + to_string(i);
        clients[i] = bank->CreateClient(name);
        accounts[i] = bank->CreateAccount(clients[i]);

        cout << "Vytvoren klient #" << i << ": " 
             << clients[i]->GetName() 
             << " (code: " << clients[i]->GetCode() << ")" << endl;
    }

    cout << "\nPocet klientu v bance: " << bank->GetClientsCount() << endl;
    cout << "Pocet uctu v bance: " << bank->GetAccountsCount() << endl;
    cout << "Celkovy pocet Account objektu: " << Account::GetObjectsCount() << endl;  // úkol 1
    cout << "Celkovy pocet Client objektu: " << Client::GetObjectsCount() << endl << endl;

    Account::SetDefaultInterestRate(4.8);
    cout << "Defaultni urokova sazba zmenena na 4.8 % (plati pro vsechny nove ucty)" << endl << endl;

    cout << "=== DEMO DEDICNOSTI A ZASTUPITELNOSTI (LSP) ===" << endl;
    SavingsAccount* savings = new SavingsAccount(clients[0], 999);
    Account* basePtr = savings;

    cout << "Vytvoren SavingsAccount, pristupujeme pres Account* ukazatel" << endl;
    basePtr->AddMoney(15000);
    cout << "Balance (pres basePtr): " << basePtr->GetBalance() << " Kc" << endl;
    basePtr->ApplyInterest();
    cout << "Po ApplyInterest (4.8 %): " << basePtr->GetBalance() << " Kc" << endl;
    cout << "Aktualni uroková sazba: " << basePtr->GetInterestRate() << " %" << endl << endl;

    cout << "Po vytvoreni SavingsAccount -> Account objekty: " 
         << Account::GetObjectsCount() << endl;

    delete savings;
    delete bank;

    return 0;
}