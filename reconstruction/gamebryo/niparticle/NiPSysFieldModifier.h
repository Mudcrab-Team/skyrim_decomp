// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysFieldModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// LinkObject, NiPSysFieldModifier::~NiPSysFieldModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiPoint3, x, y, z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LoadTriple, SaveTriple: GUESS(low)
// linkedObject: GUESS(low)
// CompareFields: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPoint3
{
public:
    void LoadTriple(NiStream& stream);
    void SaveTriple(NiStream& stream);

    float x, y, z;
};

class NiPSysFieldModifier : public NiPSysModifier
{
public:
    NiPSysFieldModifier();
    ~NiPSysFieldModifier() override = default;
    void LinkObject(NiStream& stream) override;
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
protected:
    std::uint8_t CompareFields(NiObject* other);

private:
    NiAVObject* linkedObject;
    std::uint8_t padding38[0x18];
};
static_assert(sizeof(NiPSysFieldModifier) == 0x50, "measured allocation size");
