// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdBody; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

struct hkpShape;
struct hkpCdBody_cce531ab {
    hkpShape* m_shape_0;
    unsigned int m_shapeKey_8;
    char _pad_C[4];
    void* m_motion_10;
    hkpCdBody_cce531ab* m_parent_18;
};
static_assert(sizeof(hkpCdBody_cce531ab) == 32, "hkpCdBody_cce531ab layout differs from the PDB");
