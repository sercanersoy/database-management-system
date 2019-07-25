//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGE_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGE_H


#include "../../constants.h"
#include "SysCatPageHeader.h"
#include "SysCatType.h"

class SysCatPage {
    SysCatPageHeader pageHeader;
    SysCatType types[SYS_CAT_TYPE_LIMIT];
};


#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGE_H
