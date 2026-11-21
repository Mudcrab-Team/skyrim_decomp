// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbEventPayload; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkbEventPayload__VFTable;
struct hkbEventPayload {
    hkbEventPayload__VFTable* vftable_hkbEventPayload_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
};
static_assert(sizeof(hkbEventPayload) == 16, "hkbEventPayload layout differs from the PDB");
