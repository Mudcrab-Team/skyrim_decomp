// Source exposure: mixed (represented community declarations and local binary analysis).
// IMessageBoxCallbackStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IMessageBoxCallback.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x575ad0 DeletingLeaf575ad0::~DeletingLeaf575ad0
void operator delete(void*, unsigned __int64) noexcept;
#include "IMessageBoxCallbackStorageLayout.h"
namespace ResearchLayouts {
inline IMessageBoxCallbackStorageLayout::~IMessageBoxCallbackStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::IMessageBoxCallbackStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::IMessageBoxCallbackStorageLayout object;
