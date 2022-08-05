#include "Account.h"
#include "Type.h"
#include <iostream>
Account::Account(int id, Customer *customer, string username, string password, int balance) {
    this->id = id;
    this->customer = customer;
    this->username = username;
    this->password = password;
    this->balance = balance;
}

void Account::makeTransfer() {
    Type type = transfer;
    float amount;
    std::cout << "\nPodaj kwote przelewu: ";
    std::cin >> amount;
    if(this->balance-amount<0){
        std::cout << "Niewystarczajaca ilosc srodkow, przerywanie przelewu\n";
        return;
    }
    this->balance -= amount;
    string title;
    std::cout << "Podaj tytul przelewu: ";
    std::getline(std::cin >> std::ws, title);
//    std::cin >> title;
    string date="Today";
    string destinationAccountID;
    std::cout << "Podaj numer konta odbiorcy: ";
    std::cin >> destinationAccountID;
    string destinationName;
    std::cout << "Podaj nazwe odbiorcy: ";
    std::getline(std::cin >> std::ws, destinationName);
//    std::cin >> destinationName;


    operationHistory.addOperation(type, amount, title, date, destinationAccountID, destinationName);
    std::cout << "Przelew wykonano: " << std::endl;
}

void Account::takeLoan() {

    Type type = loan;
    float amount;
    std::cout << "\nPodaj kwote pozyczki: ";
    std::cin >> amount;
    this->balance += amount;
    string title = "Pozyczka nr " + std::to_string(operationHistory.getNextAvailableID());
    string date="Today";
    string endDate="Tomorrow";

    operationHistory.addOperation(type, amount, title, date, endDate);
    std::cout << "Pozyczke pobrano" << std::endl;
}

Customer *Account::getCustomer() {
    return customer;
}

string Account::getUsername() {
    return username;
}

string Account::getPassword() {
    return password;
}

void Account::setUsername(string username) {
    this->username = username;
}

void Account::setPassword(string password) {
    this->password = password;
}

int Account::getBalance() {
    return balance;
}

void Account::showHistory() {
    operationHistory.showAllOperations();
}
