// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSShaderAccumulator, batchRenderer, BSBatchRenderer: CRASHLOGGER_PDB(59818@2026.10.24)
// FinishAlphaGroup: GUESS(low)
// StopGroupingAlphas, GeometryGroup: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

class BSBatchRenderer
{
public:
    struct GeometryGroup;
    void FinishAlphaGroup(GeometryGroup* group);
};

class BSShaderAccumulator
{
public:
    void StopGroupingAlphas(BSBatchRenderer::GeometryGroup* group);

private:
    unsigned char unknown00[0x130];
    BSBatchRenderer* batchRenderer;
};
