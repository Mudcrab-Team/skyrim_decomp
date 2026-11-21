// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::TESQuest *>; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct TESQuest_fe66f8e1;
struct BSTArray_RE__TESQuest_d778905a_75e5810a {
    TESQuest_fe66f8e1** _data;
    unsigned int _capacity;
    unsigned int pad0C;
    unsigned int _size;
    unsigned int pad14;
};
static_assert(sizeof(BSTArray_RE__TESQuest_d778905a_75e5810a) == 24, "BSTArray_RE__TESQuest_d778905a_75e5810a layout differs from the PDB");
