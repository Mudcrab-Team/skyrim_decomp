// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: tagRECT; size 0x10
#pragma once
struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};
static_assert(sizeof(tagRECT) == 16, "tagRECT layout differs from the PDB");
