#ifndef IOV2_OPERATION_H
#define IOV2_OPERATION_H

#include <string>
#include "Type.h"


class Operation {
protected:
    int id;
    Type type;
    float amount;
    std::string date;
    std::string title;
public:
    Operation(int id, Type type, float amount, std::string date, std::string title);
    virtual void showInfo() = 0;
    virtual void showDetailedInfo() = 0;
    Type getType();
    int getId();
};


#endif //IOV2_OPERATION_H
