// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of keyframe accessors. Stamped as a twin of matched 0x4324b0 (skyrim_shared/facegen/BSFaceGenKeyframeExclusive): source copied, names replaced by placeholders.
// Function121bdf0, Owner121bdf0: GUESS(low) STANDIN
// Unk_0D, pad08, field10, pad11, field14, Function4324c0, Function4324d0, Function432570, Function4324e0, Function432550: GUESS(low) STANDIN
#pragma once
#include "BSFaceGenKeyframeExclusive.h"

class Owner121bdf0
{
public:
    virtual std::uint8_t Unk_0D() const;
    float Function121bdf0() const;
    float Function4324c0() const;
    std::uint8_t Function4324d0() const;
    void Function432570(std::uint8_t a_value);
    bool Function4324e0() const;
    bool Function432550(float a_value);

    std::uint8_t pad08[0x8];  // 08
    std::uint8_t field10;  // 10
    std::uint8_t pad11[0x3];  // 11
    float field14;  // 14
};

