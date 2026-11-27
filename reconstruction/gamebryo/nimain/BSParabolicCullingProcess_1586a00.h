// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, BSCullingProcess, NiCullingProcess, Process1, GetHemisphereMask, BSCompoundFrustum, GetActivePlaneState, SetActivePlaneState, Process, NiAVObject, NiAVObjectFlag, NiObjectNET, NiBound, NiTransform, NiMatrix3, NiPoint3, NiPlane, NiFrustum, NiFrustumPlanes, NiCamera, NiVisibleArray, NiNode, BSPortalGraphEntry, BSCPCullingType, BSShaderAccumulator: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, objectArray, cullQueue, roomSharedMap, portalGraphEntry, cullMode, compoundFrustum, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// unk301F8, backHemisphereAccumulator, equatorialPlane, lightPosition, lightRadius, lightCamera, worldBound, flags, freePlane, freeOp, firstOp, skipViewFrustum, prethreaded, functionOperators, viewFrustum, viewPosition: CRASHLOGGER_PDB(59818@2026.10.24)
// kAlwaysDraw, kPreProcessedNode, kNotVisible, kAccumulated, OnVisible: CRASHLOGGER_PDB(59818@2026.10.24)
// ProcessHemisphere, TestBit, BSTArrayHeapAllocator, BSTArray, CullQueueEntry, CullQueueRing, CullQueue, RoomSharedMap, vslot00: GUESS(low) STANDIN
#pragma once

#include <cstdint>

inline bool TestBit(std::uint32_t flagWord, std::uint32_t bitIndex)
{
    return ((flagWord >> bitIndex) & 1u) != 0;
}

struct NiPoint3 {
    float x;
    float y;
    float z;
};

struct NiMatrix3 {
    float entry[3][3];
};

struct NiTransform {
    NiMatrix3 rotate;
    NiPoint3 translate;
    float scale;
};

struct NiBound {
    NiPoint3 center;
    float radius;
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
};

enum NiAVObjectFlag : std::uint32_t {
    kAlwaysDraw = 0x800,
    kPreProcessedNode = 0x1000,
    kNotVisible = 0x100000,
    kAccumulated = 0x4000000,
};

struct NiCullingProcess;
struct NiCamera;
struct NiVisibleArray;
struct NiNode;
struct BSPortalGraphEntry;
struct BSShaderAccumulator;

struct NiObjectNET {
    virtual ~NiObjectNET();
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual void vslot04();
    virtual void vslot05();
    virtual void vslot06();
    virtual void vslot07();
    virtual void vslot08();
    virtual void vslot09();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void vslot37();
    virtual void vslot38();
    virtual void vslot39();
    virtual void vslot40();
    virtual void vslot41();
    virtual void vslot42();
    virtual void vslot43();
    virtual void vslot44();
    virtual void vslot45();
    virtual void vslot46();
    virtual void vslot47();
    virtual void vslot48();
    virtual void vslot49();
    virtual void vslot50();
    virtual void vslot51();
    virtual void OnVisible(NiCullingProcess* process, std::uint32_t alphaGroupIndex);

    std::uint32_t refCount;
    const char* name;
    void* controllers;
    void** extra;
    std::uint16_t extraDataSize;
    std::uint16_t maxSize;
};

struct NiAVObject : NiObjectNET {
    NiNode* parent;
    std::uint32_t parentIndex;
    std::uint32_t unk03C;
    void* collisionObject;
    NiTransform local;
    NiTransform world;
    NiTransform previousWorld;
    NiBound worldBound;
    std::uint32_t flags;
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

struct BSCompoundFrustum {
    void GetActivePlaneState(std::uint32_t* stateBuffer, std::uint32_t count);
    void SetActivePlaneState(std::uint32_t* stateBuffer, std::uint32_t count);
    bool Process(NiAVObject* object);

    BSTArray<NiFrustumPlanes> planes;
    BSTArray<void*> functionOperators;
    NiFrustumPlanes viewFrustum;
    float viewPosition[4];
    NiCamera* camera;
    std::uint32_t freePlane;
    std::uint32_t freeOp;
    std::uint32_t firstOp;
    bool skipViewFrustum;
    bool prethreaded;
};

struct NiCullingProcess {
    virtual ~NiCullingProcess();
    virtual void Process1(NiAVObject* object, std::uint32_t alphaGroupIndex);

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

struct BSParabolicCullingProcess : BSCullingProcess {
    void Process1(NiAVObject* object, std::uint32_t alphaGroupIndex) override;
    void ProcessHemisphere(NiAVObject* object, std::uint32_t alphaGroupIndex);
    std::uint32_t GetHemisphereMask(NiBound* bound);

    float unk301F8;
    BSShaderAccumulator* backHemisphereAccumulator;
    NiPlane equatorialPlane;
    NiPoint3 lightPosition;
    float lightRadius;
    NiCamera* lightCamera;
};
