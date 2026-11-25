// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of keyframe accessors. Stamped as a twin of matched 0x432570 (skyrim_shared/facegen/BSFaceGenKeyframeExclusive): source copied, names replaced by placeholders.
// Function7b4e40, Owner7b4e40: GUESS(low) STANDIN
// Unk_0D, pad08, field10, pad11, field14, Function4324b0, Function4324c0, Function4324d0, Function4324e0, Function432550: GUESS(low) STANDIN
#pragma once
#include "BSFaceGenKeyframeExclusive.h"

class Owner7b4e40
{
public:
    virtual std::uint8_t Unk_0D() const;
    float Function4324b0() const;
    float Function4324c0() const;
    std::uint8_t Function4324d0() const;
    void Function7b4e40(std::uint8_t a_value);
    bool Function4324e0() const;
    bool Function432550(float a_value);

    std::uint8_t pad08[0x8];  // 08
    std::uint8_t field10;  // 10
    std::uint8_t pad11[0x3];  // 11
    float field14;  // 14
};

