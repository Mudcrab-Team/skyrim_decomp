// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<TESRace*>; size 0x18
#pragma once

struct TESRace_e57679c0;
struct BSTArray_TESRace_e2dbea85 {
    TESRace_e57679c0** _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_TESRace_e2dbea85) == 24, "BSTArray_TESRace_e2dbea85 layout differs from the PDB");
