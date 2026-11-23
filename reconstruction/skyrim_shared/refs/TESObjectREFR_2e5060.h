// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR, TESWorldSpace, formFlags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::GetWorldSpace: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESObjectREFR::CanUseWorldSpace, unk00: GUESS(low)
#pragma once

#include <cstdint>

class TESWorldSpace;

class TESObjectREFR
{
public:
    static bool CanUseWorldSpace(const TESObjectREFR* a_ref, const TESWorldSpace* a_world);
    TESWorldSpace* GetWorldSpace() const;

    std::uint8_t unk00[0x10];
    std::uint32_t formFlags;
};
