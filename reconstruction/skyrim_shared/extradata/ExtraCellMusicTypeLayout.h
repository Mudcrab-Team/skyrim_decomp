// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCellMusicType.h; MIT.
// ExtraCellMusicType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCellMusicTypeLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class BGSMusicType;
class ExtraCellMusicTypeLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraCellMusicTypeLayout();
    BGSMusicType* type;
};
static_assert(sizeof(ExtraCellMusicTypeLayout) == 24, "community represented size");
static_assert(offsetof(ExtraCellMusicTypeLayout, type) == 16, "type offset");
}
