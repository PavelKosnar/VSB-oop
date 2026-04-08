#pragma once

#include <iostream>
#include "client.hpp"
#include "creditCard.hpp"

using namespace std;

class Account {
    protected:
        Client* client;
        Client* partner;
        int id;
        int balance;
        CreditCard** creditCards;
        int creditCardsCount;
        double interestRate;
        static double defaultInterestRate;
        static int objectsCount;

    public:
        Account(Client* c, int id);
        virtual ~Account();
        int GetID();
        int GetBalance();
        void AddMoney(int m);
        bool SendMoney(Account* a, int m);
        Client* CreatePartner(Client* c);
        CreditCard* CreateCreditCard(int num, string n, Client* c, string e, int s, int b);
        static void SetDefaultInterestRate(double rate);
        double GetInterestRate() const;
        void ApplyInterest();
        static int GetObjectsCount();

        virtual bool CanWithdraw(int m); 
        virtual bool Withdraw(int m);
};