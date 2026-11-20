// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BaseExtraList; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct BSExtraData_4ca6af76;
struct BaseExtraList_vtbl;
struct PresenceBitfield;
struct BaseExtraList_5f76e5cb {
    BaseExtraList_vtbl* __vftable;
    BSExtraData_4ca6af76* data;
    PresenceBitfield* presence;
};
static_assert(sizeof(BaseExtraList_5f76e5cb) == 24, "BaseExtraList_5f76e5cb layout differs from the PDB");
