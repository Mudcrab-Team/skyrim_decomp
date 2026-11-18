// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraStartingWorldOrCell.h; MIT.
// ExtraStartingWorldOrCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraStartingWorldOrCellLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class TESForm;
class ExtraStartingWorldOrCellLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraStartingWorldOrCellLayout();
    TESForm* startingWorldOrCell;
};
static_assert(sizeof(ExtraStartingWorldOrCellLayout) == 24, "community represented size");
static_assert(offsetof(ExtraStartingWorldOrCellLayout, startingWorldOrCell) == 16, "startingWorldOrCell offset");
}
