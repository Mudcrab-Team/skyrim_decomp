// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// BSFrustumFOVController: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct ControllerRef;
struct ControllerRefVTable
{
    void* unknown00;
    void (*destroy)(ControllerRef*);
};
struct ControllerRef
{
    ControllerRefVTable* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct ControllerRefPtr
{
    ~ControllerRefPtr();
    ControllerRef* value;
};
struct ControllerLeafBase
{
    ~ControllerLeafBase();
    std::uint8_t state[0x48];
};
struct ControllerLeaff97360 : ControllerLeafBase
{
    ~ControllerLeaff97360();
    ControllerRefPtr reference;
};
