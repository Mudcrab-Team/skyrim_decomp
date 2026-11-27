// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// Adapted bodies: BSShaderManager::GetTexture follows momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshadermanager.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshadermanager.cpp:270
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x14ec0a0 BSShaderManager::GetTexture
#include "BSShaderManager_14ec0a0.h"

#include <cstring>

extern "C" int sprintf_s(char* buffer, std::size_t size, const char* format, ...);

namespace
{
    constexpr char kSpecialPathMarker = '\b';
    constexpr std::size_t kPathCapacity = 260;
}

void BSShaderManager::GetTexture(const char* path, bool demand, NiPointer<NiTexture>& out, bool isHeightMap)
{
    NiPointer<NiTexture> texture;
    if (path != nullptr) {
        if (*path == kSpecialPathMarker) {
            if (std::strncmp(path, kSpecialFallback, 4) == 0 ||
                std::strncmp(path, kSpecialDefault, 4) == 0) {
                texture = g_defaultTexture;
            }
        } else if (demand) {
            const std::uint32_t mode = textureLoadMode;
            LoadTexture(path, texture, demand, isHeightMap, mode, false, false);
        } else {
            LookupTexture(path, texture);
        }
    }

    if (!texture.get()) {
        char message[kPathCapacity];
        sprintf_s(message, sizeof(message), kMissingTextureFormat, path);
        if (isHeightMap) {
            texture = g_defaultHeightTexture;
        } else {
            texture = g_defaultTexture;
        }
    }

    out = texture;
}
