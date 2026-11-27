// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a4ca0 ImageSpaceModifierInstanceRB::ctor
#include "ImageSpaceModifierInstanceRB_2a4ca0.h"

#include <cstring>

ImageSpaceModifierInstanceRB::ImageSpaceModifierInstanceRB(float a_first, float a_second, NiAVObject* a_target, float a_duration,
    float a_x, float a_y, float a_z, float a_w, const float* a_pair)
    : ImageSpaceModifierInstanceTemp(a_second, a_first, a_target, a_duration)
{
    std::memset(&unk30, 0, 0x48);
    if (a_target)
    {
        Vec2 position;
        a_target->position.Function14eed20(&position);
    }
    unk48 = a_first;
    unk50 = a_y;
    unk4C = a_x;
    unk54 = a_z;
    unk58 = a_w;
    unk5C = a_pair[0];
    unk60 = a_pair[1];
}
