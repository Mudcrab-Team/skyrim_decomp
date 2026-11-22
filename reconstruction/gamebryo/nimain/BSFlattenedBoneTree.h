// Source exposure: mixed (community headers and pinned image).
// Code origin: existing unit plus original reconstruction of UpdateSelectedDownwardPass and UpdateRigidDownwardPass.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSFlattenedBoneTree, BSFlattenedBoneTree::UpdateDownwardPass, UpdateSelectedDownwardPass, UpdateRigidDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// UpdateBoneRoots, unknown128: GUESS(low)
#pragma once

#include <cstdint>
#include "NiNode_ee1560.h"

class BSFlattenedBoneTree : public NiNode
{
public:
    void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2) override;  // compared: 0xef4d10
    virtual void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xef4d40
    virtual void UpdateRigidDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xef4d70

    void UpdateBoneRoots();

    std::uint8_t unknown128[0x40];  // 128
};
static_assert(sizeof(BSFlattenedBoneTree) == 0x168, "BSFlattenedBoneTree size");
