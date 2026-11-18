// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraIgnoredBySandboxStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraIgnoredBySandbox.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17cd90 DeletingLeaf17cd90::~DeletingLeaf17cd90
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraIgnoredBySandboxStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraIgnoredBySandboxStorageLayout::~ExtraIgnoredBySandboxStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraIgnoredBySandboxStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ExtraIgnoredBySandboxStorageLayout object;
