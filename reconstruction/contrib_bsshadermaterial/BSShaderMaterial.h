// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1575700 BSShaderMaterial::CopyMembers
// BSShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSShaderMaterial::CopyMembers, BSShaderMaterial::texCoordOffset, BSShaderMaterial::texCoordScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint2: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_00, Unk_01: GUESS(low); placeholder virtual slots that keep CopyMembers at slot 0x02
// unk08: GUESS(low)
#pragma once

#include <cstdint>

struct NiPoint2
{
    float x;
    float y;
};

class BSShaderMaterial
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void CopyMembers(BSShaderMaterial* a_other);  // 02

    std::uint32_t unk08;  // 08
    NiPoint2      texCoordOffset[2];  // 0C
    NiPoint2      texCoordScale[2];   // 1C
};
