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
// NiPSysEmitter: STANDIN GUESS(low); base name from the particle emitter hierarchy; its 0x40 bytes after NiPSysModifier are unnamed fields
// Functionf9fa60: GUESS(low); setter for linkedObject (0x70)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysEmitter : public NiPSysModifier
{
public:
    // Unnamed emitter fields (speed, declination, colour, radius, life span and similar), offsets 0x30-0x70.
    std::uint8_t unk30[0x40];  // 30
};
static_assert(sizeof(NiPSysEmitter) == 0x70, "NiPSysModifier plus the emitter fields");

class NiPSysVolumeEmitter : public NiPSysEmitter
{
public:
    NiPSysVolumeEmitter();
    ~NiPSysVolumeEmitter() override = default;
    void LoadBinary(NiStream& stream) override;
    void LinkObject(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    void Functionf9fa60(NiAVObject* a_object);

private:
    void LoadBase(NiStream& stream);
    void LinkBase(NiStream& stream);
    void SaveBase(NiStream& stream);
    NiAVObject* linkedObject;  // 70
};
static_assert(sizeof(NiPSysVolumeEmitter) == 0x78, "measured allocation size");
