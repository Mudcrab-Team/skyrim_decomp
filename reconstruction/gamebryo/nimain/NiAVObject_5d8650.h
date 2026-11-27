// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// NiAVObject, NiNode, worldBound, flags, SetAlwaysDrawRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBound, centerX, centerY, centerZ, radius, AsNode, GetAt, children, childrenCapacity, childrenSize, BSVisitControl, kContinue, kStop, TraverseScenegraphObjects, AlwaysDrawVisitor, Unk_01, Unk_02, unknown008, unknown0F8: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct NiBound
{
    float centerX;  // 00
    float centerY;  // 04
    float centerZ;  // 08
    float radius;   // 0C
};
static_assert(sizeof(NiBound) == 0x10, "NiBound size");

class NiNode;

class NiAVObject
{
public:
    virtual ~NiAVObject();     // 00
    virtual void    Unk_01();  // 01
    virtual void    Unk_02();  // 02
    virtual NiNode* AsNode();  // 03

    std::uint8_t  unknown008[0xDC];  // 008
    NiBound       worldBound;        // 0E4
    std::uint32_t flags;             // 0F4
};
static_assert(offsetof(NiAVObject, worldBound) == 0xE4, "worldBound offset");
static_assert(offsetof(NiAVObject, flags) == 0xF4, "flags offset");

class NiNode : public NiAVObject
{
public:
    NiAVObject* GetAt(std::uint32_t index) const { return children[index]; }

    std::uint8_t  unknown0F8[0x20];  // 0F8
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

struct AlwaysDrawVisitor
{
    BSVisitControl operator()(NiAVObject* object) const
    {
        object->flags |= 0x800;
        object->worldBound.radius = 1.0f;
        return BSVisitControl::kContinue;
    }
};
