#pragma once

#include <iostream>
#include "client.hpp"
#include "creditCard.hpp"

using namespace std;

class Account {
    private:
        Client* client;
        Client* partner;
        int id;
        CreditCard** creditCards;
        int creditCardsCount;
        double interestRate;
        static double defaultInterestRate;
        static int objectsCount;

    protected:
        double balance;

    public:
        Account(Client* c, int id);
        ~Account();
        int GetID();
        double GetBalance();
        void AddMoney(double m);
        bool SendMoney(Account* a, double m);
        Client* CreatePartner(Client* c);
        CreditCard* CreateCreditCard(int num, string n, Client* c, string e, int s, double b);
        static void SetDefaultInterestRate(double rate);
        double GetInterestRate() const;
        void ApplyInterest();
        static int GetObjectsCount();

        bool CanWithdraw(double m);
        bool Withdraw(double m);
};