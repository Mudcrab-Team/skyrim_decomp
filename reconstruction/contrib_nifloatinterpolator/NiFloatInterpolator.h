// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the community declarations and the pinned listing only; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf614b0 NiFloatInterpolator::IsEqual
// 0xf61760 NiFloatInterpolator::IsFloatValueSupported
// 0xf61810 NiFloatInterpolator::GetKeyType
// NiFloatInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiFloatInterpolator::IsEqual, NiFloatInterpolator::IsFloatValueSupported, NiFloatInterpolator::GetKeyType,
// NiFloatInterpolator::floatValue, NiFloatInterpolator::floatData, NiFloatInterpolator::lastTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject, NiObject::IsEqual, NiFloatData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// KeyType, KeyType::kNoInterp: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_00 through Unk_2B, Unk_2D through Unk_3B: GUESS(low); placeholder virtual slots that keep the named slots at slots 0x2C and 0x3C
// NiObject::Unk_00 through NiObject::Unk_1B: GUESS(low); placeholder virtual slots that keep NiObject::IsEqual at slot 0x1C
// unknown08, unknown0C, unknown14, unknown1C: GUESS(low); fields the listing does not read, kept so the read fields sit at their observed offsets
// NiFloatInterpolator::IsEqualBase: GUESS(low); the base-class comparison that NiFloatInterpolator::IsEqual chains to
#pragma once

#include <cstdint>

enum class KeyType : std::uint32_t
{
    kNoInterp = 0
};

// The object interface of the data a key-based interpolator points at. Only its vtable slot 0x1C is called here;
// no member of it is read, so the stand-in represents that interface and not its whole layout.
class NiObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual bool IsEqual(NiObject* a_object);  // 1C
};

class NiFloatData : public NiObject
{
};

class NiFloatInterpolator
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual bool IsEqual(NiObject* a_object);  // 1C
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual bool IsFloatValueSupported() const;  // 2C
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual KeyType GetKeyType(std::uint16_t a_channel) const;  // 3C

    // The base-class comparison this override chains to. Its body is out of line in the target image.
    bool IsEqualBase(NiObject* a_object);

    std::uint32_t unknown08;  // 08
    std::uint32_t unknown0C;  // 0C
    float         lastTime;   // 10
    std::uint32_t unknown14;  // 14
    float         floatValue; // 18
    std::uint32_t unknown1C;  // 1C
    NiFloatData*  floatData;  // 20
};
