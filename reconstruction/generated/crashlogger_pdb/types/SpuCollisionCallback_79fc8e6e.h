// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpuCollisionCallback; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

struct hkSpuCollisionCallbackUtil_d0c70351;
struct SpuCollisionCallback_79fc8e6e {
    hkSpuCollisionCallbackUtil_d0c70351* util;
    unsigned short capacity;
    unsigned char eventFilter;  // SpuCollisionCallbackEventFilter in the PDB is wider than this slot
    unsigned char userFilter;
    unsigned int pad0C;
};
static_assert(sizeof(SpuCollisionCallback_79fc8e6e) == 16, "SpuCollisionCallback_79fc8e6e layout differs from the PDB");
