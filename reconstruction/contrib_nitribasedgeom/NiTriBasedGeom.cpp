// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only. The destructor body is empty; the image stores the vtable, calls the base complete destructor and frees the 0x138-byte object.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf18520 NiTriBasedGeom::AsNiTriBasedGeom
// 0xf1f3f0 NiTriBasedGeom::Unk_36
// 0xf1f480 NiTriBasedGeom::~NiTriBasedGeom
// Adapted bodies: none
#include "NiTriBasedGeom.h"

NiTriBasedGeom::NiTriBasedGeom()
{
}

NiTriBasedGeom* NiTriBasedGeom::AsNiTriBasedGeom()
{
    return this;
}

std::uint32_t NiTriBasedGeom::Unk_36()
{
    return geometryData->Unk_2B();
}

NiTriBasedGeom::~NiTriBasedGeom()
{
}
