//
// Created by sercanersoy on 27.07.2019.
//

#include <cstring>
#include "SysCatType.h"

SysCatType::SysCatType() {
    for (auto &fieldName : fields) {
        memset(fieldName, 0, SYS_CAT_TYPE_FIELD_SIZE);
    }
};

SysCatType::SysCatType(SysCatTypeHeader _typeHeader, char **_fields) {
    typeHeader = _typeHeader;
    for (int i = 0; i < SYS_CAT_TYPE_FIELD_LIMIT; ++i) {
        for (int j = 0; j < SYS_CAT_TYPE_FIELD_SIZE; ++j) {
            fields[i][j] = _fields[i][j];
        }
    }
}

SysCatType &SysCatType::operator=(const SysCatType &rhs) {
    typeHeader = rhs.typeHeader;
    for (int i = 0; i < SYS_CAT_TYPE_FIELD_LIMIT; ++i) {
        for (int j = 0; j < SYS_CAT_TYPE_FIELD_SIZE; ++j) {
            fields[i][j] = rhs.fields[i][j];
        }
    }
    return *this;
}
