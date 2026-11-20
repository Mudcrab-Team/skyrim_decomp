// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadGameBuffer; size 0x28
#pragma once

struct BGSLoadGameBuffer_vtbl_909d8c1b;
struct BGSLoadGameBuffer {
    BGSLoadGameBuffer_vtbl_909d8c1b* __vftable;
    void* buffer;
    unsigned long long unk10;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int bufferPosition;
};
static_assert(sizeof(BGSLoadGameBuffer) == 40, "BGSLoadGameBuffer layout differs from the PDB");
