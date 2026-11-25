// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysCollider: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); reference operations and member offset observed on the target
#pragma once
#include <cstdint>

struct ColliderReference;
struct ColliderReferenceTable
{
    void* unknown00;
    void (*destroy)(ColliderReference*);
};
struct ColliderReference
{
    ColliderReferenceTable* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct ColliderReferencePtr
{
    ~ColliderReferencePtr();
    ColliderReference* value;
};
// volatile: the target updates the object counter atomically.
extern volatile long gColliderObjectCount;
class ColliderBase
{
public:
    virtual ~ColliderBase();
    std::uint8_t state[0x30];
};
struct ColliderLeaffb71b0
{
    ~ColliderLeaffb71b0();
    ColliderBase base;
    ColliderReferencePtr reference;
};
