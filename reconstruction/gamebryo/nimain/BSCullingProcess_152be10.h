// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess, BSParabolicCullingProcess, BSGeometryListCullingProcess, NiCullingProcess, SetupCullingProcess, UpdateLightPlanes, SetBackHemisphereAccumulator, SetFrustum, CullDescriptor, BSShaderAccumulator, NiCamera, NiAVObject, NiVisibleArray, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, BSPortalGraphEntry, BSCompoundFrustum, BSCPCullingType: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, objectArray, cullQueue, roomSharedMap, portalGraphEntry, cullMode, compoundFrustum, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// accumulator, unk08, unk18, unk20, unk28, geometryListProcess, unk38, sceneRoot, lightData, renderTargetIndex, ringSelect, unk60, unk61, unk62, lightRadius: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTArrayHeapAllocator, BSTArray, CullQueueEntry, CullQueueRing, CullQueue, RoomSharedMap, unk5D, unk5E, unk5F: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct NiPoint3 {
    float x;
    float y;
    float z;
};

struct NiPlane {
    NiPoint3 normal;
    float constant;
};

struct NiFrustum {
    float fLeft;
    float fRight;
    float fTop;
    float fBottom;
    float fNear;
    float fFar;
    bool bOrtho;
};

struct NiFrustumPlanes {
    NiPlane cullingPlanes[6];
    std::uint32_t activePlanes;
    std::uint32_t basePlaneStates;
    std::uint32_t unk68;
    std::uint32_t unk6C;

    NiFrustumPlanes& operator=(const NiFrustumPlanes& other)
    {
        for (int i = 0; i < 6; ++i) {
            cullingPlanes[i].normal.x = other.cullingPlanes[i].normal.x;
            cullingPlanes[i].normal.y = other.cullingPlanes[i].normal.y;
            cullingPlanes[i].normal.z = other.cullingPlanes[i].normal.z;
            cullingPlanes[i].constant = other.cullingPlanes[i].constant;
        }
        activePlanes = other.activePlanes;
        basePlaneStates = other.basePlaneStates;
        unk68 = other.unk68;
        unk6C = other.unk6C;
        return *this;
    }
};

struct NiVisibleArray;
struct NiCamera;
struct NiAVObject;
struct BSPortalGraphEntry;
struct BSCompoundFrustum;
struct BSGeometryListCullingProcess;
struct BSCullingProcess;

struct BSShaderAccumulator {
    void* unk00;
    void* unk08;
    NiCamera* camera;
};

struct CullDescriptor {
    BSShaderAccumulator* accumulator;
    BSShaderAccumulator* unk08;
    NiCamera* camera;
    BSCompoundFrustum* compoundFrustum;
    NiFrustum* unk20;
    BSPortalGraphEntry* portalGraphEntry;
    BSGeometryListCullingProcess* geometryListProcess;
    NiFrustumPlanes* unk38;
    NiAVObject* sceneRoot;
    void* lightData;
    int cullMode;
    float lightRadius;
    int renderTargetIndex;
    bool ringSelect;
    std::uint8_t unk5D;
    bool unk5E;
    bool unk5F;
    bool unk60;
    bool unk61;
    bool unk62;
};

struct NiCullingProcess {
    virtual ~NiCullingProcess();
    void SetFrustum(const NiFrustum& view);

    bool useVirtualAppend;
    NiVisibleArray* visibleSet;
    NiCamera* camera;
    NiFrustum frustum;
    NiFrustumPlanes planes;
    NiFrustumPlanes customCullPlanes;
    bool cameraRelatedUpdates;
    bool updateAccumulateFlag;
    bool ignorePreprocess;
    bool doCustomCullPlanes;
    bool enablePlaneOptimization;
    std::uint8_t unk121;
};

enum class BSCPCullingType : int {
    kNormal = 0,
    kAllPass = 1,
    kAllFail = 2,
    kIgnoreMultiBounds = 3,
    kForceMultiBoundsNoUpdate = 4,
};

template<class T>
struct BSTArrayHeapAllocator {
    T* data;
    std::uint32_t capacity;
};

template<class T>
struct BSTArray : BSTArrayHeapAllocator<T> {
    std::uint32_t size;
};

struct CullQueueEntry {
    NiAVObject* object;
    int groupIndex;
    std::uint32_t flags;
};

struct CullQueueRing {
    CullQueueEntry* entries[8192];
    std::uint32_t head;
    std::uint32_t tail;
    std::uint32_t commitHead;
    std::uint32_t commitTail;
};

struct CullQueue {
    CullQueueEntry pool[4096];
    CullQueueRing active;
    CullQueueRing freeList;
};

struct RoomSharedMap {
    std::uint64_t entries[6];
};

struct BSCullingProcess : NiCullingProcess {
    static BSCullingProcess* SetupCullingProcess(int passType, CullDescriptor* descriptor, BSCullingProcess* process);

    BSTArray<NiAVObject*> objectArray;
    CullQueue cullQueue;
    RoomSharedMap roomSharedMap;
    BSPortalGraphEntry* portalGraphEntry;
    BSCPCullingType cullMode;
    BSCompoundFrustum* compoundFrustum;
    BSCPCullingType cullModeStack[10];
    std::uint32_t cullModeStackIndex;
    bool recurseToGeometry;
    bool isGroupingAlphas;
    std::uint8_t unk301D6;
    BSTArray<void*> alphaGroups;
    int alphaGroupIndex;
    std::uint32_t alphaGroupStopIndex;
};

struct BSGeometryListCullingProcess : BSCullingProcess {};

struct BSParabolicCullingProcess : BSCullingProcess {
    void UpdateLightPlanes(NiCamera* lightCamera, float lightRadius, bool flag);
    void SetBackHemisphereAccumulator(BSShaderAccumulator* accumulator);
};
