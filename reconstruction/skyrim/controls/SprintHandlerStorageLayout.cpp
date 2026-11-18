// Source exposure: mixed (represented community declarations and local binary analysis).
// PlayerInputHandlerStorageLayout, HeldStateHandlerStorageLayout, SprintHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/SprintHandler.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7b1db0 DeletingLeaf7b1db0::~DeletingLeaf7b1db0
void operator delete(void*, unsigned __int64) noexcept;
#include "SprintHandlerStorageLayout.h"
namespace ResearchLayouts {
inline PlayerInputHandlerStorageLayout::~PlayerInputHandlerStorageLayout() {}
inline HeldStateHandlerStorageLayout::~HeldStateHandlerStorageLayout() {}
inline SprintHandlerStorageLayout::~SprintHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::SprintHandlerStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::SprintHandlerStorageLayout object;
