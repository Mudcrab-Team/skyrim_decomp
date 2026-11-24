// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x54a820 BGSFootIkRaycastInterfaceDB::KillSDM
// Adapted bodies: BGSFootIkRaycastInterfaceDB::KillSDM from fo4-private@1b765c70 src/Shared/Animation/BGSFootIkRaycastInterfaceDB.cpp:152 (see the header)
#include "BGSFootIkRaycastInterfaceDB_54a820.h"

void BGSFootIkRaycastInterfaceDB::KillSDM()
{
    BSIFootIkRaycastInterfaceDB::pInstanceS = nullptr;
    BSTSingletonSDM<BGSFootIkRaycastInterfaceDB>::KillSDM();
}
