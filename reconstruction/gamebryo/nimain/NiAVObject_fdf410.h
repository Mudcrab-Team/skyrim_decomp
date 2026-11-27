// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports IsKindOf, NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// NiAVObject, NiNode, NiRTTI, GetRTTI, ContainsParticleSystemRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRTTI_NiParticleSystem, name, baseRTTI, AsNode, GetAt, IsKindOf, children, childrenCapacity, childrenSize, Unk_01, unknown008: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct NiRTTI
{
    const char* name;      // 00
    NiRTTI*     baseRTTI;  // 08
};

extern NiRTTI NiRTTI_NiParticleSystem;

class NiNode;

class NiAVObject
{
public:
    virtual ~NiAVObject();           // 00
    virtual void    Unk_01();        // 01
    virtual NiRTTI* GetRTTI() const; // 02
    virtual NiNode* AsNode();        // 03

    static std::uint32_t ContainsParticleSystemRecursive(NiAVObject* object, bool* outFound);
};

class NiNode : public NiAVObject
{
public:
    NiAVObject* GetAt(std::uint32_t index) const { return children[index]; }

    std::uint8_t  unknown008[0x110];  // 008
    NiAVObject**  children;           // 118
    std::uint16_t childrenCapacity;   // 120
    std::uint16_t childrenSize;       // 122
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "childrenSize offset");
