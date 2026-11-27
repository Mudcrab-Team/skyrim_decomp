// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSBatchRenderer, GeometryGroup, batchRenderer: CRASHLOGGER_PDB(59818@2026.10.24)
// virtual destructor: GUESS(low)
#pragma once

class BSBatchRenderer
{
public:
    virtual ~BSBatchRenderer();
    struct GeometryGroup
    {
        ~GeometryGroup();
        BSBatchRenderer* batchRenderer;
    };
};
