// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraEditorRefMoveData.h; MIT.
// ExtraEditorRefMoveData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraEditorRefMoveDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraEditorRefMoveDataLayout.h.
// ExtraEditorRefMoveDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"
#include "../../bscore/BSFixedStringStorageLayout.h"

namespace ResearchLayouts {
class ExtraEditorRefMoveDataStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraEditorRefMoveDataStorageLayout();
    NiPoint3StorageLayout realAngle;
    NiPoint3StorageLayout realLocation;
    NiPoint3StorageLayout oldLocation;
};
static_assert(sizeof(ExtraEditorRefMoveDataStorageLayout) == 56, "community represented size");
static_assert(offsetof(ExtraEditorRefMoveDataStorageLayout, realAngle) == 16, "realAngle offset");
static_assert(offsetof(ExtraEditorRefMoveDataStorageLayout, realLocation) == 28, "realLocation offset");
static_assert(offsetof(ExtraEditorRefMoveDataStorageLayout, oldLocation) == 40, "oldLocation offset");
}
