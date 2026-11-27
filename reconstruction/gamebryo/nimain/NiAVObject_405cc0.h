// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// NiAVObject, NiNode, bhkCollisionObject, bhkRigidBody, hkpRigidBody, CountRigidBodyMotionTypes: CRASHLOGGER_PDB(59818@2026.10.24)
// MotionTypeCounts, dynamicCount, fixedCount, keyframedCount, AsNode, GetCollisionObjectRef, GetRigidBody, referencedObject, motionType, children, childrenCapacity, childrenSize, Unk_01, Unk_02, unknown000, unknown00, unknown008: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct MotionTypeCounts
{
    std::uint32_t dynamicCount;    // 00
    std::uint32_t fixedCount;      // 04
    std::uint32_t keyframedCount;  // 08
};

struct hkpRigidBody
{
    std::uint8_t unknown000[0x160];  // 000
    std::uint8_t motionType;         // 160
};
static_assert(offsetof(hkpRigidBody, motionType) == 0x160, "motionType offset");

class bhkRigidBody
{
public:
    std::uint8_t  unknown00[0x10];   // 00
    hkpRigidBody* referencedObject;  // 10
};
static_assert(offsetof(bhkRigidBody, referencedObject) == 0x10, "referencedObject offset");

class bhkCollisionObject
{
public:
    bhkRigidBody* GetRigidBody() const;
};

class NiNode;

class NiAVObject
{
public:
    virtual ~NiAVObject();      // 00
    virtual void    Unk_01();   // 01
    virtual void    Unk_02();   // 02
    virtual NiNode* AsNode();   // 03

    bhkCollisionObject* GetCollisionObjectRef() const;
    static void CountRigidBodyMotionTypes(NiAVObject* object, MotionTypeCounts* counts);
};

class NiNode : public NiAVObject
{
public:
    std::uint8_t  unknown008[0x110];  // 008
    NiAVObject**  children;           // 118
    std::uint16_t childrenCapacity;   // 120
    std::uint16_t childrenSize;       // 122
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "childrenSize offset");
