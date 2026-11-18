// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/R/ReadyWeaponHandler.h; MIT.
// ReadyWeaponHandler: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ReadyWeaponHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "actors/PlayerInputHandlerLayout.h"

namespace ResearchLayouts {
class ReadyWeaponHandlerLayout : public PlayerInputHandlerLayout {
public:
    virtual ~ReadyWeaponHandlerLayout();
};
static_assert(sizeof(ReadyWeaponHandlerLayout) == 16, "community represented size");
}
