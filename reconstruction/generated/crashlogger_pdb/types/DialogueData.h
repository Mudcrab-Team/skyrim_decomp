// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DialogueData; size 0x30
#pragma once

struct Unk28;
struct DialogueData {
    unsigned char unk0[12];
    unsigned int refCount;
    unsigned char unk10[24];
    Unk28* unk28;
};
static_assert(sizeof(DialogueData) == 48, "DialogueData layout differs from the PDB");
