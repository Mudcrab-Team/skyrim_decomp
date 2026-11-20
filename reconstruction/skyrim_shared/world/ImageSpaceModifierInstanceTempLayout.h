// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/ImageSpaceModifierInstanceTemp.h; MIT.
// ImageSpaceModifierInstanceTemp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstanceTempLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/world/ImageSpaceModifierInstanceLayout.h"

namespace ResearchLayouts {
class ImageSpaceModifierInstanceTempLayout : public ImageSpaceModifierInstanceLayout {
public:
    virtual ~ImageSpaceModifierInstanceTempLayout();
    float duration;
};
static_assert(sizeof(ImageSpaceModifierInstanceTempLayout) == 48, "community represented size");
static_assert(offsetof(ImageSpaceModifierInstanceTempLayout, duration) == 40, "duration offset");
}
