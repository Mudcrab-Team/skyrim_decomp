// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: KEYWORD_DATA; size 0x10
#pragma once

struct BGSKeyword;
struct KEYWORD_DATA {
    BGSKeyword* keyword;
    float data;
    unsigned int pad0C;
};
static_assert(sizeof(KEYWORD_DATA) == 16, "KEYWORD_DATA layout differs from the PDB");
