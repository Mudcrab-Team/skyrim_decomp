// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSFlattenedBoneTree: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSFlattenedBoneTree::UpdateDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// UpdateBoneRoots: GUESS(low)
// unknown128: GUESS(low)
#pragma once

#include <cstdint>
#include "NiNode_ee1560.h"

class BSFlattenedBoneTree : public NiNode
{
public:
    virtual void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xef4d10

    void UpdateBoneRoots();

    std::uint8_t unknown128[0x40];  // 128
};
static_assert(sizeof(BSFlattenedBoneTree) == 0x168, "BSFlattenedBoneTree size");
