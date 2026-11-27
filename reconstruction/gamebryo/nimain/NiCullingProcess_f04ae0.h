// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// NiCullingProcess, Process1, NiAVObject, NiAVObjectFlag, NiFrustum, NiFrustumPlanes, NiPlane, NiPoint3, NiBound, NiCamera, NiVisibleArray, NiTransform, NiMatrix3: CRASHLOGGER_PDB(59818@2026.10.24)
// useVirtualAppend, visibleSet, camera, frustum, planes, customCullPlanes, cameraRelatedUpdates, updateAccumulateFlag, ignorePreprocess, doCustomCullPlanes, enablePlaneOptimization, unk121, cullingPlanes, activePlanes, basePlaneStates, unk68, unk6C, worldBound, flags, center, radius, normal, constant: CRASHLOGGER_PDB(59818@2026.10.24)
// kAlwaysDraw, kPreProcessedNode, kNotVisible, kAccumulated, fLeft, fRight, fTop, fBottom, fNear, fFar, bOrtho: CRASHLOGGER_PDB(59818@2026.10.24)
// OnVisible, NiObjectNET, parent, parentIndex, unk03C, collisionObject, local, world, previousWorld: CRASHLOGGER_PDB(59818@2026.10.24)
// TestBit, radiusRaw, unkSlot01: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <intrin.h>

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
    union {
        float radius;
        std::uint32_t radiusRaw;
    };
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

struct NiObjectNET {
    virtual ~NiObjectNET();
    virtual void unkSlot01();
    virtual void unkSlot02();
    virtual void unkSlot03();
    virtual void unkSlot04();
    virtual void unkSlot05();
    virtual void unkSlot06();
    virtual void unkSlot07();
    virtual void unkSlot08();
    virtual void unkSlot09();
    virtual void unkSlot10();
    virtual void unkSlot11();
    virtual void unkSlot12();
    virtual void unkSlot13();
    virtual void unkSlot14();
    virtual void unkSlot15();
    virtual void unkSlot16();
    virtual void unkSlot17();
    virtual void unkSlot18();
    virtual void unkSlot19();
    virtual void unkSlot20();
    virtual void unkSlot21();
    virtual void unkSlot22();
    virtual void unkSlot23();
    virtual void unkSlot24();
    virtual void unkSlot25();
    virtual void unkSlot26();
    virtual void unkSlot27();
    virtual void unkSlot28();
    virtual void unkSlot29();
    virtual void unkSlot30();
    virtual void unkSlot31();
    virtual void unkSlot32();
    virtual void unkSlot33();
    virtual void unkSlot34();
    virtual void unkSlot35();
    virtual void unkSlot36();
    virtual void unkSlot37();
    virtual void unkSlot38();
    virtual void unkSlot39();
    virtual void unkSlot40();
    virtual void unkSlot41();
    virtual void unkSlot42();
    virtual void unkSlot43();
    virtual void unkSlot44();
    virtual void unkSlot45();
    virtual void unkSlot46();
    virtual void unkSlot47();
    virtual void unkSlot48();
    virtual void unkSlot49();
    virtual void unkSlot50();
    virtual void unkSlot51();
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
