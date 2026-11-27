// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSFadeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSFadeNode::SetFirstChildLocalRotation: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x24c450 BSFadeNode::SetFirstChildLocalRotation
#include "BSFadeNode_24c450.h"

// Copy the local rotation matrix onto the first child node and trigger an update.
void BSFadeNode::SetFirstChildLocalRotation(const NiMatrix3& a_rot)
{
    NiNode* node = AsNode();
    if (node && node->childCapacity > 0) {
        NiAVObject* child = node->children[0];
        if (child) {
            child->localRotate = a_rot;
            NiUpdateData updateData;
            updateData.flags = 0;
            updateData.time = 0.0f;
            child->Update(updateData);
        }
    }
}
