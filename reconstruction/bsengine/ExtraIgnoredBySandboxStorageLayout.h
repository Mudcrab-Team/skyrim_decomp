// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraIgnoredBySandbox.h; MIT.
// ExtraIgnoredBySandbox: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraIgnoredBySandboxLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraIgnoredBySandboxLayout.h.
// ExtraIgnoredBySandboxStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"

namespace ResearchLayouts {
class ExtraIgnoredBySandboxStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraIgnoredBySandboxStorageLayout();
};
static_assert(sizeof(ExtraIgnoredBySandboxStorageLayout) == 16, "community represented size");
}
