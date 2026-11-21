// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorValueOwner; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct ActorValueOwner_vtbl;
struct ActorValueOwner {
    ActorValueOwner_vtbl* __vftable;
};
static_assert(sizeof(ActorValueOwner) == 8, "ActorValueOwner layout differs from the PDB");
