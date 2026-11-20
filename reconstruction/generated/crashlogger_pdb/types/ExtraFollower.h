// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraFollower; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__ExtraFollower__FollowerInfo_828821e9.h"
struct ExtraFollower {
    BSExtraData_4ca6af76 _base;
    BSTArray_RE__ExtraFollower__FollowerInfo_828821e9 actorFollowers;
};
static_assert(sizeof(ExtraFollower) == 40, "ExtraFollower layout differs from the PDB");
