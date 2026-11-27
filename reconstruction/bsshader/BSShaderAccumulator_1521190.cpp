// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSShaderAccumulator, BSBatchRenderer, GeometryGroup, RenderBatches, SetCurrentAccumulator, ClearBSShaders, batchRenderer, geometryGroups, currentFirstPass, currentLastPass, activePassIndexList, currentPass, currentBucket, currentActive, firstPerson: CRASHLOGGER_PDB(59818@2026.10.24)
// PassIndexNode, StartBatchIteration, SkipBatch, RenderBatch, ClearPasses, unrecovered129: GUESS(low)
// 0x1521190 BSShaderAccumulator::RenderBatches
#include "BSShaderAccumulator_1521190.h"

void BSShaderAccumulator::RenderBatches(unsigned int first, unsigned int last, unsigned int flags, int group)
{
    SetCurrentAccumulator(this);
    BSBatchRenderer* renderer = batchRenderer;
    GeometryGroup* geomGroup;
    if (group > -1) {
        geomGroup = renderer->geometryGroups[group];
        renderer = geomGroup->batchRenderer;
    } else {
        geomGroup = nullptr;
    }

    currentPass = 0;
    PassIndexNode* node;
    if (renderer) {
        renderer->currentFirstPass = first;
        renderer->currentLastPass = last;
        currentBucket = 0;
        node = &renderer->activePassIndexList;
        currentActive = renderer->StartBatchIteration(&currentPass, &currentBucket, &node);
    } else {
        currentActive = false;
    }

    while (currentActive) {
        bool skip = false;
        switch (currentPass) {
        case 0x5C000058u:
        case 0x5C000059u:
        case 0x5C00005Au:
        case 0x5C00005Bu:
            skip = (firstPerson || unrecovered129);
            break;
        default:
            break;
        }
        if (skip) {
            currentActive = renderer->SkipBatch(&currentPass, &currentBucket, &node);
        } else {
            currentActive = renderer->RenderBatch(&currentPass, &currentBucket, &node, flags);
        }
    }

    if (geomGroup) {
        geomGroup->ClearPasses();
    }
    ClearBSShaders(false);
}
