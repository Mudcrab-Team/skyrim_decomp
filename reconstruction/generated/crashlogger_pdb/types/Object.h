// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Object; size 0x1d0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_RE__BSScript__UnlinkedTypes__FunctionDebugInfo_RE__BSScrapArrayAllocator_11991507.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_2dd245fc.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_6ccf9bdf.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_7c4d15b1.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_9f660166.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_be521491.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_cbb18849.h"
struct Object {
    BSFixedString_char_83b572b4 fileName;
    unsigned long long compilationTime;
    BSFixedString_char_83b572b4 userName;
    BSFixedString_char_83b572b4 computerName;
    unsigned char loadDebugInformation;
    unsigned char undefined_21[7];
    unsigned long long modificationTime;
    BSTArray_RE__BSScript__UnlinkedTypes__FunctionDebugInfo_RE__BSScrapArrayAllocator_11991507 functionDebugInfoList;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_6ccf9bdf userFlagMap;
    BSFixedString_char_83b572b4 className;
    BSFixedString_char_83b572b4 parentClassName;
    BSFixedString_char_83b572b4 docString;
    unsigned int userFlags;
    unsigned int pad_9C;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_cbb18849 variables;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_7c4d15b1 properties;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_be521491 staticFunctions;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_be521491 memberFunctions;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_9f660166 stateMap;
    unsigned int totalFunctions;
    unsigned int pad_194;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_2dd245fc initialVariableValues;
    BSFixedString_char_83b572b4 autoStateName;
};
static_assert(sizeof(Object) == 464, "Object layout differs from the PDB");
