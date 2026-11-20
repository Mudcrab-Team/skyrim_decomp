// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraIgnoredBySandbox.h; MIT.
// ExtraIgnoredBySandbox: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraIgnoredBySandboxLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class ExtraIgnoredBySandboxLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraIgnoredBySandboxLayout();
};
static_assert(sizeof(ExtraIgnoredBySandboxLayout) == 16, "community represented size");
}
