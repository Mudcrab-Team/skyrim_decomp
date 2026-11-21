// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the pinned listing and the cited public declarations only.
// Adapted bodies: none.
// BSNullImplGameSound: EXE_RTTI
// BSGameSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FunctionSlot00, unknown08..unknownC0, soundFlags, stateFlags, value74, value78, position: GUESS(low);
// names and offsets come from the pinned field accesses recorded in the sibling unit of this directory.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once

#include <cstdint>

// NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct NiPoint3
{
    float x;
    float y;
    float z;
};

// BSGameSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BSGameSound
{
public:
    virtual void FunctionSlot00();
    virtual ~BSGameSound();

protected:
    std::uint64_t unknown08;
    std::uint64_t unknown10;
    std::uint64_t unknown18;
    std::uint64_t unknown20;
    std::uint64_t unknown28;
    std::uint64_t unknown30;
    std::uint64_t unknown38;
    std::uint64_t unknown40;
    std::uint64_t unknown48;
    std::uint32_t soundFlags;
    std::uint32_t unknown54;
    std::uint32_t unknown58;
    std::uint32_t stateFlags;
    std::uint64_t unknown60;
    std::uint64_t unknown68;
    std::uint32_t unknown70;
    float value74;
    float value78;
    std::uint32_t unknown7C;
    std::uint64_t unknown80;
    std::uint64_t unknown88;
    std::uint64_t unknown90;
    std::uint64_t unknown98;
    std::uint64_t unknownA0;
    std::uint64_t unknownA8;
    std::uint64_t unknownB0;
    std::uint64_t unknownB8;
    std::uint64_t unknownC0;
};
static_assert(sizeof(BSGameSound) == 0xC8, "game sound prefix size");

// BSNullImplGameSound: EXE_RTTI
class BSNullImplGameSound : public BSGameSound
{
public:
    virtual std::uint8_t Unk_08() const;
    BSNullImplGameSound* Functioncd6c10(std::uint32_t a_flags);

private:
    NiPoint3 position;
};
static_assert(sizeof(BSNullImplGameSound) == 0xD8, "null game sound size");
