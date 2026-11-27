// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorTreeNode, CombatBehaviorThread, CombatBehaviorThread::GetAscendingUpdate: CRASHLOGGER_PDB(59818@2026.10.24)
// CombatBehaviorTreeNode::unk00, CombatBehaviorTreeNode::parent, CombatBehaviorThread::unk00, CombatBehaviorThread::currentNode, CombatBehaviorThread::previousNode: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class CombatBehaviorTreeNode
{
public:
    std::uint8_t            unk00[0x10];
    CombatBehaviorTreeNode* parent;  // 0x10
};
static_assert(offsetof(CombatBehaviorTreeNode, parent) == 0x10, "CombatBehaviorTreeNode::parent offset");

class CombatBehaviorThread
{
public:
    bool GetAscendingUpdate() const;

    std::uint8_t            unk00[0x138];
    CombatBehaviorTreeNode* currentNode;   // 0x138
    CombatBehaviorTreeNode* previousNode;  // 0x140
};
static_assert(offsetof(CombatBehaviorThread, currentNode) == 0x138, "currentNode offset");
static_assert(offsetof(CombatBehaviorThread, previousNode) == 0x140, "previousNode offset");
