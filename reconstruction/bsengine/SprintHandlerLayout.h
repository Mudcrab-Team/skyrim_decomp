// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/SprintHandler.h; MIT.
// SprintHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SprintHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/HeldStateHandlerLayout.h"

namespace ResearchLayouts {
class SprintHandlerLayout : public HeldStateHandlerLayout {
public:
    virtual ~SprintHandlerLayout();
};
static_assert(sizeof(SprintHandlerLayout) == 24, "community represented size");
}
