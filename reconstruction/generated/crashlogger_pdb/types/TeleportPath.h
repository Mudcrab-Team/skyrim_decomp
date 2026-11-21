// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TeleportPath; size 0x48
#pragma once

#include "BSTArray_RE__TeleportPath__ParentSpaceNode_571875dd.h"
#include "BSTArray_RE__TeleportPath__TeleportLink_c45462d3.h"
#include "NiPoint3_a7124070.h"
struct TeleportPath {
    BSTArray_RE__TeleportPath__ParentSpaceNode_571875dd spaces;
    BSTArray_RE__TeleportPath__TeleportLink_c45462d3 teleportRefs;
    NiPoint3_a7124070 start;
    NiPoint3_a7124070 end;
};
static_assert(sizeof(TeleportPath) == 72, "TeleportPath layout differs from the PDB");
