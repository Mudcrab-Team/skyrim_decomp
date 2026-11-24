// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x250920 TESRegionDataLandscape::LoadIcon
// Adapted bodies: TESRegionDataLandscape::LoadIcon follows fo4-private@1b765c70 src/Shared/Regions/TESRegionDataLandscape.cpp:40
#include "TESRegionDataLandscape_250920.h"

static const std::uint32_t ICON_ID = 0x4E4F4349;

bool TESRegionDataLandscape::LoadIcon(TESFile* a_mod)
{
    if (!a_mod)
        return false;
    if (a_mod->GetTESChunkID() == ICON_ID)
        icon->Load(a_mod);
    return true;
}
