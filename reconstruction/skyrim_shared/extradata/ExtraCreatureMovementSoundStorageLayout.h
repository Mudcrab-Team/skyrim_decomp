// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraCreatureMovementSound.h; MIT.
// ExtraCreatureMovementSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraCreatureMovementSoundLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ExtraCreatureMovementSoundLayout.h.
// ExtraCreatureMovementSoundStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BSExtraDataStorageLayout.h"
#include "bsaudio/BSSoundHandleStorageLayout.h"

namespace ResearchLayouts {
class ExtraCreatureMovementSoundStorageLayout : public BSExtraDataStorageLayout {
public:
    virtual ~ExtraCreatureMovementSoundStorageLayout();
    BSSoundHandleStorageLayout handle;
};
static_assert(sizeof(ExtraCreatureMovementSoundStorageLayout) == 32, "community represented size");
static_assert(offsetof(ExtraCreatureMovementSoundStorageLayout, handle) == 16, "handle offset");
}
