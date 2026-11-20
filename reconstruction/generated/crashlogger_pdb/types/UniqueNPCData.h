// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UniqueNPCData; size 0x18
#pragma once

struct Actor_b2630b95;
struct BGSLocation;
struct UniqueNPCData {
    Actor_b2630b95* actor;
    unsigned int refID;
    unsigned int pad0C;
    BGSLocation* editorLoc;
};
static_assert(sizeof(UniqueNPCData) == 24, "UniqueNPCData layout differs from the PDB");
