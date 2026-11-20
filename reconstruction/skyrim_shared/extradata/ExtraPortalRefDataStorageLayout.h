// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraPortalRefData.h; MIT.
// ExtraPortalRefData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraPortalRefDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraPortalRefDataLayout.h.
// ExtraPortalRefDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class PortalLinkedRefData;
class ExtraPortalRefDataStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraPortalRefDataStorageLayout();
    PortalLinkedRefData* data;
};
static_assert(sizeof(ExtraPortalRefDataStorageLayout) == 24, "community represented size");
static_assert(offsetof(ExtraPortalRefDataStorageLayout, data) == 16, "data offset");
}
