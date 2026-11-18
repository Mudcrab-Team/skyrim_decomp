// Source exposure: mixed (represented community declarations and local binary analysis).
// PlayerInputHandlerStorageLayout, ReadyWeaponHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/R/ReadyWeaponHandler.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7b1c80 DeletingLeaf7b1c80::~DeletingLeaf7b1c80
void operator delete(void*, unsigned __int64) noexcept;
#include "ReadyWeaponHandlerStorageLayout.h"
namespace ResearchLayouts {
inline PlayerInputHandlerStorageLayout::~PlayerInputHandlerStorageLayout() {}
inline ReadyWeaponHandlerStorageLayout::~ReadyWeaponHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ReadyWeaponHandlerStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ReadyWeaponHandlerStorageLayout object;
