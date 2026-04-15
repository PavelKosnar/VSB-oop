#pragma once

#include <iostream>

class AbstractAccount {
    public:
        AbstractAccount();
        virtual ~AbstractAccount();

        virtual bool CanWithdraw(double a) = 0;
};