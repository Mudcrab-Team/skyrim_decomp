// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject::IsOcclusionMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_occlusionMarkerA, g_occlusionMarkerB, g_occlusionMarkerC: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESWaterForm;

// TESObject::DecRef, TESObject::GetRefCount, TESObject::GetWaterType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0x146640, 0x146810, 0x146840
class TESObject : public TESForm
{
public:
    virtual bool IsOcclusionMarker();  // compared: 0x275ee0
    virtual std::uint32_t DecRef();  // compared: 0x146640
    virtual std::uint32_t GetRefCount() const;  // compared: 0x146810
    virtual TESWaterForm* GetWaterType() const;  // compared: 0x146840
};

extern TESObject* g_occlusionMarkerA;
extern TESObject* g_occlusionMarkerB;
extern TESObject* g_occlusionMarkerC;
