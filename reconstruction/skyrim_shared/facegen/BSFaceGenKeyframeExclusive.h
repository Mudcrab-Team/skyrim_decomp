// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of keyframe accessors.
// Adapted bodies: none.
// BSFaceGenKeyframeExclusive: EXE_RTTI
// Unk_0D, pad08, field10, pad11, field14, Function4324b0, Function4324c0, Function4324d0, Function432570: GUESS(low)
#pragma once
#include <cstdint>

class BSFaceGenKeyframeExclusive
{
public:
    virtual std::uint8_t Unk_0D() const;
    float Function4324b0() const;
    float Function4324c0() const;
    std::uint8_t Function4324d0() const;
    void Function432570(std::uint8_t a_value);

    std::uint8_t pad08[0x8];  // 08
    std::uint8_t field10;  // 10
    std::uint8_t pad11[0x3];  // 11
    float field14;  // 14
};
