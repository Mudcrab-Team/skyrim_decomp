// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerEventNode; size 0x68
#pragma once

#include "BGSStoryManagerBranchNode.h"
struct BGSRegisteredStoryEvent;
struct BGSStoryManagerEventNode {
    BGSStoryManagerBranchNode _base;
    BGSRegisteredStoryEvent* event;
};
static_assert(sizeof(BGSStoryManagerEventNode) == 104, "BGSStoryManagerEventNode layout differs from the PDB");
