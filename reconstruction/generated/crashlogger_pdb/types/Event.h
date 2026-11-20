// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Event; size 0x8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct Actor_b2630b95;
struct Event {
    Actor_b2630b95* killer;
};
static_assert(sizeof(Event) == 8, "Event layout differs from the PDB");
