// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// Adapted bodies: BSShaderTextureSet::SetTexture follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:68
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x153b3d0 BSShaderTextureSet::SetTexture
// Adapted bodies: BSShaderTextureSet::GetTexture follows momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bsshader/bsshadertextureset.cpp:27
#include "BSShaderTextureSet_153b3d0.h"

void BSShaderTextureSet::SetTexture(Texture texture, NiPointer<NiTexture>& out)
{
    NiPointer<NiTexture> result;
    if (const char* path = GetTexturePath(texture)) {
        NiPointer<NiSourceTexture> loaded;
        BSShaderManager::GetTexture(path, true, loaded, texture == kHeight);
        if (loaded.get()) {
            result = loaded.get();
        }
    }
    out = result;
}
