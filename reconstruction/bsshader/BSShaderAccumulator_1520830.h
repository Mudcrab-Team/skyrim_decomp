// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// BSShaderAccumulator, FinishAccumulatingMode25_VolumetricOrOcclusion, RenderBatches, BSBatchRenderer, batchRenderer, geometryGroups, GeometryGroup, flags, camera: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderGeometryGroup, RenderGroup, groupsEnabled: GUESS(low)
#pragma once

struct GeometryGroup
{
    unsigned char unknown00[0x26];
    unsigned char flags;
    void RenderGroup(unsigned renderFlags);
};
struct BSBatchRenderer
{
    unsigned char unknown00[0x70];
    GeometryGroup* geometryGroups[16];
};
struct NiCamera;
struct BSShaderAccumulator
{
    unsigned char unknown00[0x10];
    NiCamera* camera;
    unsigned char unknown18[0x118];
    BSBatchRenderer* batchRenderer;

    void RenderBatches(unsigned first, unsigned last, unsigned flags, int group);
    void FinishAccumulatingMode25_VolumetricOrOcclusion(unsigned renderFlags);
    void RenderGeometryGroup(int index, unsigned renderFlags);
};

extern bool groupsEnabled;
