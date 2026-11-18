// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraPortalRefData.h; MIT.
// ExtraPortalRefData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPortalRefDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"

namespace ResearchLayouts {
class PortalLinkedRefData;
class ExtraPortalRefDataLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraPortalRefDataLayout();
    PortalLinkedRefData* data;
};
static_assert(sizeof(ExtraPortalRefDataLayout) == 24, "community represented size");
static_assert(offsetof(ExtraPortalRefDataLayout, data) == 16, "data offset");
}
