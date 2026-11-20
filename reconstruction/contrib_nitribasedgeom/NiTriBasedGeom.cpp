// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations. The constructor and destructor bodies are empty; the image stores the vtable, calls the base complete destructor and frees the 0x138-byte object.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nitrishape.cpp:98
// NiTriBasedGeom::NiTriBasedGeom: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); an empty constructor, same shape as the sibling's, present so that the unit emits the vtable
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf18520 NiTriBasedGeom::AsNiTriBasedGeom
// 0xf1f3f0 NiTriBasedGeom::Unk_36
// 0xf1f480 NiTriBasedGeom::~NiTriBasedGeom
// Adapted bodies: NiTriBasedGeom::NiTriBasedGeom (momusdigital/fnv_decomp@91e1b6e8, no licence; an empty constructor, trivial, identical in shape).
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
