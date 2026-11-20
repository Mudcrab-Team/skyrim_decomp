// Source exposure: mixed (represented community declarations and local binary analysis).
// InputEventStorageLayout, CharEventStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CharEvent.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcfa500 DeletingLeafcfa500::~DeletingLeafcfa500
void operator delete(void*, unsigned __int64) noexcept;
#include "CharEventStorageLayout.h"
namespace ResearchLayouts {
inline InputEventStorageLayout::~InputEventStorageLayout() {}
inline CharEventStorageLayout::~CharEventStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::CharEventStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::CharEventStorageLayout object;
