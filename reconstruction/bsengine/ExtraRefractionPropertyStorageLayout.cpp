// Source exposure: mixed (represented community declarations and local binary analysis).
// BSExtraDataStorageLayout, ExtraRefractionPropertyStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraRefractionProperty.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x17d920 DeletingLeaf17d920::~DeletingLeaf17d920
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraRefractionPropertyStorageLayout.h"
namespace ResearchLayouts {
inline BSExtraDataStorageLayout::~BSExtraDataStorageLayout() {}
inline ExtraRefractionPropertyStorageLayout::~ExtraRefractionPropertyStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ExtraRefractionPropertyStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ExtraRefractionPropertyStorageLayout object;
