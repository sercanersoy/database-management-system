//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPE_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPE_H


#include "../../config.h"
#include "SysCatTypeHeader.h"

class SysCatType {
public:
    SysCatTypeHeader typeHeader;
    char fields[SYS_CAT_TYPE_FIELD_LIMIT][SYS_CAT_TYPE_FIELD_SIZE];

    SysCatType();
    SysCatType(SysCatTypeHeader _typeHeader, char **_fields);
    SysCatType &operator=(const SysCatType &rhs);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPE_H
