// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProperty; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "hkpPropertyValue.h"
struct hkpProperty_d8b0dba1 {
    unsigned int m_key_0;
    unsigned int m_alignmentPadding_4;
    hkpPropertyValue m_value_8;
};
static_assert(sizeof(hkpProperty_d8b0dba1) == 16, "hkpProperty_d8b0dba1 layout differs from the PDB");
