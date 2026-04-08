#pragma once

#include <iostream>

using namespace std;

class Client;

class CreditCard {
    private:
        int num;
        string name;
        Client* client;
        string endDate;
        int secCode;
        double balance;
    
    public:
        CreditCard(int num, string n, Client* c, string e, int s, double b);
        ~CreditCard();
        string GetName();
        double GetBalance();
};