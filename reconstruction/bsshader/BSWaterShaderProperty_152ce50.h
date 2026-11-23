// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWaterShaderProperty, BSWaterShaderProperty::ForEachTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSShaderProperty, BSShaderProperty::ForEachVisitor, BSShaderProperty::ForEachVisitor::~ForEachVisitor, BSShaderProperty::ForEachVisitor::Accept, BSShaderProperty::material, BSShaderMaterial, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSWaterShaderProperty::~BSWaterShaderProperty, vslot01, vslot02, vslot03, vslot04, vslot05, vslot06, vslot07, vslot08, vslot09, vslot0A, vslot0B, vslot0C, vslot0D, vslot0E, vslot0F, vslot10, vslot11, vslot12, vslot13, vslot14, vslot15, vslot16, vslot17, vslot18, vslot19, vslot1A, vslot1B, vslot1C, vslot1D, vslot1E, vslot1F, vslot20, vslot21, vslot22, vslot23, vslot24, vslot25, vslot26, vslot27, vslot28, vslot29, vslot2A, vslot2B, vslot2C, vslot2D, vslot2E, vslot2F, vslot30, vslot31, vslot32, propertyPad, materialPad, unk40, unk48, unk50, GetTexture2, GetTexture3: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiSourceTexture;

class BSShaderMaterial
{
public:
    NiSourceTexture* GetTexture2() const { return unk48; }
    NiSourceTexture* GetTexture3() const { return unk50; }

    unsigned char materialPad[0x40];  // 00
    NiSourceTexture* unk40;  // 40
    NiSourceTexture* unk48;  // 48
    NiSourceTexture* unk50;  // 50
};
static_assert(offsetof(BSShaderMaterial, unk40) == 0x40, "unk40 offset");

class BSShaderProperty
{
public:
    class ForEachVisitor
    {
    public:
        virtual ~ForEachVisitor();  // 00
        virtual std::uint32_t Accept(NiSourceTexture* a_texture) = 0;  // 01
    };
};

class BSWaterShaderProperty
{
public:
    using ForEachVisitor = BSShaderProperty::ForEachVisitor;

    virtual ~BSWaterShaderProperty();  // 00
    virtual void vslot01();  // 01
    virtual void vslot02();  // 02
    virtual void vslot03();  // 03
    virtual void vslot04();  // 04
    virtual void vslot05();  // 05
    virtual void vslot06();  // 06
    virtual void vslot07();  // 07
    virtual void vslot08();  // 08
    virtual void vslot09();  // 09
    virtual void vslot0A();  // 0A
    virtual void vslot0B();  // 0B
    virtual void vslot0C();  // 0C
    virtual void vslot0D();  // 0D
    virtual void vslot0E();  // 0E
    virtual void vslot0F();  // 0F
    virtual void vslot10();  // 10
    virtual void vslot11();  // 11
    virtual void vslot12();  // 12
    virtual void vslot13();  // 13
    virtual void vslot14();  // 14
    virtual void vslot15();  // 15
    virtual void vslot16();  // 16
    virtual void vslot17();  // 17
    virtual void vslot18();  // 18
    virtual void vslot19();  // 19
    virtual void vslot1A();  // 1A
    virtual void vslot1B();  // 1B
    virtual void vslot1C();  // 1C
    virtual void vslot1D();  // 1D
    virtual void vslot1E();  // 1E
    virtual void vslot1F();  // 1F
    virtual void vslot20();  // 20
    virtual void vslot21();  // 21
    virtual void vslot22();  // 22
    virtual void vslot23();  // 23
    virtual void vslot24();  // 24
    virtual void vslot25();  // 25
    virtual void vslot26();  // 26
    virtual void vslot27();  // 27
    virtual void vslot28();  // 28
    virtual void vslot29();  // 29
    virtual void vslot2A();  // 2A
    virtual void vslot2B();  // 2B
    virtual void vslot2C();  // 2C
    virtual void vslot2D();  // 2D
    virtual void vslot2E();  // 2E
    virtual void vslot2F();  // 2F
    virtual void vslot30();  // 30
    virtual void vslot31();  // 31
    virtual void vslot32();  // 32
    virtual std::int32_t ForEachTexture(ForEachVisitor& a_visitor);  // 33; compared: 0x152ce50

    unsigned char propertyPad[0x70];  // 08
    BSShaderMaterial* material;  // 78
};
static_assert(offsetof(BSWaterShaderProperty, material) == 0x78, "material offset");
