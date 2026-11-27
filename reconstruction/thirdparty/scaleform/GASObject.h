// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: local stand-ins (no ancestor has a shared header).
// GASObject, GASObjectInterface, GASStringContext, GASEnvironment, GASString, GASObject::Unk_00, GASObject::Unk_01, GASObject::~GASObject, GASObject::Unk_03, GASObject::Unk_04, GASObject::Unk_05, GASObject::Unk_06, GASObject::Unk_07, GASObject::Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GASObjectInterface::~GASObjectInterface, GASObjectInterface::GASObjectInterface_01, GASObjectInterface::GASObjectInterface_03, GASObjectInterface::GASObjectInterface_04, GASObjectInterface::GASObjectInterface_0B, GASObjectInterface::Set__proto__, GASObjectInterface::__proto__: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GRefCountBaseGC::Unk_00, GRefCountBaseGC::Unk_01, GRefCountBaseGC::~GRefCountBaseGC, GRefCountBaseGC::refCount, GASStringContext::globalContext, GASStringContext::version, GASEnvironment::sprite: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GNewOverrideBase, GRefCountBaseGC, GASRefCountBase, GFxSprite, GASGlobalContext: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GASObjectInterface::GetObjectType, GASObjectInterface::ToASCharacter, GASObjectInterface::ObjectType, GASObjectInterface::kObject_ASCharacter,GASEnvironment::stringContext, GASValue, a_env, a_name, a_value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class GASObject;
class GASGlobalContext;
class GASValue;
class GFxASCharacter;
class GFxSprite;
struct GASString;

class GASStringContext
{
public:
    GASGlobalContext* globalContext;  // 00
    std::uint8_t version;  // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
    std::uint64_t unk20;  // 20
    std::uint64_t unk28;  // 28
};
static_assert(sizeof(GASStringContext) == 0x30, "GASStringContext size");

class GASEnvironment
{
public:
    std::uint8_t unk000[0xE8];  // 000
    GFxSprite* sprite;  // 0E8
    GASStringContext stringContext;  // 0F0
    std::uint64_t unk120[16];  // 120
};
static_assert(offsetof(GASEnvironment, stringContext) == 0xF0, "GASEnvironment::stringContext offset");
static_assert(sizeof(GASEnvironment) == 0x1A0, "GASEnvironment size");

class GASObjectInterface
{
public:
    enum ObjectType
    {
        kObject_ASCharacter = 2
    };

    virtual ~GASObjectInterface();  // 00
    virtual void GASObjectInterface_01(void);  // 01
    virtual int GetObjectType() const;  // 02
    virtual void GASObjectInterface_03(void);  // 03
    virtual void GASObjectInterface_04(GASEnvironment* a_env, const GASString& a_name, GASValue* a_value);  // 04
    virtual void GASObjectInterface_05(void);  // 05
    virtual void GASObjectInterface_06(void);  // 06
    virtual void GASObjectInterface_07(void);  // 07
    virtual void GASObjectInterface_08(void);  // 08
    virtual void GASObjectInterface_09(void);  // 09
    virtual void GASObjectInterface_0A(void);  // 0A
    virtual void GASObjectInterface_0B(GASStringContext* a_stringContext, const GASString& a_name, GASValue* a_value);  // 0B
    virtual void GASObjectInterface_0C(void);  // 0C
    virtual void Set__proto__(GASStringContext* a_stringContext, GASObject* a_object);  // 0D
    virtual void GASObjectInterface_0E(void);  // 0E
    virtual void GASObjectInterface_0F(void);  // 0F
    virtual void GASObjectInterface_10(void);  // 10
    virtual void GASObjectInterface_11(void);  // 11
    virtual void GASObjectInterface_12(void);  // 12
    virtual void GASObjectInterface_13(void);  // 13
    virtual void GASObjectInterface_14(void);  // 14

    GFxASCharacter* ToASCharacter();

    std::uint64_t unk08;  // 08
    GASObject* __proto__;  // 10
};
static_assert(sizeof(GASObjectInterface) == 0x18, "GASObjectInterface size");

class GNewOverrideBase
{
public:
};

class GRefCountBaseGC : public GNewOverrideBase
{
public:
    virtual void Unk_00(void);  // 00
    virtual void Unk_01(void);  // 01
    virtual ~GRefCountBaseGC();  // 02

    void* unk08;  // 08
    std::uint32_t refCount;  // 10
    std::uint64_t unk18;  // 18
};
static_assert(sizeof(GRefCountBaseGC) == 0x20, "GRefCountBaseGC size");

class GASRefCountBase : public GRefCountBaseGC
{
public:
};

class GASObject : public GASRefCountBase, public GASObjectInterface
{
public:
    // override (GASRefCountBase)
    void Unk_00(void) override;  // 00
    void Unk_01(void) override;  // 01
    ~GASObject() override;  // 02

    // override (GASObjectInterface)
    void GASObjectInterface_04(GASEnvironment* a_env, const GASString& a_name, GASValue* a_value) override;  // 04
    void GASObjectInterface_0B(GASStringContext* a_stringContext, const GASString& a_name, GASValue* a_value) override;  // 0B
    void Set__proto__(GASStringContext* a_stringContext, GASObject* a_object) override;  // 0D

    // add
    virtual void Unk_03(void);  // 03
    virtual void Unk_04(void);  // 04
    virtual void Unk_05(void);  // 05
    virtual void Unk_06(void);  // 06
    virtual void Unk_07(void);  // 07
    virtual void Unk_08(void);  // 08

    std::uint64_t unk38;  // 38
    std::uint64_t unk40;  // 40
    std::uint64_t unk48;  // 48
    std::uint64_t unk50;  // 50
    std::uint64_t unk58;  // 58
    std::uint64_t unk60;  // 60
};
static_assert(offsetof(GASObject, unk38) == 0x38, "GASObject::unk38 offset");
static_assert(sizeof(GASObject) == 0x68, "GASObject size");
