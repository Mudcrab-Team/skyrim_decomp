// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraSoulStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraSoul.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18fc20 DeletingLeaf18fc20::~DeletingLeaf18fc20
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraSoulStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraSoulStorageLayout::~ExtraSoulStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraSoulStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraSoulStorageLayout object;
