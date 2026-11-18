// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCreatureMovementSound.h; MIT.
// ExtraCreatureMovementSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCreatureMovementSoundLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"
#include "bsaudio/BSSoundHandleLayout.h"

namespace ResearchLayouts {
class ExtraCreatureMovementSoundLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraCreatureMovementSoundLayout();
    BSSoundHandleLayout handle;
};
static_assert(sizeof(ExtraCreatureMovementSoundLayout) == 32, "community represented size");
static_assert(offsetof(ExtraCreatureMovementSoundLayout, handle) == 16, "handle offset");
}
