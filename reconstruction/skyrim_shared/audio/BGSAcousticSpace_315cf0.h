// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAcousticSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Clone3D, BGSAcousticSpace::~BGSAcousticSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundObject, NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class NiAVObject;

class TESBoundObject : public TESForm
{
public:
    ~TESBoundObject() override;
};

class BGSAcousticSpace : public TESBoundObject
{
public:
    BGSAcousticSpace();
    virtual NiAVObject* Clone3D(TESObjectREFR*);
    ~BGSAcousticSpace() override;

private:
    std::uint8_t padding20[0x28];
};
static_assert(sizeof(BGSAcousticSpace) == 0x48, "observed allocation size");
