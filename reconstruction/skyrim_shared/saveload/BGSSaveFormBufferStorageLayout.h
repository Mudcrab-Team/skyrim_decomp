// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSSaveFormBuffer.h; MIT.
// BGSSaveFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSaveFormBufferLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/forms/BGSSaveFormBufferLayout.h.
// BGSSaveFormBufferStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "BGSSaveGameBufferStorageLayout.h"

namespace ResearchLayouts {
class TESForm;
class BGSSaveFormBufferStorageLayout : public BGSSaveGameBufferStorageLayout {
public:
    virtual ~BGSSaveFormBufferStorageLayout();
    std::uint64_t unk18;
    std::uint64_t unk20;
    TESForm* form;
};
static_assert(sizeof(BGSSaveFormBufferStorageLayout) == 48, "community represented size");
static_assert(offsetof(BGSSaveFormBufferStorageLayout, unk18) == 24, "unk18 offset");
static_assert(offsetof(BGSSaveFormBufferStorageLayout, unk20) == 32, "unk20 offset");
static_assert(offsetof(BGSSaveFormBufferStorageLayout, form) == 40, "form offset");
}
