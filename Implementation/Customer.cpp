#include "Customer.h"

Customer::Customer(string personalID, string firstName, string lastName, string email, string phone) {
    this->personalID = personalID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->phone = phone;
}

string Customer::getFullName() {
    return firstName + " " + lastName;
}

string Customer::getPersonalId() {
    return personalID;
}

string Customer::getEmail() {
    return email;
}

void Customer::setEmail(string email) {
    this->email = email;
}

string Customer::getPhone() {
    return phone;
}

void Customer::setPhone(string phone) {
    this->phone = phone;
}
