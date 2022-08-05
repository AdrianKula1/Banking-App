#ifndef IOV2_BANK_H
#define IOV2_BANK_H


#include <string>
#include <vector>
#include "Account.h"
#include "Customer.h"
using std::string, std::vector;

class Bank {
    int availableAccountID;
    vector<Customer*> customers;
    vector<Account*> accounts;

public:
    Bank();
    ~Bank();

    void addCustomer(string personalID, string firstName, string lastName, string email, string phone);
    Customer *findCustomer(string personalID);
    bool removeCustomer(string personalID);

    void addAccount(string personalID, string username, string password, int balance=0);
    Account *findAccount(string username, string password);
    bool removeAccount(string username, string password);
};


#endif //IOV2_BANK_H
