// Source exposure: mixed (binary-analysis of the pinned image, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// Adapted bodies: none known. The origin check reports NiPointer::~NiPointer, NiRefObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:2424
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:2513
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell_ob1_variant.cpp:133
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x411280 Sky::~Sky
#include "Sky_411280.h"

Sky::~Sky()
{
    delete atmosphere;
    delete stars;
    delete clouds;
    delete sun;
    delete masser;
    delete secunda;
    delete precip;

    moonsRoot = nullptr;
    auroraRoot = nullptr;
    if (root._ptr && root._ptr->unk30)
    {
        root._ptr->unk30->VFunc38(root._ptr);
    }
    root = nullptr;

    Function418580();
    Function4199A0();

    for (std::uint32_t i = 0; i < storedWorldMapCloudTextures.size; ++i)
    {
        storedWorldMapCloudTextures.Elements()[i] = nullptr;
    }
    storedWorldMapCloudTextures.Clear();

    Function418E10(true);
}
