// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// NiAVObject, NiNode, NiCollisionObject, bhkWorldObject, collisionObject, flags, VisitCollisionObjectTree: CRASHLOGGER_PDB(59818@2026.10.24)
// CollisionVisitorData, VisitCallback, NiAVObjectFlags, appCulled, selectiveUpdate, selectiveUpdateTransforms, selectiveUpdateController, selectiveUpdateRigid, rest, AsNode, GetWorldObject, recurse, skipFlagUpdate, children, childrenCapacity, childrenSize, Unk_01..Unk_11, unknown00, unknown09, unknown008, unknown048, unknown0F8: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class bhkWorldObject;
class NiNode;

struct CollisionVisitorData
{
    std::uint8_t  unknown00[0x8];  // 00
    bool          recurse;         // 08
    std::uint8_t  unknown09[0x3];  // 09
    std::uint32_t skipFlagUpdate;  // 0C
};
static_assert(offsetof(CollisionVisitorData, recurse) == 0x8, "recurse offset");
static_assert(offsetof(CollisionVisitorData, skipFlagUpdate) == 0xC, "skipFlagUpdate offset");

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
    virtual bhkWorldObject* GetWorldObject();  // 12
};

struct NiAVObjectFlags
{
    std::uint32_t appCulled : 1;
    std::uint32_t selectiveUpdate : 1;
    std::uint32_t selectiveUpdateTransforms : 1;
    std::uint32_t selectiveUpdateController : 1;
    std::uint32_t selectiveUpdateRigid : 1;
    std::uint32_t rest : 27;
};
static_assert(sizeof(NiAVObjectFlags) == 0x4, "NiAVObjectFlags size");

using VisitCallback = void (*)(bhkWorldObject*, CollisionVisitorData*);

class NiAVObject
{
public:
    virtual ~NiAVObject();     // 00
    virtual void    Unk_01();  // 01
    virtual void    Unk_02();  // 02
    virtual NiNode* AsNode();  // 03

    static void VisitCollisionObjectTree(
        NiAVObject* object,
        CollisionVisitorData* data,
        VisitCallback callback);

    std::uint8_t       unknown008[0x38];  // 008
    NiCollisionObject* collisionObject;   // 040
    std::uint8_t       unknown048[0xAC];  // 048
    NiAVObjectFlags    flags;             // 0F4
};
static_assert(offsetof(NiAVObject, collisionObject) == 0x40, "collisionObject offset");
static_assert(offsetof(NiAVObject, flags) == 0xF4, "flags offset");

class NiNode : public NiAVObject
{
public:
    std::uint8_t  unknown0F8[0x20];  // 0F8
    NiAVObject**  children;          // 118
    std::uint16_t childrenCapacity;  // 120
    std::uint16_t childrenSize;      // 122
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "childrenSize offset");
