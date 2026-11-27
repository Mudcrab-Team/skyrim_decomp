// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers, sibling names).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none known. The origin check reports NiTArray::SetAt as similar to the sibling bodies cited in the header (CC0-1.0); the draft states it was written from the pinned image listing.
// 0x15849a0 ImageSpaceEffectFullScreenBlur::BorrowTextures
#include "ImageSpaceEffectFullScreenBlur_15849a0.h"

void ImageSpaceEffectFullScreenBlur::BorrowTextures()
{
    blurTexture0.Function1554f40(0x16);
    effectTextures.SetAt(2, &blurTexture0);
    blurTexture1.Function1554f40(0x1A);
    effectTextures.SetAt(3, &blurTexture1);
}
