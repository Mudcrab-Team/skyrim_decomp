// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryEvent; size 0x38
#pragma once
struct BGSStoryEvent {
    unsigned int id;
    unsigned int index;
    unsigned long long members[6];
};
static_assert(sizeof(BGSStoryEvent) == 56, "BGSStoryEvent layout differs from the PDB");
