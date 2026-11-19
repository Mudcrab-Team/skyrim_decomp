// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x15271f0 BSLightingShaderMaterialHairTint::SaveBinary
// 0x1527230 BSLightingShaderMaterialHairTint::LoadBinary
// BSLightingShaderMaterialHairTint: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialBase: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialHairTint::SaveBinary, BSLightingShaderMaterialHairTint::LoadBinary, BSLightingShaderMaterialBase::SaveBinary, BSLightingShaderMaterialBase::LoadBinary, BSLightingShaderMaterialHairTint::tintColor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream, NiColor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiStream is a forward declaration only
// NiColor::SaveBinary2, NiColor::LoadBinary2: GUESS(low); the image calls helpers taking the stream, the colour at this+0xA0 being the object
// Unk_00 through Unk_0B: GUESS(low); placeholder virtual slots that keep SaveBinary and LoadBinary at slots 0x0C and 0x0D
// pad08 through pad98: GUESS(low); unexamined 8-byte members of the base that keep tintColor at 0xA0
#pragma once

#include <cstdint>

class NiStream;

class NiColor
{
public:
    void SaveBinary2(NiStream& a_stream) const;
    void LoadBinary2(NiStream& a_stream);

    float red;
    float green;
    float blue;
};

class BSLightingShaderMaterialBase
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
    virtual void SaveBinary(NiStream& a_stream);  // 0C
    virtual void LoadBinary(NiStream& a_stream);  // 0D

    std::uint64_t pad08;
    std::uint64_t pad10;
    std::uint64_t pad18;
    std::uint64_t pad20;
    std::uint64_t pad28;
    std::uint64_t pad30;
    std::uint64_t pad38;
    std::uint64_t pad40;
    std::uint64_t pad48;
    std::uint64_t pad50;
    std::uint64_t pad58;
    std::uint64_t pad60;
    std::uint64_t pad68;
    std::uint64_t pad70;
    std::uint64_t pad78;
    std::uint64_t pad80;
    std::uint64_t pad88;
    std::uint64_t pad90;
    std::uint64_t pad98;
};

class BSLightingShaderMaterialHairTint : public BSLightingShaderMaterialBase
{
public:
    void SaveBinary(NiStream& a_stream) override;  // compared: 0x15271f0
    void LoadBinary(NiStream& a_stream) override;  // compared: 0x1527230

    NiColor tintColor;  // A0
};
