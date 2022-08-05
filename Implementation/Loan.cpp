#include "Loan.h"


void Loan::showInfo(){
    std::cout << "Indeks: " << id << std::endl;
    std::cout << "Rodzaj: " << type << std::endl;
    std::cout << "Kwota: " << amount << std::endl;
    std::cout << "Tytul: " << title << std::endl;
}

void Loan::showDetailedInfo(){
    std::cout << "ID: " << id << std::endl;
    std::cout << "Rodzaj: " << type << std::endl;
    std::cout << "Kwota: " << amount << std::endl;
    std::cout << "Data poczatkowa: " << date << std::endl;
    std::cout << "Data koncowa: " << endDate << std::endl;
    std::cout << "Tytul: " << title << std::endl;
}

Loan::Loan(int id, Type type, float amount, std::string date, std::string title, std::string endDate): Operation(id, type, amount, date, title) {
    this->endDate=endDate;
}
