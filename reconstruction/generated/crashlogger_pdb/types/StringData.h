// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StringData; size 0x8
#pragma once
struct StringData {
    unsigned int aliasID;
    unsigned int fullNameFormID;
};
static_assert(sizeof(StringData) == 8, "StringData layout differs from the PDB");
