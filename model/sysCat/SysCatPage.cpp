//
// Created by sercanersoy on 27.07.2019.
//

#include "SysCatPage.h"

SysCatPage::SysCatPage() = default;

SysCatPage::SysCatPage(SysCatPageHeader _pageHeader, SysCatType *_types) {
    pageHeader = _pageHeader;
    for (int i = 0; i < SYS_CAT_TYPE_LIMIT; ++i) {
        types[i] = _types[i];
    }
}

SysCatPage &SysCatPage::operator=(const SysCatPage &rhs) {
    pageHeader = rhs.pageHeader;
    for (int i = 0; i < SYS_CAT_TYPE_LIMIT; ++i) {
        types[i] = rhs.types[i];
    }
    return *this;
}

SysCatPage SysCatPage::readFromFile(std::fstream &file, int pageNo) {
    SysCatPage sysCatPage;
    file.seekg(pageNo * SYS_CAT_PAGE_SIZE);
    file.read((char*) &sysCatPage, SYS_CAT_PAGE_SIZE);
    return sysCatPage;
}

void SysCatPage::writeToFile(std::fstream &file, int pageNo) {
    file.seekp(pageNo * SYS_CAT_PAGE_SIZE);
    file.write((char*) this, SYS_CAT_PAGE_SIZE);
}
