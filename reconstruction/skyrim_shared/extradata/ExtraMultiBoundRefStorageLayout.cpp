// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraMultiBoundRefStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraMultiBoundRef.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17d320 DeletingLeaf17d320::~DeletingLeaf17d320
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraMultiBoundRefStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraMultiBoundRefStorageLayout::~ExtraMultiBoundRefStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraMultiBoundRefStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraMultiBoundRefStorageLayout object;
