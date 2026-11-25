// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorResource.cpp:161
// CombatBehaviorResource, SetOwner, pOwner, CombatBehaviorThread, CheckParent: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatBehaviorResource, CombatBehaviorThread, CheckParent: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00: GUESS(low)
#pragma once

#include <cstdint>

class CombatBehaviorThread
{
public:
    bool CheckParent(const CombatBehaviorThread* a_thread) const;
};

class CombatBehaviorResource
{
public:
    void SetOwner(CombatBehaviorThread* a_thread);  // compared: 0x871a70

    std::uint8_t unk00[0x20];
    CombatBehaviorThread* pOwner;
};
