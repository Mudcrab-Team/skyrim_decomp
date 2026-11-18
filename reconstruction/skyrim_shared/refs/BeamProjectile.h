// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BeamProjectile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Projectile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); pads the base to 0x240, the offset of the member the compared code writes
// BeamProjectile::Revert, BeamProjectile::SaveGame: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Projectile::Revert, Projectile::SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); called non-virtually by the compared code
// BGSSaveGameBuffer::SaveDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only, four target arguments are declared in its shared header
// unk240: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "../saveload/BGSSaveFormBuffer.h"

class BGSLoadFormBuffer;

class Projectile : public TESObjectREFR
{
public:
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // compared base call: 0x7fbcf0
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // compared base call: 0x7fb000

    std::uint8_t unkBase[0x240 - sizeof(TESObjectREFR)];  // pads to the member at 0x240
};

class BeamProjectile : public Projectile
{
public:
    virtual std::uint8_t Slot165() const;
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // compared: 0x7e03e0
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // compared: 0x7e0320

    std::uint8_t unk240;  // 240
};
