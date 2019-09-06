//
// Created by sercanersoy on 27.07.2019.
//

#include <cstring>
#include "SysCatTypeHeader.h"

SysCatTypeHeader::SysCatTypeHeader() {
    std::memset(typeName, 0, SYS_CAT_TYPE_FIELD_SIZE);
    nofFields = 0;
    valid = 0;
};

SysCatTypeHeader::SysCatTypeHeader(char _valid, char *_typeName, char _nofFields) {
    valid = _valid;
    nofFields = _nofFields;
    for (int i = 0; i < SYS_CAT_TYPE_FIELD_SIZE; ++i) {
        typeName[i] = _typeName[i];
    }
}

SysCatTypeHeader &SysCatTypeHeader::operator=(const SysCatTypeHeader &rhs) {
    valid = rhs.valid;
    nofFields = rhs.nofFields;
    for (int i = 0; i < SYS_CAT_TYPE_FIELD_SIZE; ++i) {
        typeName[i] = rhs.typeName[i];
    }
    return *this;
}
