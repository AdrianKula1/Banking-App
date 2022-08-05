#include "OperationHistory.h"
#include "Transfer.h"
#include "Loan.h"
#include <iostream>
OperationHistory::OperationHistory(){
    nextAvailableID=0;
};

int OperationHistory::getNextAvailableID() {
    return nextAvailableID;
}

void OperationHistory::addOperation(Type type, float amount, std::string title, std::string date, std::string destinationAccountID, std::string destinationName) {
    operations.push_back(new Transfer(nextAvailableID, type, amount, date, title, destinationAccountID, destinationName));
    ++nextAvailableID;
}

void OperationHistory::addOperation(Type type, float amount, std::string title, std::string date, std::string endDate) {
    operations.push_back(new Loan(nextAvailableID, type, amount, date, title, endDate));
    ++nextAvailableID;
}

Operation* OperationHistory::findOperation(int id) {
    for(int i=0; i<operations.size(); i++){
        if(operations[i]->getId()==id){
            return operations[i];
        }
    }
    return nullptr;
}

bool OperationHistory::removeOperation(int id) {
    for(int i=0; i<operations.size(); i++){
        if(operations[i]->getId()==id){
            operations.erase(operations.begin() + i);
            return true;
        }
    }
    return false;
}

void OperationHistory::showAllOperations() {
    if(operations.size()==0){
        std::cout << "\nNie wykonales jeszcze zadnej transakcji" << std::endl;
        return;
    }
    for(int i=0; i<operations.size(); i++){
        std::cout << "\nOPERACJA NUMER " << i << std::endl;
        operations[i]->showInfo();
    }
    std::cout << "\nCzy chcesz zobaczyc dokladne informacje jednej z transakcji?: Y/N" << std::endl;
    string op;
    std::cin >> op;
    if(op == "Y" || op == "y") {
        std::cout << "\nProsze wpisac indeks operacji: ";
        int ID;
        std::cin >> ID;
        if(ID >= (int)operations.size()) {
            std::cout << "Nie ma operacji o takim indeksie!\n";
            showAllOperations();
            return;
        }
        findOperation(ID)->showDetailedInfo();
    }
}


