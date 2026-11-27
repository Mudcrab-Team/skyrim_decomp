// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSRotAccumTransfInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct RotReference;
struct RotReferenceTable
{
    void* unknown00;
    void (*destroy)(RotReference*);
};
struct RotReference
{
    RotReferenceTable* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct RotReferencePtr
{
    ~RotReferencePtr();
    RotReference* value;
};
class RotAccumBase
{
public:
    virtual ~RotAccumBase();
    std::uint8_t state[0x30];
};
class RotAccumLeaff8c310 : public RotAccumBase
{
public:
    ~RotAccumLeaff8c310() override;
    RotReferencePtr reference;
};
