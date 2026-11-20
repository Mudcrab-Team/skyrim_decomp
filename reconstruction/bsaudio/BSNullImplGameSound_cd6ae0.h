// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the partial BSGameSound prefix follows the cited base declaration and pinned field accesses.
// BSNullImplGameSound: EXE_RTTI
// BSGameSound: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function declarations, FunctionSlot00, soundFlags, stateFlags, value74, value78, padding, position: GUESS(low)
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class BSGameSound
{
public:
    virtual void FunctionSlot00();
    virtual ~BSGameSound();

protected:
    void Functioncd5af0();

    std::uint8_t padding08[0x48];
    std::uint32_t soundFlags;
    std::uint8_t padding54[8];
    std::uint32_t stateFlags;
    std::uint8_t padding60[0x14];
    float value74;
    float value78;
    std::uint8_t padding7C[0x4C];
};
static_assert(sizeof(BSGameSound) == 0xC8, "game sound prefix size");

class BSNullImplGameSound : public BSGameSound
{
public:
    bool Functioncd6ae0();
    void Functioncd6b10(const NiPoint3& value);
    void Functioncd6b40(NiPoint3& value) const;
    void Functioncd6b70(float first, float second);
    void Functioncd6be0();

private:
    NiPoint3 position;
};
