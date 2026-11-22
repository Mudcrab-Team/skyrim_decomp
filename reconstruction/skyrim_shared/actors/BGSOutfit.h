// Origin: original reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BGSOutfit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSOutfit::ClearData, BGSOutfit::~BGSOutfit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"

// OutfitArray, OutfitTLS, OutfitScope, ClearOutfitArray, ResetOutfitCount, ReleaseOutfitArray,
// data, capacity, pad0C, count, pad14, saved: GUESS(low); represented heap-array and TLS ownership.
void ClearOutfitArray(void*);
void ResetOutfitCount(std::uint32_t*);
void ReleaseOutfitArray(void*);
struct OutfitArray {
    ~OutfitArray() {
        if (data) { ClearOutfitArray(this); count = 0; }
        ResetOutfitCount(&count);
        ReleaseOutfitArray(this);
    }
    void* data;
    std::uint32_t capacity, pad0C, count, pad14;
};
static_assert(sizeof(OutfitArray)==0x18, "outfit array size");
class BGSOutfit : public TESForm
{
public:
    BGSOutfit();
    virtual void ClearData();  // compared: 0x264820
    OutfitArray items;
    virtual ~BGSOutfit();  // compared: 0x264d80 (scalar deleting destructor)
};
