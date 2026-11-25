// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image and community declarations. Stamped as a twin of matched 0x44e660 (skyrim/ai/BGSPackageDataBool): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// 0x44d730 Owner44d730::~Owner44d730
// CI hash: 0x44d730 ??_GOwner44d730@@UEAAPEAXI@Z
#include "Owner44d730.h"

// Emits the vftable and its scalar deleting destructor.
Owner44d730::Owner44d730()
{
}

Owner44d730::~Owner44d730()
{
    flags08.bits &= ~std::uint64_t{3};
}
