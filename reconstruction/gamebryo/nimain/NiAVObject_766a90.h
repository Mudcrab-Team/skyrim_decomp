// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports IsKindOf, NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// NiAVObject, NiNode, NiCollisionObject, bhkBlendCollisionObject, NiRTTI, collisionObject, GetRTTI, SetBlendCollisionFieldRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRTTI_bhkBlendCollisionObject, name, baseRTTI, AsNode, GetAt, field38, children, childrenCapacity, childrenSize, IsKindOf, CastToBlendCollisionObject, BSVisitControl, kContinue, kStop, TraverseScenegraphObjects, SetBlendCollisionFieldVisitor, value, Unk_01, Unk_02, unknown008, unknown048: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct NiRTTI
{
    const char* name;      // 00
    NiRTTI*     baseRTTI;  // 08
};

extern NiRTTI NiRTTI_bhkBlendCollisionObject;

class NiCollisionObject
{
public:
    virtual ~NiCollisionObject();     // 00
    virtual void    Unk_01();         // 01
    virtual NiRTTI* GetRTTI() const;  // 02
};

class bhkBlendCollisionObject : public NiCollisionObject
{
public:
    std::uint8_t  unknown008[0x30];  // 008
    std::uint64_t field38;           // 038
};
static_assert(offsetof(bhkBlendCollisionObject, field38) == 0x38, "field38 offset");

class NiNode;

class NiAVObject
{
public:
    virtual ~NiAVObject();     // 00
    virtual void    Unk_01();  // 01
    virtual void    Unk_02();  // 02
    virtual NiNode* AsNode();  // 03

    std::uint8_t       unknown008[0x38];  // 008
    NiCollisionObject* collisionObject;   // 040
};
static_assert(offsetof(NiAVObject, collisionObject) == 0x40, "collisionObject offset");

class NiNode : public NiAVObject
{
public:
    NiAVObject* GetAt(std::uint32_t index) const { return children[index]; }

    std::uint8_t  unknown048[0xD0];  // 048
    NiAVObject**  children;          // 118
    std::uint16_t childrenCapacity;  // 120
    std::uint16_t childrenSize;      // 122
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "childrenSize offset");

enum class BSVisitControl : std::uint32_t
{
    kContinue = 0,
    kStop = 1,
};

inline bool IsKindOf(const NiCollisionObject* object, const NiRTTI* target)
{
    for (const NiRTTI* rtti = object->GetRTTI(); rtti != nullptr; rtti = rtti->baseRTTI) {
        if (rtti == target) {
            return true;
        }
    }
    return false;
}

inline bhkBlendCollisionObject* CastToBlendCollisionObject(NiCollisionObject* object)
{
    if (!object) {
        return nullptr;
    }
    return IsKindOf(object, &NiRTTI_bhkBlendCollisionObject)
        ? static_cast<bhkBlendCollisionObject*>(object)
        : nullptr;
}

template <class Visitor>
BSVisitControl TraverseScenegraphObjects(NiAVObject* object, Visitor& visitor)
{
    BSVisitControl result = BSVisitControl::kContinue;
    if (object) {
        result = visitor(object);
        NiNode* node = object->AsNode();
        if (node) {
            const std::uint32_t count = node->childrenSize;
            for (std::uint32_t i = 0; i < count && result != BSVisitControl::kStop; ++i) {
                result = TraverseScenegraphObjects(node->GetAt(i), visitor);
            }
        }
    }
    return result;
}

struct SetBlendCollisionFieldVisitor
{
    std::uint64_t value;

    BSVisitControl operator()(NiAVObject* object) const
    {
        if (bhkBlendCollisionObject* blend = CastToBlendCollisionObject(object->collisionObject)) {
            blend->field38 = value;
        }
        return BSVisitControl::kContinue;
    }
};
