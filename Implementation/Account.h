#ifndef IOV2_ACCOUNT_H
#define IOV2_ACCOUNT_H


#include "Customer.h"
#include "OperationHistory.h"
#include <string>


using std::string;

class Account {
    int id;
    Customer *customer;

    string username, password;
    float balance;
    OperationHistory operationHistory;

public:
    Account(int id, Customer *customer, string username, string password, int balance);

    void makeTransfer();
    void takeLoan();
    Customer *getCustomer();
    void setUsername(string username);
    void setPassword(string password);
    string getUsername();
    string getPassword();
    int getBalance();
    void showHistory();
};

#endif //IOV2_ACCOUNT_H
