// Source exposure: mixed (represented community declarations and local binary analysis).
// InputEventStorageLayout, DeviceConnectEventStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/D/DeviceConnectEvent.h; MIT.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcfa530 DeletingLeafcfa530::~DeletingLeafcfa530
void operator delete(void*, unsigned __int64) noexcept;
#include "DeviceConnectEventStorageLayout.h"
namespace ResearchLayouts {
inline InputEventStorageLayout::~InputEventStorageLayout() {}
inline DeviceConnectEventStorageLayout::~DeviceConnectEventStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::DeviceConnectEventStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::DeviceConnectEventStorageLayout object;
