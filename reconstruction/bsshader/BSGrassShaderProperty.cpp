// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0-or-later.
// This file is free software: you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version.
// This file is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU General Public License for more details. A copy is provided in
// licenses/CommonLibSSE-GPL-3.0.txt; see also https://www.gnu.org/licenses/.
// 0x151db90 BSGrassShaderProperty::GetRenderPasses_ShadowMapOrMask
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Code origin: original bodies written from the local listing; declarations from powerof3/CommonLibSSE and CommonLibSSE-NG.
// Adapted bodies: none.
#include "BSGrassShaderProperty.h"

void BSGrassShaderProperty::GetRenderPasses_ShadowMapOrMask()
{
    GetRenderPasses();
}

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
