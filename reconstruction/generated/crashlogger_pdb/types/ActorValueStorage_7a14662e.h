// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ActorValueStorage; size 0x20
// one of 2 different PDB types sharing this name
#pragma once
struct ActorValueStorage_7a14662e {
    unsigned char baseValues_raw[16];
    unsigned char modifiers_raw[16];
};
static_assert(sizeof(ActorValueStorage_7a14662e) == 32, "ActorValueStorage_7a14662e layout differs from the PDB");
