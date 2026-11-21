// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSString; size 0x10
#pragma once
struct BSString {
    char* Text_0;
    unsigned short Length_8;
    unsigned short BufferSize_A;
    char _pad_C[4];
};
static_assert(sizeof(BSString) == 16, "BSString layout differs from the PDB");
