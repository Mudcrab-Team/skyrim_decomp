// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// SubmitCullResultsJob, CullDescriptor, BSGeometryListCullingProcess, BSCullingProcess, SubmitCullResults, NiCamera, NiAVObject, AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// accumulator, unk08, camera, unk18, unk20, unk28, geometryListProcess, unk38, sceneRoot, lightData, unk50, renderTargetIndex, ringSelect, unk60, unk61, unk62: CRASHLOGGER_PDB(59818@2026.10.24)
// memoryContext, previous: GUESS(low)
#pragma once

#include <cstdint>

extern __declspec(thread) std::uint32_t memoryContext;

struct NiCamera;
struct NiAVObject;

struct BSCullingProcess {
    void SubmitCullResults(void* objects, NiCamera* camera, bool flag1, bool flag2);
};

struct BSGeometryListCullingProcess : BSCullingProcess {};

struct CullDescriptor {
    void* accumulator;
    void* unk08;
    NiCamera* camera;
    void* unk18;
    void* unk20;
    void* unk28;
    BSGeometryListCullingProcess* geometryListProcess;
    void* unk38;
    NiAVObject* sceneRoot;
    void* lightData;
    void* unk50;
    int renderTargetIndex;
    unsigned char ringSelect;
    unsigned char unk5D;
    unsigned char unk5E;
    unsigned char unk5F;
    unsigned char unk60;
    bool unk61;
    unsigned char unk62;
};

void SubmitCullResultsJob(CullDescriptor* descriptor);
