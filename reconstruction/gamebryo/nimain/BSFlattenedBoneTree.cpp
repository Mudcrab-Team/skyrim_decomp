// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xef4d10 BSFlattenedBoneTree::UpdateDownwardPass
#include "BSFlattenedBoneTree.h"

void BSFlattenedBoneTree::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
    NiNode::UpdateDownwardPass(a_data, a_arg2);
    UpdateBoneRoots();
}
