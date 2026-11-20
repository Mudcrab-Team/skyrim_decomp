// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FollowerInfo; size 0x8
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
struct FollowerInfo {
    BSPointerHandle_RE__Actor_1a35f4b9 actor;
    float intendedFollowDistance;
};
static_assert(sizeof(FollowerInfo) == 8, "FollowerInfo layout differs from the PDB");
