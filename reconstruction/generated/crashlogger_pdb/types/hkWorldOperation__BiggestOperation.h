// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkWorldOperation__BiggestOperation; size 0x28
#pragma once

#include "hkEnum_hkWorldOperation__Type_uint8.h"
struct hkWorldOperation__BiggestOperation {
    hkEnum_hkWorldOperation__Type_uint8 m_type_0;
    char _pad_1[7];
    unsigned long long dummy_8[4];
};
static_assert(sizeof(hkWorldOperation__BiggestOperation) == 40, "hkWorldOperation__BiggestOperation layout differs from the PDB");
