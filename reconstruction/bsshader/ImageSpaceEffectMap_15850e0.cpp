// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x15850e0 ImageSpaceEffectMap::UpdateParams
#include "ImageSpaceEffectMap_15850e0.h"

bool ImageSpaceEffectMap::UpdateParams(ImageSpaceEffectParam* a_param)
{
    ParamBlock* block = unk30->first;
    int second;
    int first;
    unk48->texture->Function1555030(&first, &second);
    block->Function152b170(0, 1.0f / static_cast<float>(first), 1.0f / static_cast<float>(second), 0.0f, 0.0f);
    return true;
}
