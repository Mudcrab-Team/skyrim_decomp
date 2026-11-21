// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSEventFlag; size 0x8
#pragma once
struct BSEventFlag {
    void* event;
};
static_assert(sizeof(BSEventFlag) == 8, "BSEventFlag layout differs from the PDB");
