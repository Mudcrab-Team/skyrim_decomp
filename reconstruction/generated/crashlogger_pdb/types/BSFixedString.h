// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSFixedString; size 0x8
#pragma once
struct BSFixedString {
    unsigned char* _data;
};
static_assert(sizeof(BSFixedString) == 8, "BSFixedString layout differs from the PDB");
