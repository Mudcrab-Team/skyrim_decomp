// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: StringChunk; size 0x108
#pragma once
struct StringChunk {
    unsigned char strings_raw[256];
    StringChunk* next;
};
static_assert(sizeof(StringChunk) == 264, "StringChunk layout differs from the PDB");
