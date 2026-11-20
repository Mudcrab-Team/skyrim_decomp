// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSRegisteredStoryEvent; size 0x28
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
struct RE__BSTArray_RE__BGSStoryEventMember_4da805c5;
struct BGSRegisteredStoryEvent {
    unsigned char uniqueID[4];
    unsigned int pad04;
    RE__BSTArray_RE__BGSStoryEventMember_4da805c5* members;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce name;
    bool immediate;
    unsigned char pad21;
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(BGSRegisteredStoryEvent) == 40, "BGSRegisteredStoryEvent layout differs from the PDB");
