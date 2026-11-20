// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgentNnEntry; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkEnum_hkpAgentNnTrackType_uint8.h"
struct hkpContactMgr;
struct hkpLinkedCollidable;
struct hkpAgentNnEntry {
    unsigned char m_streamCommand_0;
    unsigned char m_agentType_1;
    unsigned char m_numContactPoints_2;
    unsigned char m_size_3;
    unsigned short m_agentIndexOnCollidable_4[2];
    hkpContactMgr* m_contactMgr_8;
    unsigned char m_collisionQualityIndex_10;
    unsigned char m_forceCollideOntoPpu_11;
    hkEnum_hkpAgentNnTrackType_uint8 m_nnTrackType_12;
    unsigned char m_padding_13;
    char _pad_14[4];
    hkpLinkedCollidable* m_collidable_18[2];
};
static_assert(sizeof(hkpAgentNnEntry) == 40, "hkpAgentNnEntry layout differs from the PDB");
