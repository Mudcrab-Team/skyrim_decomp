// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14e72c0 BSShaderProperty::CreateClone
// 0x14e74d0 BSShaderProperty::IsEqual
// 0x14e77a0 BSShaderProperty::SetupGeometry
// Adapted bodies: none
#include "BSShaderProperty.h"

NiObject* BSShaderProperty::CreateClone(NiCloningProcess& a_cloning)
{
    return nullptr;
}

bool BSShaderProperty::IsEqual(NiObject* a_object)
{
    return false;
}

bool BSShaderProperty::SetupGeometry(BSGeometry* a_geometry)
{
    return true;
}
