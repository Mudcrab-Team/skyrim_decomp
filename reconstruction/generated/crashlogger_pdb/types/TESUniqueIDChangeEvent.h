// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESUniqueIDChangeEvent; size 0x10
#pragma once
struct TESUniqueIDChangeEvent {
    unsigned int oldBaseID;
    unsigned int newBaseID;
    unsigned int objectID;
    unsigned short oldUniqueID;
    unsigned short newUniqueID;
};
static_assert(sizeof(TESUniqueIDChangeEvent) == 16, "TESUniqueIDChangeEvent layout differs from the PDB");
