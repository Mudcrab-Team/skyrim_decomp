// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraLock.h; MIT.
// ExtraLock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraLockLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/extradata/BSExtraDataLayout.h"

namespace ResearchLayouts {
class REFR_LOCK;
class ExtraLockLayout : public BSExtraDataLayout {
public:
    virtual ~ExtraLockLayout();
    REFR_LOCK* lock;
};
static_assert(sizeof(ExtraLockLayout) == 24, "community represented size");
static_assert(offsetof(ExtraLockLayout, lock) == 16, "lock offset");
}
