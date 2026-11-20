// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxRenderConfig; size 0x38
#pragma once

#include "GFxState_6a94ada2.h"
#include "GPtr_RE__GRenderer_cd55cb51.h"
#include "RenderCapBits.h"
#include "RenderFlag.h"
#include "VertexFormat.h"
struct GFxRenderConfig {
    GFxState_6a94ada2 _base;
    GPtr_RE__GRenderer_cd55cb51 renderer;
    float maxCurvePixelError;
    RenderFlag renderFlags;
    float strokerAAWidth;
    RenderCapBits rendererCapBits;
    VertexFormat rendererVtxFmts;
    unsigned int pad34;
};
static_assert(sizeof(GFxRenderConfig) == 56, "GFxRenderConfig layout differs from the PDB");
