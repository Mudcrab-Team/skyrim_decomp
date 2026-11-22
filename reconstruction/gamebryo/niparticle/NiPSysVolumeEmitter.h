// Source exposure: mixed (pinned image and cited public declarations).
// 0xfc0390 compared function
// 0xfc0340 compared function
// 0xfc0310 compared function
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysVolumeEmitter: GUESS(low)
// Class spelling follows the qualified Address Library names.
// LoadBinary, LinkObject, SaveBinary, NiPSysVolumeEmitter::~NiPSysVolumeEmitter: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// LoadBase, LinkBase, SaveBase, linkedObject: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysVolumeEmitter : public NiPSysModifier
{
public:
    NiPSysVolumeEmitter();
    ~NiPSysVolumeEmitter() override = default;
    void LoadBinary(NiStream& stream) override;
    void LinkObject(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    void LoadBase(NiStream& stream);
    void LinkBase(NiStream& stream);
    void SaveBase(NiStream& stream);
    std::uint8_t padding30[0x40];
    NiAVObject* linkedObject;
};
static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "measured allocation size");
