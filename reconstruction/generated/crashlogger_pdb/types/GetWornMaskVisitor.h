// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GetWornMaskVisitor; size 0x18
#pragma once

#include "IItemChangeVisitor.h"
#include "enumeration_RE__BIPED_MODEL__BipedObjectSlot_unsigned_int_fafe642c.h"
struct Actor_b2630b95;
struct GetWornMaskVisitor {
    IItemChangeVisitor _base;
    enumeration_RE__BIPED_MODEL__BipedObjectSlot_unsigned_int_fafe642c slotMask;
    unsigned int pad0C;
    Actor_b2630b95* actor;
};
static_assert(sizeof(GetWornMaskVisitor) == 24, "GetWornMaskVisitor layout differs from the PDB");
