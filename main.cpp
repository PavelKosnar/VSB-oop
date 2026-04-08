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
    cout << "Defaultni urokova sazba zmenena na 4.8 %" << endl << endl;

    cout << "DEDICNOST A ZASTUPITELNOST" << endl;
    SavingsAccount* savings = new SavingsAccount(clients[0], 999);
    Account* basePtr = savings;

    cout << "Vytvoren SavingsAccount, pristupujeme pres Account* ukazatel" << endl;
    basePtr->AddMoney(15000);
    cout << "Balance: " << basePtr->GetBalance() << " Kc" << endl;
    basePtr->ApplyInterest();
    cout << "Po ApplyInterest: " << basePtr->GetBalance() << " Kc" << endl;
    cout << "Aktualni uroková sazba: " << basePtr->GetInterestRate() << " %" << endl << endl;

    cout << "--- Prekryti metody Withdraw ---" << endl;
    
    int castka = 15500;
    cout << "Pokus o vyber " << castka << " Kc ze sporiciho uctu..." << endl;
    if (basePtr->Withdraw(castka)) {
        cout << "Vyber schvalen. Zustatek: " << basePtr->GetBalance() << " Kc" << endl;
    } else {
        cout << "Vyber ZAMITNUT: Pravidla sporiciho uctu nepovolila vyber" << endl;
    }

    castka = 5000;
    if (basePtr->Withdraw(castka)) {
        cout << "Vyber " << castka << " Kc schvalen. Novy zustatek: " << basePtr->GetBalance() << " Kc" << endl;
    }
    // ----------------------------------------------------

    cout << "\nPo vytvoreni SavingsAccount -> Account objekty: " 
         << Account::GetObjectsCount() << endl;

    delete savings;
    delete bank;

    return 0;
}