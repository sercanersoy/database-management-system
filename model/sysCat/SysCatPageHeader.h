//
// Created by sercanersoy on 25.07.2019.
//

#ifndef DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGEHEADER_H
#define DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGEHEADER_H


class SysCatPageHeader {
public:
    char nofTypes = 0;
    char firstAvailType = 0;

    SysCatPageHeader();
    SysCatPageHeader(char _nofTypes, char _firstAvailType);
    SysCatPageHeader &operator=(const SysCatPageHeader& rhs);
};

#endif //DATABASE_MANAGEMENT_SYSTEM_SYSCATPAGEHEADER_H
