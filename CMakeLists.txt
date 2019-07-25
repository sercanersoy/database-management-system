cmake_minimum_required(VERSION 3.14)
project(database_management_system)

set(CMAKE_CXX_STANDARD 11)

add_executable(database_management_system main.cpp util/queryParser.cpp util/queryParser.h constants.h model/sysCat/SysCatPageHeader.h model/sysCat/SysCatPage.h model/sysCat/SysCatTypeHeader.h model/sysCat/SysCatType.h model/dataFile/DataFilePageHeader.h model/dataFile/DataFilePage.h model/dataFile/DataFileRecordHeader.h model/dataFile/DataFileRecord.h)