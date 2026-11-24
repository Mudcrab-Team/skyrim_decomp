// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: BSShaderTextureSet::SaveBinary follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x153b250 BSShaderTextureSet::SaveBinary
#include "BSShaderTextureSet_153b250.h"

void BSShaderTextureSet::SaveBinary(NiStream& stream)
{
    NiObject::SaveBinary(stream);
    std::uint32_t count = 9;
    stream.oStr->write(&count, 1);
    for (std::uint32_t i = 0; i < 9; ++i) {
        stream.WriteStreamString(textures[i]);
    }
}
