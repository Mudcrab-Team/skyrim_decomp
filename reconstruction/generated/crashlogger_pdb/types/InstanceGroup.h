// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InstanceGroup; size 0x58
#pragma once

#include "BSMultiBoundAABB.h"
struct VertexBuffer;
struct InstanceGroup {
    BSMultiBoundAABB _base;
    VertexBuffer* vertexBuffer;
    unsigned int triCount;
    unsigned int instanceCount;
    bool isVisible;
    unsigned char undefined_51[7];
};
static_assert(sizeof(InstanceGroup) == 88, "InstanceGroup layout differs from the PDB");
