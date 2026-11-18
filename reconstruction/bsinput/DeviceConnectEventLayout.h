// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/D/DeviceConnectEvent.h; MIT.
// DeviceConnectEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// DeviceConnectEventLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsinput/InputEventLayout.h"

namespace ResearchLayouts {
class DeviceConnectEventLayout : public InputEventLayout {
public:
    virtual ~DeviceConnectEventLayout();
    bool connected;
};
static_assert(sizeof(DeviceConnectEventLayout) == 32, "community represented size");
static_assert(offsetof(DeviceConnectEventLayout, connected) == 24, "connected offset");
}
