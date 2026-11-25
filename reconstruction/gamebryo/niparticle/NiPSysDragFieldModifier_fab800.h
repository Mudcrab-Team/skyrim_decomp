// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysDragFieldModifier, CopyMembers, NiCloningProcess: SIBLING(fo4-private@1b765c70, author-permission)
// Field and base names: GUESS(low); stand-ins for offsets observed on the target
#pragma once
#include <cstdint>

struct NiCloningProcess;
struct DragFieldBase
{
    void CopyMembers(DragFieldBase* destination, NiCloningProcess& process);
    std::uint8_t state[0x50];
};
struct DragDirection { float x, y, z; };
struct NiPSysDragFieldModifier : DragFieldBase
{
    void CopyMembers(NiPSysDragFieldModifier* destination, NiCloningProcess& process);
    bool usesDirection;
    DragDirection direction;
};
