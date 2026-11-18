// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/N/NiObjectNET.h; MIT.
// NiObjectNET: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObjectNETLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/BSFixedStringLayout.h"
#include "netimmerse/NiObjectLayout.h"

namespace ResearchLayouts {
class NiExtraDataLayout;
class NiTimeController;
class NiObjectNETLayout : public NiObjectLayout {
public:
    virtual ~NiObjectNETLayout();
    BSFixedStringLayout name;
    NiPointerLayout<NiTimeController> controllers;
    NiExtraDataLayout** extra;
    std::uint16_t extraDataSize;
    std::uint16_t maxSize;
};
static_assert(sizeof(NiObjectNETLayout) == 48, "community represented size");
static_assert(offsetof(NiObjectNETLayout, name) == 16, "name offset");
static_assert(offsetof(NiObjectNETLayout, controllers) == 24, "controllers offset");
static_assert(offsetof(NiObjectNETLayout, extra) == 32, "extra offset");
static_assert(offsetof(NiObjectNETLayout, extraDataSize) == 40, "extraDataSize offset");
static_assert(offsetof(NiObjectNETLayout, maxSize) == 42, "maxSize offset");
}
