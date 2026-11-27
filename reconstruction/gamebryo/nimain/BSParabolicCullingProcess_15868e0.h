// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, BSCullingProcess, NiCullingProcess, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, NiCamera, NiVisibleArray, NiAVObject, BSPortalGraphEntry, BSCompoundFrustum, BSCPCullingType, BSShaderAccumulator: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, fLeft, fRight, fTop, fBottom, fNear, fFar, bOrtho, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C: CRASHLOGGER_PDB(59818@2026.10.24)
// objectArray, cullQueue, roomSharedMap, portalGraphEntry, cullMode, compoundFrustum, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// unk301F8, backHemisphereAccumulator, equatorialPlane, lightPosition, lightRadius, lightCamera, normal, constant, _data, _capacity, _size: CRASHLOGGER_PDB(59818@2026.10.24)
// AccumulatorReference, defaultPosition, ArrayStorage, ArrayBase, CullQueueEntry, CullQueueRing, CullQueue, RoomSharedMap, entries, pool, active, freeList, head, tail, commitHead, commitTail, object, groupIndex, flags, pointer: GUESS(low) STANDIN
#pragma once

struct NiPoint3 {
    float x;
    float y;
    float z;
};
extern const NiPoint3 defaultPosition;

struct NiPlane {
    NiPlane();
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
    unsigned int activePlanes;
    unsigned int basePlaneStates;
    unsigned int unk68;
    unsigned int unk6C;
};

struct NiVisibleArray;
struct NiCamera;
struct NiAVObject;
struct BSPortalGraphEntry;
struct BSCompoundFrustum;
struct BSShaderAccumulator;

struct NiCullingProcess {
    virtual ~NiCullingProcess();
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
    unsigned char unk121;
};

enum class BSCPCullingType : int {
    kNormal = 0,
    kAllPass = 1,
    kAllFail = 2,
    kIgnoreMultiBounds = 3,
    kForceMultiBoundsNoUpdate = 4,
};

template<class T>
struct ArrayStorage {
    T* _data;
    unsigned int _capacity;
};

template<class T>
struct ArrayBase : ArrayStorage<T> {
    unsigned int _size;
};

struct CullQueueEntry {
    NiAVObject* object;
    int groupIndex;
    unsigned int flags;
};

struct CullQueueRing {
    CullQueueEntry* entries[8192];
    unsigned int head;
    unsigned int tail;
    unsigned int commitHead;
    unsigned int commitTail;
};

struct CullQueue {
    CullQueueEntry pool[4096];
    CullQueueRing active;
    CullQueueRing freeList;
};

struct RoomSharedMap {
    unsigned long long entries[6];
};

struct BSCullingProcess : NiCullingProcess {
    BSCullingProcess();
    ~BSCullingProcess() override;
    ArrayBase<NiAVObject*> objectArray;
    CullQueue cullQueue;
    RoomSharedMap roomSharedMap;
    BSPortalGraphEntry* portalGraphEntry;
    BSCPCullingType cullMode;
    BSCompoundFrustum* compoundFrustum;
    BSCPCullingType cullModeStack[10];
    unsigned int cullModeStackIndex;
    bool recurseToGeometry;
    bool isGroupingAlphas;
    unsigned char unk301D6;
    ArrayBase<void*> alphaGroups;
    int alphaGroupIndex;
    unsigned int alphaGroupStopIndex;
};

struct AccumulatorReference {
    AccumulatorReference() : pointer(nullptr) {}
    ~AccumulatorReference();
    BSShaderAccumulator* pointer;
};

struct BSParabolicCullingProcess : BSCullingProcess {
    BSParabolicCullingProcess();
    ~BSParabolicCullingProcess() override;
    float unk301F8;
    AccumulatorReference backHemisphereAccumulator;
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiCamera* lightCamera;
};
