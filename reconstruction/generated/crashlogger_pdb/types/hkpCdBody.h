// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdBody; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpShape_890c4847;
struct hkpCdBody {
    hkpShape_890c4847* shape;
    unsigned int shapeKey;
    unsigned int pad0C;
    void* motion;
    hkpCdBody* parent;
};
static_assert(sizeof(hkpCdBody) == 32, "hkpCdBody layout differs from the PDB");
