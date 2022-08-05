//
// Created by Adrian on 06.05.2022.
//

#include "Operation.h"

Operation::Operation(int id, Type type, float amount, std::string date, std::string title) {
    this->id=id;
    this->type=type;
    this->amount=amount;
    this->date=date;
    this->title=title;
}

Type Operation::getType() {
    return this->type;
}

int Operation::getId() {
    return this->id;
}
