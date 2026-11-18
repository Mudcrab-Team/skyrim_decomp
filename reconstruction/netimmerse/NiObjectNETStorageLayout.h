// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiObjectNET.h; MIT.
// NiObjectNET: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObjectNETLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/netimmerse/NiObjectNETLayout.h.
// NiObjectNETStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../bsengine/BSFixedStringStorageLayout.h"
#include "NiObjectStorageLayout.h"

namespace ResearchLayouts {
class NiExtraDataStorageLayout;
class NiTimeController;
class NiObjectNETStorageLayout : public NiObjectStorageLayout {
public:
    virtual ~NiObjectNETStorageLayout();
    BSFixedStringStorageLayout name;
    NiPointerStorageLayout<NiTimeController> controllers;
    NiExtraDataStorageLayout** extra;
    std::uint16_t extraDataSize;
    std::uint16_t maxSize;
};
static_assert(sizeof(NiObjectNETStorageLayout) == 48, "community represented size");
static_assert(offsetof(NiObjectNETStorageLayout, name) == 16, "name offset");
static_assert(offsetof(NiObjectNETStorageLayout, controllers) == 24, "controllers offset");
static_assert(offsetof(NiObjectNETStorageLayout, extra) == 32, "extra offset");
static_assert(offsetof(NiObjectNETStorageLayout, extraDataSize) == 40, "extraDataSize offset");
static_assert(offsetof(NiObjectNETStorageLayout, maxSize) == 42, "maxSize offset");
}
