// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// NiAVObject, NiNode, NiCollisionObject, NiUpdateData, collisionObject, UpdateWorldBound, UpdateWorldData, UpdateActiveCollisionTransformRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// AsNode, GetWorldObject, RecalculateWorldTransform, time, flags, children, childrenCapacity, childrenSize, Unk_01..Unk_2E, unknown008, unknown048: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct NiUpdateData
{
    float         time;   // 00
    std::uint32_t flags;  // 04
};
static_assert(sizeof(NiUpdateData) == 0x8, "NiUpdateData size");

class NiCollisionObject
{
public:
    virtual ~NiCollisionObject();  // 00
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
    virtual void* GetWorldObject();  // 12
};

class NiNode;

class NiAVObject
{
public:
    virtual ~NiAVObject();     // 00
    virtual void    Unk_01();  // 01
    virtual void    Unk_02();  // 02
    virtual NiNode* AsNode();  // 03
    virtual void    Unk_04();
    virtual void    Unk_05();
    virtual void    Unk_06();
    virtual void    Unk_07();
    virtual void    Unk_08();
    virtual void    Unk_09();
    virtual void    Unk_0A();
    virtual void    Unk_0B();
    virtual void    Unk_0C();
    virtual void    Unk_0D();
    virtual void    Unk_0E();
    virtual void    Unk_0F();
    virtual void    Unk_10();
    virtual void    Unk_11();
    virtual void    Unk_12();
    virtual void    Unk_13();
    virtual void    Unk_14();
    virtual void    Unk_15();
    virtual void    Unk_16();
    virtual void    Unk_17();
    virtual void    Unk_18();
    virtual void    Unk_19();
    virtual void    Unk_1A();
    virtual void    Unk_1B();
    virtual void    Unk_1C();
    virtual void    Unk_1D();
    virtual void    Unk_1E();
    virtual void    Unk_1F();
    virtual void    Unk_20();
    virtual void    Unk_21();
    virtual void    Unk_22();
    virtual void    Unk_23();
    virtual void    Unk_24();
    virtual void    Unk_25();
    virtual void    Unk_26();
    virtual void    Unk_27();
    virtual void    Unk_28();
    virtual void    Unk_29();
    virtual void    Unk_2A();
    virtual void    Unk_2B();
    virtual void    Unk_2C();
    virtual void    Unk_2D();
    virtual void    Unk_2E();
    virtual void    UpdateWorldBound();                 // 2F
    virtual void    UpdateWorldData(NiUpdateData* data);  // 30

    void RecalculateWorldTransform();
    static void UpdateActiveCollisionTransformRecursive(NiAVObject* object, bool forceUpdate);

    std::uint8_t       unknown008[0x38];  // 008
    NiCollisionObject* collisionObject;   // 040
};
static_assert(offsetof(NiAVObject, collisionObject) == 0x40, "collisionObject offset");

class NiNode : public NiAVObject
{
public:
    std::uint8_t  unknown048[0xD0];  // 048
    NiAVObject**  children;          // 118
    std::uint16_t childrenCapacity;  // 120
    std::uint16_t childrenSize;      // 122
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "childrenSize offset");
