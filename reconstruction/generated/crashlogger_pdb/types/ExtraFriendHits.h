// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraFriendHits; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__AITimeStamp_3cf31a53.h"
struct ExtraFriendHits {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__AITimeStamp_3cf31a53 hits;
};
static_assert(sizeof(ExtraFriendHits) == 40, "ExtraFriendHits layout differs from the PDB");
