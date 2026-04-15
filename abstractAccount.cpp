#include <iostream>
#include "abstractAccount.hpp"

using namespace std;

AbstractAccount::AbstractAccount() {
    cout << "AbstractAccount Constructor" << endl;
}

AbstractAccount::~AbstractAccount() {
    cout << "AbstractAccount Destructor" << endl;
}