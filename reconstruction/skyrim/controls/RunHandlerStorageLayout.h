// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/R/RunHandler.h; MIT.
// RunHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RunHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/RunHandlerLayout.h.
// RunHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "HeldStateHandlerStorageLayout.h"

namespace ResearchLayouts {
class RunHandlerStorageLayout : public HeldStateHandlerStorageLayout {
public:
    virtual ~RunHandlerStorageLayout();
};
static_assert(sizeof(RunHandlerStorageLayout) == 24, "community represented size");
}
