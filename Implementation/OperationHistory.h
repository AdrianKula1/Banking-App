#ifndef IOV2_OPERATIONHISTORY_H
#define IOV2_OPERATIONHISTORY_H


#include <string>
#include <vector>
#include "Operation.h"

using std::string, std::vector;



class OperationHistory {
vector<Operation*> operations;
int nextAvailableID;
public:
    OperationHistory();
    void addOperation(Type type, float amount, std::string title, std::string date, std::string destinationAccountID, std::string destinationName);
    void addOperation(Type type, float amount, std::string title, std::string date, std::string endDate);
    Operation* findOperation(int id);
    int getNextAvailableID();
    bool removeOperation(int id);
    void showAllOperations();
};


#endif //IOV2_OPERATIONHISTORY_H
