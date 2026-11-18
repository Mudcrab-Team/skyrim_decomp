// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/ImageSpaceModifierInstanceTemp.h; MIT.
// ImageSpaceModifierInstanceTemp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstanceTempLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ImageSpaceModifierInstanceTempLayout.h.
// ImageSpaceModifierInstanceTempStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "ImageSpaceModifierInstanceStorageLayout.h"

namespace ResearchLayouts {
class ImageSpaceModifierInstanceTempStorageLayout : public ImageSpaceModifierInstanceStorageLayout {
public:
    virtual ~ImageSpaceModifierInstanceTempStorageLayout();
    float duration;
};
static_assert(sizeof(ImageSpaceModifierInstanceTempStorageLayout) == 48, "community represented size");
static_assert(offsetof(ImageSpaceModifierInstanceTempStorageLayout, duration) == 40, "duration offset");
}
