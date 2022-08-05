//
// Created by Adrian on 06.05.2022.
//

#include "Transfer.h"
#include <iostream>

void Transfer::showInfo(){
    if(type==0){
        std::cout << "POZYCZKA" << std::endl;
    }else if(type==1){
        std::cout << "PRZELEW" << std::endl;
    }
    std::cout << "Kwota: " << amount << std::endl;
    std::cout << "Tytul: " << title << std::endl;
}

void Transfer::showDetailedInfo(){
    std::cout << "ID: " << id << std::endl;
    if(type==0){
        std::cout << "Typ: pozyczka" << std::endl;
    }else if(type==1){
        std::cout << "Typ: przelew" << std::endl;
    }
    std::cout << "Tytul: " << title << std::endl;
    std::cout << "Kwota: " << amount << std::endl;
    std::cout << "Data przelewu: " << date << std::endl;
    std::cout << "Numer konta odbiorcy: " << destinationAccountID << std::endl;
    std::cout << "Odbiorca: " << destinationName << std::endl;
}

Transfer::Transfer(int id, Type type, float amount, std::string date, std::string title, std::string destinationAccountID, std::string destinationName): Operation(id, type, amount, date, title) {
    this->destinationAccountID=destinationAccountID;
    this->destinationName=destinationName;
}
