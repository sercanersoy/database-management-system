cmake_minimum_required(VERSION 3.14)
project(database_management_system)

set(CMAKE_CXX_STANDARD 11)

add_executable(database_management_system main.cpp util/QueryManager.cpp util/QueryManager.h config.h model/sysCat/SysCatPageHeader.h model/sysCat/SysCatPage.h model/sysCat/SysCatTypeHeader.h model/sysCat/SysCatType.h model/dataFile/DataFilePageHeader.h model/dataFile/DataFilePage.h model/dataFile/DataFileRecordHeader.h model/dataFile/DataFileRecord.h model/sysCat/SysCatPage.cpp model/sysCat/SysCatPageHeader.cpp model/sysCat/SysCatType.cpp model/sysCat/SysCatTypeHeader.cpp util/FileManager.cpp util/FileManager.h util/Functions.cpp util/Functions.h model/dataFile/DataFilePage.cpp model/dataFile/DataFilePageHeader.cpp model/dataFile/DataFileRecord.cpp)