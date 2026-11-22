// Source exposure: mixed (community headers and pinned image).
// Code origin: existing unit plus original reconstruction of UpdateSelectedDownwardPass and UpdateRigidDownwardPass.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// NiNodeUpdateSelectedDownwardPass, NiNodeUpdateRigidDownwardPass: GUESS(low)
// 0xef4d10 BSFlattenedBoneTree::UpdateDownwardPass
// 0xef4d40 BSFlattenedBoneTree::UpdateSelectedDownwardPass
// 0xef4d70 BSFlattenedBoneTree::UpdateRigidDownwardPass
#include "BSFlattenedBoneTree.h"

void NiNodeUpdateSelectedDownwardPass(NiNode* a_node, NiUpdateData& a_data, std::uint32_t a_arg2);
void NiNodeUpdateRigidDownwardPass(NiNode* a_node, NiUpdateData& a_data, std::uint32_t a_arg2);

void BSFlattenedBoneTree::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    NiNode::UpdateDownwardPass(a_data, a_arg2);
    UpdateBoneRoots();
}

void BSFlattenedBoneTree::UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    NiNodeUpdateSelectedDownwardPass(this, a_data, a_arg2);
    UpdateBoneRoots();
}

void BSFlattenedBoneTree::UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    NiNodeUpdateRigidDownwardPass(this, a_data, a_arg2);
    UpdateBoneRoots();
}
