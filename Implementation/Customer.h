//
// Created by Adrian on 06.05.2022.
//

#ifndef IOV2_CUSTOMER_H
#define IOV2_CUSTOMER_H


#include <string>
using std::string;

class Customer {
    string personalID, firstName, lastName, email, phone;

public:
    Customer(string personalId, string firstName, string lastName, string email, string phone);
    string getFullName();
    string getPersonalId();
    string getEmail();
    void setEmail(string email);
    string getPhone();
    void setPhone(string phone);
};

#endif //IOV2_CUSTOMER_H
