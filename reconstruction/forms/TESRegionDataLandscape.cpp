// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); bodies written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x250dd0 TESRegionDataLandscape::IsLoaded
// 0x250980 TESRegionDataLandscape::GetIconFileName
// 0x250bc0 TESRegionDataLandscape::Unk_05
#include "TESRegionDataLandscape.h"

bool TESRegionDataLandscape::IsLoaded() const
{
    return icon && icon->textureName.HasValue();
}

void TESRegionDataLandscape::GetIconFileName(BSString* a_dst)
{
    if (!icon) {
        a_dst->Set(BSStringT::EMPTY, 0);
        return;
    }
    a_dst->Set(icon->textureName._data, 0);
}

TESRegionData* TESRegionDataLandscape::Unk_05(TESRegionData* a_src)
{
    TESRegionData* result = ConstructSelf();
    result->CopyFrom(a_src, 2);
    return result;
}
