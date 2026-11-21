// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RenderPassArray; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSRenderPass_87210fc9;
struct RenderPassArray {
    BSRenderPass_87210fc9* head;
    unsigned long long unk08;
};
static_assert(sizeof(RenderPassArray) == 16, "RenderPassArray layout differs from the PDB");
