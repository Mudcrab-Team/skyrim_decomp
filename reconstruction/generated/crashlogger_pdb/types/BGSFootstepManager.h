// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSFootstepManager; size 0x80
#pragma once

#include "BSTArray_RE__detail__BSFixedString_char_dee190e5.h"
#include "BSTEventSource_RE__BGSFootstepEvent_11dcce9c.h"
#include "BSTSingletonSDM_RE__BGSFootstepManager_22d04b27.h"
struct BGSFootstepManager {
    BSTEventSource_RE__BGSFootstepEvent_11dcce9c _base;
    BSTSingletonSDM_RE__BGSFootstepManager_22d04b27 _base_BSTSingletonSDM_RE_BGSFootstepManager_;
    unsigned char pad59;
    unsigned short pad5A;
    unsigned int pad5C;
    BSTArray_RE__detail__BSFixedString_char_dee190e5 unk60;
    unsigned long long unk78;
};
static_assert(sizeof(BGSFootstepManager) == 128, "BGSFootstepManager layout differs from the PDB");
