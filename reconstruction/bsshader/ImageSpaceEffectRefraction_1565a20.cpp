// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1565a20 ImageSpaceEffectRefraction::UpdateParams
#include "ImageSpaceEffectRefraction_1565a20.h"

RefractionSettings* g_refractionSettings;

bool ImageSpaceEffectRefraction::UpdateParams(ImageSpaceEffectParam* a_param)
{
    const RefractionSettings* settings = g_refractionSettings;
    unk30->first->Function152b170(0, settings->unk98, settings->unk9C, settings->unkA0, settings->unkA4);
    return true;
}
