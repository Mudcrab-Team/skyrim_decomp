// Source exposure: mixed (represented community declarations and local binary analysis).
// PlayerInputHandlerStorageLayout, ToggleRunHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/T/ToggleRunHandler.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7b1e10 DeletingLeaf7b1e10::~DeletingLeaf7b1e10
void operator delete(void*, unsigned __int64) noexcept;
#include "ToggleRunHandlerStorageLayout.h"
namespace ResearchLayouts {
inline PlayerInputHandlerStorageLayout::~PlayerInputHandlerStorageLayout() {}
inline ToggleRunHandlerStorageLayout::~ToggleRunHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ToggleRunHandlerStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ToggleRunHandlerStorageLayout object;
