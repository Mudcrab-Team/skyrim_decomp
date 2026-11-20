// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorMover; size 0x10
#pragma once

struct ActorMover_vtbl;
struct Actor_b2630b95;
struct ActorMover {
    ActorMover_vtbl* __vftable;
    Actor_b2630b95* actor;
};
static_assert(sizeof(ActorMover) == 16, "ActorMover layout differs from the PDB");
