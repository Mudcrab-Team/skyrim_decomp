// Source exposure: mixed
// body: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); adapted body provenance only
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00da0000_od_o2_nood_variant.cpp:183
// Code origin: adapted from the cited sibling body; local names remain provisional
// Adapted bodies: Functionaaa4f0
// hkSimpleLocalFrame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaaa4f0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// FinishFlagaaa4f0, FinishMemberaaa4f0: GUESS(low) STANDIN; finishing-construction state
struct FinishFlagaaa4f0 { int finishing; };
struct FinishMemberaaa4f0 { FinishMemberaaa4f0(FinishFlagaaa4f0); unsigned value; };

__declspec(align(16)) class hkSimpleLocalFrame
{
public:
    hkSimpleLocalFrame(FinishFlagaaa4f0 flag) : member(flag) {}
    virtual void Unk00();
    std::uint8_t unknown08[0x68];
    FinishMemberaaa4f0 member;
    std::uint8_t unknown74[12];

    static const void* Functionaaa4f0();
};
