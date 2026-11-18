// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraEditorRefMoveData.h; MIT.
// ExtraEditorRefMoveData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraEditorRefMoveDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSExtraDataLayout.h"
#include "bsengine/BSFixedStringLayout.h"

namespace ResearchLayouts {
class ExtraEditorRefMoveDataLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraEditorRefMoveDataLayout();
    NiPoint3Layout realAngle;
    NiPoint3Layout realLocation;
    NiPoint3Layout oldLocation;
};
static_assert(sizeof(ExtraEditorRefMoveDataLayout) == 56, "community represented size");
static_assert(offsetof(ExtraEditorRefMoveDataLayout, realAngle) == 16, "realAngle offset");
static_assert(offsetof(ExtraEditorRefMoveDataLayout, realLocation) == 28, "realLocation offset");
static_assert(offsetof(ExtraEditorRefMoveDataLayout, oldLocation) == 40, "oldLocation offset");
}
