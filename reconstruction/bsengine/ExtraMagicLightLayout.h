// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraMagicLight.h; MIT.
// ExtraMagicLight: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraMagicLightLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/ExtraLightLayout.h"

namespace ResearchLayouts {
class ExtraMagicLightLayout : public ExtraLightLayout {
public:
    virtual ~ExtraMagicLightLayout();
};
static_assert(sizeof(ExtraMagicLightLayout) == 24, "community represented size");
}
