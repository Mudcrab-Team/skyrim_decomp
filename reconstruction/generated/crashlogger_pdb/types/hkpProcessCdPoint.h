// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCdPoint; size 0x30
#pragma once

#include "hkContactPoint_68092cba.h"
#include "hkPadSpu_uint32.h"
struct hkpProcessCdPoint {
    hkContactPoint_68092cba m_contact_0;
    hkPadSpu_uint32 m_contactPointId_20;
    char _pad_24[12];
};
static_assert(sizeof(hkpProcessCdPoint) == 48, "hkpProcessCdPoint layout differs from the PDB");
