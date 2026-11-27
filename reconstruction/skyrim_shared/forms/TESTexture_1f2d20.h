// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESTexture.cpp:98
// TESTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTexture::GetAsNormalFile, BSsprintf, Set, pString: SIBLING(fo4-private@1b765c70, author-permission)
// BSStringT: STANDIN SIBLING(fo4-private@1b765c70, author-permission); only the pointer member and Set are claimed
#pragma once

#include <cstdint>

struct BSStringT
{
    void Set(const char* a_string, std::uint32_t a_length);

    char* pString;  // 00
};

int BSsprintf(char* a_buffer, std::uint32_t a_size, const char* a_format, ...);

class TESTexture
{
public:
    static const char* GetAsNormalFile(BSStringT& a_out, const char* a_textureName);  // compared: 0x1f2d20
};
