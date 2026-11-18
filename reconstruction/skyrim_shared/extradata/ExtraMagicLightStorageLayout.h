// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraMagicLight.h; MIT.
// ExtraMagicLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraMagicLightLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraMagicLightLayout.h.
// ExtraMagicLightStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "ExtraLightStorageLayout.h"

namespace ResearchLayouts {
class ExtraMagicLightStorageLayout : public ExtraLightStorageLayout {
public:
    virtual ~ExtraMagicLightStorageLayout();
};
static_assert(sizeof(ExtraMagicLightStorageLayout) == 24, "community represented size");
}
