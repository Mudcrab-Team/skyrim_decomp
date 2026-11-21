// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AccumulateSceneGraphContext; size 0x10
#pragma once

struct BSShaderAccumulator;
struct AccumulateSceneGraphContext {
    BSShaderAccumulator* accumulator;
    bool filterByShaderProperty;
    unsigned char undefined_9[7];
};
static_assert(sizeof(AccumulateSceneGraphContext) == 16, "AccumulateSceneGraphContext layout differs from the PDB");
