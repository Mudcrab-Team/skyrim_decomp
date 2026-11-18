// Source exposure: mixed (represented community declarations and local binary analysis).
// MenuEventHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/M/MenuEventHandler.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x582480 DeletingLeaf582480::~DeletingLeaf582480
void operator delete(void*, unsigned __int64) noexcept;
#include "MenuEventHandlerStorageLayout.h"
namespace ResearchLayouts {
inline MenuEventHandlerStorageLayout::~MenuEventHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::MenuEventHandlerStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::MenuEventHandlerStorageLayout object;
