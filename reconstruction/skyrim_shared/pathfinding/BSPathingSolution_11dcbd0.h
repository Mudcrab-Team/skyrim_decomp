// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSPathingSolution, BSPathingSolution::GetLastNode, BSPathingNode, currentPathingNodes: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingNodeArray, unknown00, unknown08, payload: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct BSPathingNode
{
    std::uint8_t payload[0x48];
};
static_assert(sizeof(BSPathingNode) == 0x48, "BSPathingNode size");

struct BSPathingNodeArray
{
    BSPathingNode* data;
    std::uint64_t unknown08;
    std::uint32_t size;

    bool Empty() const { return size == 0; }
    BSPathingNode& Back() { return data[size - 1]; }
};

class BSPathingSolution
{
public:
    BSPathingNode* GetLastNode();  // compared: 0x11dcbd0

    std::uint8_t unknown00[0x90];
    BSPathingNodeArray currentPathingNodes;  // 90
};
static_assert(offsetof(BSPathingSolution, currentPathingNodes) == 0x90, "currentPathingNodes offset");
