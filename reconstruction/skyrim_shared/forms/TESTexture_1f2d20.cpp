// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:98
// 0x1f2d20 TESTexture::GetAsNormalFile
#include "TESTexture_1f2d20.h"
#include <cstring>

const char* TESTexture::GetAsNormalFile(BSStringT& a_out, const char* a_textureName)
{
    if (!a_textureName)
        return nullptr;
    char origFilename[260];
    strcpy_s(origFilename, 0x104u, a_textureName);
    char* dot = strrchr(origFilename, '.');
    if (!dot)
        return nullptr;
    *dot = 0;
    char finalFilename[260];
    BSsprintf(finalFilename, 0x104u, "%s_n.dds", origFilename);
    a_out.Set(finalFilename, 0);
    return a_out.pString ? a_out.pString : "";
}
