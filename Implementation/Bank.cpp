#include "Bank.h"
Bank::Bank() {
    availableAccountID = 0;
}

Bank::~Bank() {
    for(int i=0; i<(int)customers.size(); ++i) {
        delete customers[i];
    }
    for(int i=0; i<(int)accounts.size(); ++i) {
        delete accounts[i];
    }
}

void Bank::addCustomer(string personalID, string firstName, string lastName, string email, string phone) {
    Customer *customer = new Customer(personalID, firstName, lastName, email, phone);
    customers.push_back(customer);
}

Customer *Bank::findCustomer(string personalID) {
    for(Customer *customer : customers) {
        if(customer->getPersonalId() == personalID) return customer;
    }
    return nullptr;     // customer does not exist
}

bool Bank::removeCustomer(string personalID) {
    for(int i=0; i<(int)customers.size(); ++i) {
        if(customers[i]->getPersonalId() == personalID) {
            delete customers[i];
            customers.erase(customers.begin() + i);     // erasing garbage value from vector
            return true;
        }
    }
    return false;
}

void Bank::addAccount(string personalID, string username, string password, int balanceInPennies) {
    Account *account = new Account(availableAccountID, findCustomer(personalID), username, password, balanceInPennies);
    accounts.push_back(account);
    ++availableAccountID;
}

Account *Bank::findAccount(string username, string password) {
    for(Account *account : accounts) {
        if(account->getUsername() == username) {
            if(account->getPassword() != password) return nullptr;  // invalid password
            return account;
        }
    }
    return nullptr;     // account does not exist
}

bool Bank::removeAccount(string username, string password) {
    for(int i=0; i<(int)accounts.size(); ++i) {
        if(accounts[i]->getUsername() == username) {
            if(accounts[i]->getPassword() != password) return false;    // invalid password
            delete accounts[i];
            accounts.erase(accounts.begin() + i);       // erasing garbage value from vector
            return true;
        }
    }
    return false;
}
