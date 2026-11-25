// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfa0f00 ModifierCopyfa0f00::CopyMembers
#include "ModifierCopyfa0f00_fa0f00.h"

void ModifierCopyfa0f00::CopyMembers(ModifierCopyfa0f00* destination, NiCloningProcess& process)
{
    ModifierCopyBase::CopyMembers(destination, process);
    destination->name = name;
    destination->order = order;
    destination->active = active;
}
