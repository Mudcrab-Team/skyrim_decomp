// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// CullJob_AccumulateAndFlush, BSCullingProcess, TakePendingCullingProcess, AccumulateGeometry, ClearCollectedGeometry, FlushAlphaGroupQueue, portalGraphEntry: CRASHLOGGER_PDB(59818@2026.10.24)
// CullJobParameters, accumulator: GUESS(low) STANDIN
#pragma once

struct BSShaderAccumulator;
struct BSPortalGraphEntry;
struct CullJobParameters { BSShaderAccumulator* accumulator; };
struct BSCullingProcess {
    unsigned char unrecovered[0x30190];
    BSPortalGraphEntry* portalGraphEntry;
    static BSCullingProcess* TakePendingCullingProcess();
    void AccumulateGeometry(BSShaderAccumulator*);
    void ClearCollectedGeometry();
    void FlushAlphaGroupQueue();
};
