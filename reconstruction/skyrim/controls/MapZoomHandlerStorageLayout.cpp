// Source exposure: mixed (represented community declarations and local binary analysis).
// MenuEventHandlerStorageLayout, MapInputHandlerStorageLayout, MapZoomHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MapZoomHandler.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x99f9f0 DeletingLeaf99f9f0::~DeletingLeaf99f9f0
void operator delete(void*, unsigned __int64) noexcept;
#include "MapZoomHandlerStorageLayout.h"
namespace ResearchLayouts {
inline MenuEventHandlerStorageLayout::~MenuEventHandlerStorageLayout() {}
inline MapInputHandlerStorageLayout::~MapInputHandlerStorageLayout() {}
inline MapZoomHandlerStorageLayout::~MapZoomHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::MapZoomHandlerStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::MapZoomHandlerStorageLayout object;
