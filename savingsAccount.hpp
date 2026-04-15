#pragma once

#include "account.hpp"

class SavingsAccount : public Account {
    private:
        double credit;
    public:
        SavingsAccount(Client* client, int id, double c);
        SavingsAccount(Client* client, int id, double c, double interest);
        ~SavingsAccount();
        bool CanWithdraw(double m) override;
        bool Withdraw(double m);
};