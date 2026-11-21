// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ContainerObject; size 0x18
#pragma once

struct ContainerItemExtra;
struct TESBoundObject_fc790793;
struct ContainerObject {
    int count;
    unsigned int pad04;
    TESBoundObject_fc790793* obj;
    ContainerItemExtra* itemExtra;
};
static_assert(sizeof(ContainerObject) == 24, "ContainerObject layout differs from the PDB");
