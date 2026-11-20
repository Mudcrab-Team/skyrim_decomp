// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ParentSpaceNode; size 0x18
#pragma once

struct TESObjectCELL;
struct TESWorldSpace_f9563d31;
struct ParentSpaceNode {
    bool isWorldspace;
    unsigned char pad01[7];
    TESWorldSpace_f9563d31* worldspace;
    TESObjectCELL* interiorCell;
};
static_assert(sizeof(ParentSpaceNode) == 24, "ParentSpaceNode layout differs from the PDB");
