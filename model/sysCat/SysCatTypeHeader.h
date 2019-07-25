//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPEHEADER_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPEHEADER_H


#include "../../constants.h"

class SysCatTypeHeader {
    char valid;
    char typeName[SYS_CAT_TYPE_FIELD_SIZE];
    char nofFields;
};


#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATTYPEHEADER_H
