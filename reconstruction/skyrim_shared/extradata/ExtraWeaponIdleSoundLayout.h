// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraWeaponIdleSound.h; MIT.
// ExtraWeaponIdleSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraWeaponIdleSoundLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"
#include "bsaudio/BSSoundHandleLayout.h"

namespace ResearchLayouts {
class ExtraWeaponIdleSoundLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraWeaponIdleSoundLayout();
    BSSoundHandleLayout handle;
};
static_assert(sizeof(ExtraWeaponIdleSoundLayout) == 32, "community represented size");
static_assert(offsetof(ExtraWeaponIdleSoundLayout, handle) == 16, "handle offset");
}
