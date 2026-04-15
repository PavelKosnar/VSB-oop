#include <iostream>
#include <string>
#include "bank.hpp"
#include "client.hpp"
#include "account.hpp"
#include "address.hpp"
#include "creditCard.hpp"
#include "savingsAccount.hpp"
#include "abstractAccount.hpp"

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
    cout << "Celkovy pocet Account objektu: " << Account::GetObjectsCount() << endl;
    cout << "Celkovy pocet Client objektu: " << Client::GetObjectsCount() << endl << endl;

    Account::SetDefaultInterestRate(4.8);
    cout << "Defaultni urokova sazba zmenena na 4.8 %" << endl << endl;

    cout << "DEDICNOST A ZASTUPITELNOST" << endl;
    SavingsAccount* savings = new SavingsAccount(clients[0], 999, 0);
    Account* savingsAcc = savings;

    cout << "Vytvoren SavingsAccount, pristupujeme pres Account* ukazatel" << endl;
    savingsAcc->AddMoney(15000);
    cout << "Balance: " << savingsAcc->GetBalance() << " Kc" << endl;
    savingsAcc->ApplyInterest();
    cout << "Po ApplyInterest: " << savingsAcc->GetBalance() << " Kc" << endl;
    cout << "Aktualni uroková sazba: " << savingsAcc->GetInterestRate() << " %" << endl << endl;

    cout << "--- Prekryti metody Withdraw ---" << endl;
    
    int castka = 15500;
    cout << "Pokus o vyber " << castka << " Kc ze sporiciho uctu..." << endl;
    if (savingsAcc->Withdraw(castka)) {
        cout << "Vyber schvalen. Zustatek: " << savingsAcc->GetBalance() << " Kc" << endl;
    } else {
        cout << "Vyber ZAMITNUT: Pravidla sporiciho uctu nepovolila vyber" << endl;
    }

    castka = 5000;
    if (savingsAcc->Withdraw(castka)) {
        cout << "Vyber " << castka << " Kc schvalen. Novy zustatek: " << savingsAcc->GetBalance() << " Kc" << endl;
    }

    cout << "\nOVERLOAD SAVINGS ACCOUNT" << endl;
    SavingsAccount* savingsOverload = new SavingsAccount(clients[1], 456, 1000, 5.8);
    Account* savingsAccOverload = savingsOverload;

    cout << "Overload savings account interest rate: " << savingsAccOverload->GetInterestRate() << "%" << endl;

    cout << "\nPo vytvoreni SavingsAccount -> Account objekty: " 
         << Account::GetObjectsCount() << endl;

    delete savings;
    delete bank;

    
    cout << "\n\nPREKRYTI" << endl;
    Client* o = new Client(555, "Smith");
    SavingsAccount *sa = new SavingsAccount(o, 556, 1000);
    cout << sa->CanWithdraw(1000) << endl;

    Account* a = sa;
    cout << a->CanWithdraw(1000) << endl;
    cout << sa->CanWithdraw(1000) << endl;

    a = nullptr;
    delete sa;

    cout << "\n\nABSTRAKCE" << endl;
    Client *abstract_o = new Client(123, "Sparrow");
    SavingsAccount *abstract_sa = new SavingsAccount(abstract_o, 124, 5000);
    AbstractAccount *aa = abstract_sa;

    delete aa;
    delete abstract_o;


    return 0;
}