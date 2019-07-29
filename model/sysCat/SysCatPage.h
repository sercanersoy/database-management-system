//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGE_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGE_H


#include <fstream>
#include "../../config.h"
#include "SysCatPageHeader.h"
#include "SysCatType.h"

class SysCatPage {
public:
    SysCatPageHeader pageHeader;
    SysCatType types[SYS_CAT_TYPE_LIMIT];
    SysCatPage();

    SysCatPage(SysCatPageHeader _pageHeader, SysCatType *_types);

    SysCatPage &operator=(const SysCatPage &rhs);

    static SysCatPage readFromFile(std::fstream &file, int pageNo);

    void writeToFile(std::fstream &file, int pageNo);
};


#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGE_H
