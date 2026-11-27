// Source exposure: mixed (community headers; compared functions from the pinned image; permitted siblings).
// Code origin: declarations and body shape adapted from permitted siblings and community headers, offsets, flag bits and slots checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueOwner, ActorValueOwner::~ActorValueOwner, ActorValueOwner::GetActorValue, ActorValueOwner::GetPermanentActorValue, ActorValueOwner::GetBaseActorValue, ActorValueOwner::SetBaseActorValue, ActorValueOwner::ModActorValue, ActorValueOwner::RestoreActorValue, ActorValueOwner::SetActorValue, ActorValueOwner::GetIsPlayerOwner, ActorValueOwner::GetClampedActorValue, ActorValue, ACTOR_VALUE_MODIFIER: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueInfo, ActorValueInfo::flags, ActorValueList, ActorValueList::actorValues: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the compared function reads
// ActorValueInfo::ClampActorValue: SIBLING(fo4-private@1b765c70, author-permission); the name and the member form, the flag logic follows the Fallout: New Vegas clamp below
// ActorValueList::singleton: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; a static pointer here, NG reads it through a relocation
// Min, Max, TestBit, unknown00: GUESS(low); Min and Max are by-value float helpers spelled as in the siblings, TestBit is a flag-word bit test by index (cookbook rule 16)
// Adapted bodies: Min, Max, TestBit, ActorValueInfo::ClampActorValue (statement shape of the sibling clamp)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00500000_o2.cpp:29680
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:7509
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/font.cpp:2686
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/actorvalue.cpp:196
// Sibling source: fo4-private@1b765c70 src/Shared/AI/ActorValueOwner.cpp:12
#pragma once

#include <cstdint>

enum class ActorValue : std::int32_t
{
    kNone = -1
};

enum class ACTOR_VALUE_MODIFIER : std::int32_t
{
    kPermanent = 0
};

// A flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

inline float Min(float a_lhs, float a_rhs)
{
    return a_lhs < a_rhs ? a_lhs : a_rhs;
}

inline float Max(float a_lhs, float a_rhs)
{
    return a_lhs > a_rhs ? a_lhs : a_rhs;
}

class ActorValueInfo
{
public:
    // Bit 4 clamps to 0..100; bit 3 clamps to 0 or 1 (bit 2) .. 10; otherwise the value is unchanged.
    float ClampActorValue(float a_value) const
    {
        float result = a_value;
        if (TestBit(flags, 4)) {
            result = Max(Min(result, 100.0f), 0.0f);
        } else if (TestBit(flags, 3)) {
            float minimum = TestBit(flags, 2) ? 1.0f : 0.0f;
            result = Max(Min(result, 10.0f), minimum);
        }
        return result;
    }

    std::uint8_t unknown00[0x60];  // 00
    std::uint32_t flags;           // 60
};

class ActorValueList
{
public:
    static ActorValueList* singleton;

    std::uint64_t unknown00;         // 00
    ActorValueInfo* actorValues[1];  // 08
};

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();  // 00
    virtual float GetActorValue(ActorValue a_akValue);  // 01
    virtual float GetPermanentActorValue(ActorValue a_akValue);  // 02
    virtual float GetBaseActorValue(ActorValue a_akValue);  // 03
    virtual void SetBaseActorValue(ActorValue a_akValue, float a_value);  // 04
    virtual void ModActorValue(ActorValue a_akValue, float a_value);  // 05
    virtual void RestoreActorValue(ACTOR_VALUE_MODIFIER a_modifier, ActorValue a_akValue, float a_value);  // 06
    virtual void SetActorValue(ActorValue a_akValue, float a_value);  // 07
    virtual bool GetIsPlayerOwner() const;  // 08

    float GetClampedActorValue(ActorValue a_akValue);
};
static_assert(sizeof(ActorValueOwner) == 0x8, "ActorValueOwner size");
