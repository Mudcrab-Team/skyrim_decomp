// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:24
// CombatBehaviorTreeNode, Name, pChildArray, uiChildCount: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatBehaviorTreeNode, BSFixedString: CRASHLOGGER_PDB(59818@2026.10.24)
// unk10, unk1c, nameString, ~BSFixedString: GUESS(low)
#pragma once

#include <cstdint>

class BSFixedString
{
public:
    ~BSFixedString();

    const char* nameString;
};

class CombatBehaviorTreeNode
{
public:
    CombatBehaviorTreeNode();
    virtual ~CombatBehaviorTreeNode();  // 00; compared: 0x875b00 (scalar deleting destructor)

    BSFixedString Name;                    // 08
    std::uint8_t unk10[8];                 // 10
    CombatBehaviorTreeNode** pChildArray;  // 18
    std::uint32_t uiChildCount;            // 20
    std::uint32_t unk24;                   // 24
};
static_assert(sizeof(CombatBehaviorTreeNode) == 0x28, "CombatBehaviorTreeNode size");
