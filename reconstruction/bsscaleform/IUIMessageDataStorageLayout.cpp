// Source exposure: mixed (represented community declarations and local binary analysis).
// IUIMessageDataStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IUIMessageData.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x575b00 DeletingLeaf575b00::~DeletingLeaf575b00
void operator delete(void*, unsigned __int64) noexcept;
#include "IUIMessageDataStorageLayout.h"
namespace ResearchLayouts {
inline IUIMessageDataStorageLayout::~IUIMessageDataStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::IUIMessageDataStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::IUIMessageDataStorageLayout object;
