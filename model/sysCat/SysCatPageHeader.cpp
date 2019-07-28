//
// Created by sercanersoy on 27.07.2019.
//

#include "SysCatPageHeader.h"

SysCatPageHeader::SysCatPageHeader() = default;

SysCatPageHeader &SysCatPageHeader::operator=(const SysCatPageHeader &rhs) = default;

SysCatPageHeader::SysCatPageHeader(char _nofTypes, char _firstAvailType) {
    nofTypes = _nofTypes;
    firstAvailType = _firstAvailType;
}
