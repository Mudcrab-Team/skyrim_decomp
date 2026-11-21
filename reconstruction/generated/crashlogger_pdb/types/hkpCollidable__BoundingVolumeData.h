// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidable::BoundingVolumeData; size 0x38
#pragma once

struct hkAabbUint32;
struct hkpCollidable__BoundingVolumeData {
    unsigned int m_min_0[3];
    unsigned char m_expansionMin_C[3];
    unsigned char m_expansionShift_F;
    unsigned int m_max_10[3];
    unsigned char m_expansionMax_1C[3];
    unsigned char m_padding_1F;
    unsigned short m_numChildShapeAabbs_20;
    unsigned short m_capacityChildShapeAabbs_22;
    char _pad_24[4];
    hkAabbUint32* m_childShapeAabbs_28;
    unsigned int* m_childShapeKeys_30;
};
static_assert(sizeof(hkpCollidable__BoundingVolumeData) == 56, "hkpCollidable__BoundingVolumeData layout differs from the PDB");
