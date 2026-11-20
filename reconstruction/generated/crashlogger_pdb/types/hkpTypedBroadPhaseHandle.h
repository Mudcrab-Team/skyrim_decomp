// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTypedBroadPhaseHandle; size 0xc
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkpTypedBroadPhaseHandle {
    unsigned int m_id_0;
    char m_type_4;
    char m_ownerOffset_5;
    char m_objectQualityType_6;
    char _pad_7;
    unsigned int m_collisionFilterInfo_8;
};
static_assert(sizeof(hkpTypedBroadPhaseHandle) == 12, "hkpTypedBroadPhaseHandle layout differs from the PDB");
