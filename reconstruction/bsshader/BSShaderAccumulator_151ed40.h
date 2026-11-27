// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSShaderAccumulator::FinishAccumulatingAppendLitPassesGroupsOnly, BSShaderAccumulator and BSRenderPass layouts, BSBatchRenderer::AppendPassToGeometryGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// PropertyMethods, GetLitPasses and group meanings: GUESS(low) STANDIN
#pragma once

#include "generated/crashlogger_pdb/types/BSRenderPass.h"

struct BSGeometry;
struct BSShaderProperty;
struct BSShaderAccumulator;
struct PropertyMethods {
    void* preceding[42];
    BSRenderPass** (*GetLitPasses)(BSShaderProperty*, BSGeometry*, int, BSShaderAccumulator*);
};
struct BSShaderProperty {
    PropertyMethods* methods;
};
struct BSBatchRenderer {
    void AppendPassToGeometryGroup(BSRenderPass* pass, unsigned int group, bool flag);
};
struct BSShaderAccumulator {
    unsigned char unknown00[0x130];
    BSBatchRenderer* batchRenderer;
    unsigned char unknown138[0x18];
    int renderMode;
    bool FinishAccumulatingAppendLitPassesGroupsOnly(BSGeometry* geometry, BSShaderProperty* property);
};
