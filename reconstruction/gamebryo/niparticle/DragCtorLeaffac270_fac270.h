// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysDragFieldModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types, fields and global: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct DragCtorDirection { float x, y, z; };
extern DragCtorDirection gDragDefault;
class DragCtorBase
{
public:
    DragCtorBase();
    virtual ~DragCtorBase();
    std::uint8_t state[0x48];
};
class DragCtorLeaffac270 : public DragCtorBase
{
public:
    DragCtorLeaffac270();
    bool usesDirection;
    DragCtorDirection direction;
};
