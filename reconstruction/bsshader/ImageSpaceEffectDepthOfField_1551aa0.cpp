// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTArray::SetAt as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x1551aa0 ImageSpaceEffectDepthOfField::ReturnTextures
#include "ImageSpaceEffectDepthOfField_1551aa0.h"

void ImageSpaceEffectDepthOfField::ReturnTextures()
{
    effectTextures.SetAt(2, nullptr);
    effectTextures.SetAt(3, nullptr);
    effectTextures.data[4]->Function15550d0();
    effectTextures.SetAt(4, nullptr);
    if (effectTextures.data[6]) {
        effectTextures.SetAt(6, nullptr);
    }
}
