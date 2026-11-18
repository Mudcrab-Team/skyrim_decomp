// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x151d6d0 BSGrassShaderProperty::IsEqual
#include "BSGrassShaderProperty.h"

// TODO body: RVA 0x151d6d0, 7 bytes, BSGrassShaderProperty::IsEqual.
bool BSGrassShaderProperty::IsEqual(NiObject* a_object)
{
    return this == a_object;
}

// Accepted leaf retained from the integrated version.
// QShader: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t BSGrassShaderProperty::QShader() const
{
    return 0x2;
}
