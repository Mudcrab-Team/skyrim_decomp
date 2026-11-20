// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BaseExtraList; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSExtraData;
struct BaseExtraList {
    BSExtraData* data_00;
    unsigned long long* presence__10;
    unsigned char undefined_10[8];
};
static_assert(sizeof(BaseExtraList) == 24, "BaseExtraList layout differs from the PDB");
