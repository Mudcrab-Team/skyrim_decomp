// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the compared body is the compiler-generated scalar deleting destructor from the listing
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a5560 ImageSpaceModifierInstanceDOF::~ImageSpaceModifierInstanceDOF
// Adapted bodies: none
#include "ImageSpaceModifierInstanceDOF.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
ImageSpaceModifierInstanceDOF::ImageSpaceModifierInstanceDOF()
{
}

// ~ImageSpaceModifierInstanceDOF stays declared but undefined: the compared deleting
// destructor calls the complete destructor out of line (cookbook rule 18).
