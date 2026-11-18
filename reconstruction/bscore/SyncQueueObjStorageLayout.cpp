// Source exposure: mixed (represented community declarations and local binary analysis).
// SyncQueueObjStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/SyncQueueObj.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x78da10 DeletingLeaf78da10::~DeletingLeaf78da10
void operator delete(void*, unsigned __int64) noexcept;
#include "SyncQueueObjStorageLayout.h"
namespace ResearchLayouts {
inline SyncQueueObjStorageLayout::~SyncQueueObjStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::SyncQueueObjStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::SyncQueueObjStorageLayout object;
