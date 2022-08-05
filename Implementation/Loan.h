#ifndef IOV2_LOAN_H
#define IOV2_LOAN_H
#include "Operation.h"
#include <string>
#include <iostream>

class Loan: public Operation{
private:
    std::string endDate;

public:
    Loan(int id, Type type, float amount, std::string date, std::string title, std::string endDate);

    void showInfo() override;

    void showDetailedInfo() override;
};


#endif //IOV2_LOAN_H
