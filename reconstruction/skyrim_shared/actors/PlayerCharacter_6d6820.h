// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the caster array the body reads
// PlayerCharacter::magicCasters, PlayerCharacter::SlotTypes, kLeftHand, kRightHand, kUnknown, kPowerOrShout, kTotal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared on Actor there
// PlayerCharacter::Function6d6820: GUESS(low); returns a bit per casting source that has a current spell
// MagicCaster: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicCaster::GetCastingSource, MagicCaster::currentSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the return type is a plain integer here
// MagicCaster::Unk_00 to Unk_14, MagicCaster::unknown08, PlayerCharacter::unknown00: GUESS(low)
// CasterSlot, CasterSlot::index, CasterRef, CasterRef::caster: GUESS(low); class-type locals for the slot index and the current caster.
// The image ranks the index above the array cursor and below the caster, which this compiler only does when both are class-type locals.
// MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class MagicItem;

class MagicCaster
{
public:
    virtual void Unk_00();  // 00
    virtual void Unk_01();  // 01
    virtual void Unk_02();  // 02
    virtual void Unk_03();  // 03
    virtual void Unk_04();  // 04
    virtual void Unk_05();  // 05
    virtual void Unk_06();  // 06
    virtual void Unk_07();  // 07
    virtual void Unk_08();  // 08
    virtual void Unk_09();  // 09
    virtual void Unk_0A();  // 0A
    virtual void Unk_0B();  // 0B
    virtual void Unk_0C();  // 0C
    virtual void Unk_0D();  // 0D
    virtual void Unk_0E();  // 0E
    virtual void Unk_0F();  // 0F
    virtual void Unk_10();  // 10
    virtual void Unk_11();  // 11
    virtual void Unk_12();  // 12
    virtual void Unk_13();  // 13
    virtual void Unk_14();  // 14
    virtual std::int32_t GetCastingSource() const;  // 15

    std::uint8_t unknown08[0x20];  // 08
    MagicItem* currentSpell;       // 28
};

struct CasterSlot
{
    std::int32_t index;  // 0
};

struct CasterRef
{
    MagicCaster* caster;  // 0
};

class PlayerCharacter
{
public:
    struct SlotTypes
    {
        enum
        {
            kLeftHand = 0,
            kRightHand,
            kUnknown,
            kPowerOrShout,

            kTotal
        };
    };

    std::uint8_t Function6d6820();  // compared: 0x6d6820

    std::uint8_t unknown00[0x1A8];                  // 000
    MagicCaster* magicCasters[SlotTypes::kTotal];   // 1A8
};
