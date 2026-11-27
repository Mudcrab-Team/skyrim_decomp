// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1586860 BSImagespaceShaderWaterFlow::Function1586860
#include "BSImagespaceShaderWaterFlow_1586860.h"

FlowPair g_flowA;
FlowPair g_flowB;
FlowPair g_flowC;
FlowPair g_flowD;
float g_flowE;
float g_flowF;
float g_flowG;
float g_flowH;
float g_flowI;

void BSImagespaceShaderWaterFlow::Function1586860()
{
    Texture* texture = unkD8->texture;
    if (texture)
    {
        texture->Function1555260(0);
    }
    g_flowA = kFlowDefault;
    g_flowB = kFlowDefault;
    g_flowC = kFlowDefault;
    g_flowD = kFlowDefault;
    g_flowE = 0.0f;
    g_flowF = 0.0f;
    g_flowG = 1.0f;
    g_flowH = 1.0f;
    g_flowI = 0.0f;
}
