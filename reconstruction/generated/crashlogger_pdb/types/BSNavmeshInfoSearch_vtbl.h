// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSNavmeshInfoSearch_vtbl; size 0x18
#pragma once
struct BSNavmeshInfoSearch_vtbl {
    void (*_dtor_BSNavmeshInfoSearch)(void);
    void (*GetNeighbors)(char32_t* , void* );
    bool (*IsAtGoal)(char32_t* );
};
static_assert(sizeof(BSNavmeshInfoSearch_vtbl) == 24, "BSNavmeshInfoSearch_vtbl layout differs from the PDB");
