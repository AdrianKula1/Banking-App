#ifndef IOV2_TRANSFER_H
#define IOV2_TRANSFER_H
#include <string>
#include "Operation.h"

class Transfer: public Operation {
private:
    std::string destinationAccountID;
    std::string destinationName;

public:
    Transfer(int id, Type type, float amount, std::string date, std::string title, std::string destinationAccountID, std::string destinationName);

    void showInfo() override;

    void showDetailedInfo() override;
};


#endif //IOV2_TRANSFER_H
