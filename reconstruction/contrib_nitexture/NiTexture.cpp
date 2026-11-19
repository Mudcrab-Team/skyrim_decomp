// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only. The destructor is declared only: the image calls the complete destructor from the deleting one, and that callee is bound by the comparison.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xef3ea0 NiTexture::~NiTexture
// 0xf05940 NiTexture::Unk_25
// Adapted bodies: none
#include "NiTexture.h"

NiTexture::NiTexture()
{
}

void* NiTexture::Unk_25()
{
    return nullptr;
}
