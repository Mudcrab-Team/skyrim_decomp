// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from powerof3/CommonLibSSE and CommonLibSSE-NG.
// Adapted bodies: none.
// 0x151de70 BSGrassShaderProperty::Function151de70
// 0x151de80 BSGrassShaderProperty::Function151de80
// 0x151d6d0 BSGrassShaderProperty::IsEqual
#include "BSGrassShaderProperty.h"

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

std::uint32_t BSGrassShaderProperty::Function151de70() const
{
    return unk180;
}

void BSGrassShaderProperty::Function151de80(std::uint32_t a_value)
{
    unk180 = a_value;
}
