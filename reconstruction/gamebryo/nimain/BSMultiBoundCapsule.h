// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing unit plus original reconstruction of constructor, destructor, and radius getter.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSMultiBoundCapsule, BSMultiBoundShape, NiRefObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// GetType, BoundCapsuleTarget, BoundCapsuleArg, Function1002760, Function1002880, g_niRefObjectCount, unk08, shapeData, centerData, radius, pad34, unknown00, target: GUESS(low)
#pragma once
#include <cstdint>
#include <intrin.h>

extern volatile long g_niRefObjectCount;

class NiRefObject
{
public:
    virtual ~NiRefObject()
    {
        // Reference-counted engine objects track live instance counts atomically.
        _InterlockedDecrement(&g_niRefObjectCount);
    }
    std::uint8_t unk08[0x8];  // 08
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class BSMultiBoundShape : public NiRefObject
{
public:
    BSMultiBoundShape();
    ~BSMultiBoundShape() override = default;
    std::uint8_t shapeData[0x8];  // 10
};
static_assert(sizeof(BSMultiBoundShape) == 0x18, "BSMultiBoundShape size");

class BoundCapsuleTarget
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
};

struct BoundCapsuleArg
{
    std::uint8_t unknown00[0x18];
    BoundCapsuleTarget* target;
};

class BSMultiBoundCapsule : public BSMultiBoundShape
{
public:
    BSMultiBoundCapsule();
    ~BSMultiBoundCapsule() override = default;
    virtual std::uint32_t GetType() const;
    std::uint32_t Function1002760(BoundCapsuleArg* a_arg);
    float Function1002880() const;

    std::uint64_t centerData[3];  // 18
    float radius;  // 30
    std::uint32_t pad34;  // 34
};
static_assert(sizeof(BSMultiBoundCapsule) == 0x38, "BSMultiBoundCapsule size");
