// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSInputDevice; size 0x70
#pragma once

#include "BSIInputDevice.h"
#include "BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_56be95b9.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_2c8e9f8b.h"
struct BSInputDevice {
    BSIInputDevice _base;
    unsigned char device_raw[4];
    unsigned int pad0C;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_2c8e9f8b deviceButtons;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_56be95b9 buttonNameIDMap;
};
static_assert(sizeof(BSInputDevice) == 112, "BSInputDevice layout differs from the PDB");
