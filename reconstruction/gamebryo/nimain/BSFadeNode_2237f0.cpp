// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSFadeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSFadeNode::FindScabbardNode: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x2237f0 BSFadeNode::FindScabbardNode
#include "BSFadeNode_2237f0.h"

#include <cstring>

// Search child nodes for a scabbard child and detach it when found.
bool BSFadeNode::FindScabbardNode()
{
    NiNode* current = this;
    while (current) {
        std::uint32_t i = 0;
        while (i < current->childCapacity) {
            NiAVObject* child = current->children[i];
            if (child) {
                const char* name = child->name;
                if (name) {
                    if (_stricmp(name, gScabbardName) == 0) {
                        current->DetachChildAt(i);
                        return true;
                    }
                    if (_strnicmp(name, gWeaponPrefix, 9) == 0) {
                        current = child->AsNode();
                        goto next_node;
                    }
                }
            }
            ++i;
        }
        return false;
    next_node:;
    }
    return false;
}
