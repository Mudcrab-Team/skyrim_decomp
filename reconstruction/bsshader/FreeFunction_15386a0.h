// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: NiRefObject::IncRefCount, NiRefObject::DecRefCount, NiPointer::~NiPointer (sibling ref-count idioms noted below).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp:15 (NiRefObject::IncRefCount, NiPointer::~NiPointer).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e include/NiRefObject_inline.h:32 (NiRefObject::DecRefCount).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:7827 (NiRefObject::DecRefCount).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsmenu/debugtext_ob1_variant.cpp:1535 (NiPointer::~NiPointer).
// SPDX-License-Identifier: CC0-1.0
// FirstListAccumulationJob, CullDescriptor, SubmitCullResultsJob, FlushAlphaGroupQueueJob, BSCullingProcess, NiCullingProcess, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, NiVisibleArray, BSCPCullingType, InitCullDescriptor, DispatchCullAndAccumulate, NiRefObject, NiCamera, NiAVObject, BSCompoundFrustum, BSPortalGraphEntry, BSPortalGraph, BSMultiBoundRoom, accumulator, unk08, camera, geometryListProcess, sceneRoot, lightData, renderTargetIndex, unk61, portalGraphEntry, compoundFrustum, portalGraph, multiBoundRoomAccumList, multiBoundRoomRoot, visibilityMap, visibleUnboundSpace, enableAccumulation, unk134, cellId: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, objectArray, cullQueue, roomSharedMap, cullMode, cullModeStack, cullModeStackIndex, recurseToGeometry, isGroupingAlphas, unk301D6, alphaGroups, alphaGroupIndex, alphaGroupStopIndex, fLeft, fRight, fTop, fBottom, fNear, fFar, bOrtho, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, normal, constant: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer, PortalGraphData, activeCullingProcess, defaultLightData, baseRenderTargetIndex, unk10, unk58, unk131, CullQueueEntry, CullQueueRing, CullQueue, RoomSharedMap, ArrayView, ScatterTableStorage, FrustumStorage, refCount, unk0C, unk14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        // atomic increment: shared reference count across threads
        _InterlockedIncrement(&refCount);
    }

    void DecRefCount()
    {
        // atomic decrement: delete object when last reference drops
        if (_InterlockedDecrement(&refCount) == 0) {
            DeleteThis();
        }
    }

    long refCount;
};

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        if (ptr) {
            ptr->DecRefCount();
        }
    }

    NiPointer& operator=(T* rhs)
    {
        if (ptr != rhs) {
            T* old = ptr;
            if (rhs) {
                rhs->IncRefCount();
            }
            ptr = rhs;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* ptr;
};

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
};

class NiCamera : public NiRefObject
{
};

class NiAVObject : public NiRefObject
{
};

struct NiVisibleArray;
struct BSCompoundFrustum;
struct BSMultiBoundRoom;
struct BSPortalGraph;

struct PortalGraphData
{
    void* unrecovered000[11];
    unsigned char unk58;
};

struct ArrayView {
    void* data;
    std::uint32_t capacity;
    std::uint32_t unk0C;
    std::uint32_t size;
    std::uint32_t unk14;
};

struct ScatterTableStorage {
    std::uint64_t words[6];
};

struct FrustumStorage {
    ArrayView planes;
    ArrayView functionOperators;
    NiFrustumPlanes viewFrustum;
    NiPoint3 viewPosition;
    std::uint32_t unkAC;
    NiCamera* camera;
    std::uint32_t freePlane;
    std::uint32_t freeOp;
    std::uint32_t firstOp;
    bool skipViewFrustum;
    bool prethreaded;
};

struct BSPortalGraphEntry : NiRefObject
{
    PortalGraphData* unk10;
    ArrayView multiBoundRoomAccumList;
    BSMultiBoundRoom* multiBoundRoomRoot;
    ScatterTableStorage visibilityMap;
    FrustumStorage compoundFrustum;
    bool visibleUnboundSpace;
    bool unk131;
    std::uint32_t unk134;
    std::uint32_t cellId;
};
static_assert(offsetof(BSPortalGraphEntry, unk10) == 0x10, "unk10 offset");
static_assert(offsetof(BSPortalGraphEntry, unk131) == 0x131, "unk131 offset");

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
    std::uint64_t words[6];
};

enum class BSCPCullingType : int {
    kNormal = 0,
};

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
    std::uint8_t unk121;
};

struct BSCullingProcess : NiCullingProcess
{
    ArrayView objectArray;
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
    ArrayView alphaGroups;
    int alphaGroupIndex;
    std::uint32_t alphaGroupStopIndex;
};
static_assert(offsetof(BSCullingProcess, portalGraphEntry) == 0x30190, "portalGraphEntry offset");
static_assert(offsetof(BSCullingProcess, compoundFrustum) == 0x301A0, "compoundFrustum offset");

struct CullDescriptor
{
    CullDescriptor();

    NiPointer<NiRefObject> accumulator;
    NiPointer<NiRefObject> unk08;
    NiPointer<NiCamera> camera;
    void* unk18;
    void* unk20;
    void* unk28;
    BSCullingProcess* geometryListProcess;
    void* unk38;
    NiPointer<NiAVObject> sceneRoot;
    void* lightData;
    void* unk50;
    int renderTargetIndex;
    unsigned char ringSelect;
    unsigned char unrecovered05D[3];
    unsigned char unk60;
    bool unk61;
    unsigned char unk62;
    unsigned char unrecovered063[5];
};

void SubmitCullResultsJob(CullDescriptor* descriptor);
void FlushAlphaGroupQueueJob(CullDescriptor* descriptor);
void DispatchCullAndAccumulate(CullDescriptor* descriptor, unsigned int flag1, unsigned int flag2);
void FirstListAccumulationJob(CullDescriptor* descriptor);

extern BSCullingProcess** activeCullingProcess;
extern int baseRenderTargetIndex;
extern unsigned char defaultLightData;
