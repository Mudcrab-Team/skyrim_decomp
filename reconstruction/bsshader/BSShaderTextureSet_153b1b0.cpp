// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// Adapted bodies: BSShaderTextureSet::LoadBinary follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:45
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x153b1b0 BSShaderTextureSet::LoadBinary
#include "BSShaderTextureSet_153b1b0.h"

void BSShaderTextureSet::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    int count = 0;
    stream.iStr->Read(count);
    for (int index = 0; index < count; ++index) {
        stream.LoadFixedStringLegacy(textures[index]);
    }
}
