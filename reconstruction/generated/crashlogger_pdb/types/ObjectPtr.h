// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ObjectPtr; size 0x10
#pragma once

struct CombatBehaviorStack;
struct ObjectPtr {
    CombatBehaviorStack* stack;
    unsigned int frame;
    unsigned int pad0C;
};
static_assert(sizeof(ObjectPtr) == 16, "ObjectPtr layout differs from the PDB");
