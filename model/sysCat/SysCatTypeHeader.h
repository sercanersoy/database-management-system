//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPEHEADER_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPEHEADER_H


#include "../../config.h"

class SysCatTypeHeader {
public:
    char valid;
    char typeName[SYS_CAT_TYPE_FIELD_SIZE];
    char nofFields;

    SysCatTypeHeader();

    SysCatTypeHeader(char _valid, char *_typeName, char _nofFields);

    SysCatTypeHeader &operator=(const SysCatTypeHeader &rhs);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPEHEADER_H
