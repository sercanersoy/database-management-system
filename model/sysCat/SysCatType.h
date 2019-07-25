//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPE_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPE_H


#include "../../constants.h"
#include "SysCatTypeHeader.h"

class SysCatType {
    SysCatTypeHeader typeHeader;
    char fields[SYS_CAT_TYPE_FIELD_LIMIT][SYS_CAT_TYPE_FIELD_SIZE];
};


#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPE_H
