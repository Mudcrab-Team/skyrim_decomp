// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GeometryGroup, batchRenderer: CRASHLOGGER_PDB(59818@2026.10.24)
// virtual destructor: GUESS(low)
// 0x155dd40 BSBatchRenderer::GeometryGroup::~GeometryGroup
#include "BSBatchRenderer_155dd40.h"

// Release the renderer owned by this geometry group.
BSBatchRenderer::GeometryGroup::~GeometryGroup()
{
    if (batchRenderer) {
        delete batchRenderer;
        batchRenderer = nullptr;
    }
}
