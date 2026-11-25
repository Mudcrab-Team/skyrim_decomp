// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorTreeNode, Function875510, CombatBehaviorTreeChild, unk18, unk20, unk08: GUESS(low)
#pragma once

#include <cstdint>

struct CombatBehaviorTreeChild
{
    std::uint64_t unk00;
    std::uint64_t unk08;
};

class CombatBehaviorTreeNode
{
public:
    std::uint32_t Function875510(const std::uint64_t* a_key);  // compared: 0x875510

    char unk00[0x18];
    CombatBehaviorTreeChild** unk18;
    std::uint32_t unk20;
};
