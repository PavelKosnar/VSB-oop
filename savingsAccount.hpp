#pragma once

#include "account.hpp"

class SavingsAccount : public Account {
    public:
        SavingsAccount(Client* c, int id);
        ~SavingsAccount();
        bool CanWithdraw(int m) override;
};