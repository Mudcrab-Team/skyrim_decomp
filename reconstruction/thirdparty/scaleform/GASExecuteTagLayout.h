// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/G/GASExecuteTag.h; MIT.
// GASExecuteTag: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GASExecuteTagLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class GASExecuteTagLayout {
public:
    virtual ~GASExecuteTagLayout();
};
static_assert(sizeof(GASExecuteTagLayout) == 8, "community represented size");
}
