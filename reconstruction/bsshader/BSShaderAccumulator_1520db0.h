// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: BSSpinLock::Unlock follows the project unit BSShaderAccumulator_151e430.cpp.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObject, NiObject, NiObjectNET, NiAVObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, BSBatchRenderer, BSShader, BSShaderProperty, BSRenderPass, BSGeometry, SunOcclusionTest, AutoMemContext, BSSpinLock, NiCamera, NiNode, NiTransform, NiBound, IssueSunOcclusionQuery, MakeRenderPass, SetupAndDrawPass, ClearRenderPass, ClearBSShaders, BSGraphics::GetThreadRenderContextLock, BSGraphics::State, SetCameraData, camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, useEqualDepthTest, sunPixelCount, waitingForSunQuery, percentSunOccludedStored, sunOcclusionTests, occlusionQuery, percentOccluded, pixelCount, frameCount, waiting, modelBound, alphaProperty, shaderProperty, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, flags, userData, fadeAmount, lastUpdatedFrameCounter, lodMode, flags02: CRASHLOGGER_PDB(59818@2026.10.24)
// name, controllers, extra, extraDataSize, maxSize, rotate, translate, scale, center, radius, Unlock: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GeometryList, Node, head, tail, count, refCount, owningThread, lockCount, unrecovered0C, unrecovered3C, unrecovered58, unrecovered10A, unrecovered10C, RenderLockGuard, g_memoryContext_tls_0x768, g_renderer, g_renderState, g_skyShader, CreateOcclusionQuery, BeginOcclusionQuery, EndOcclusionQuery: GUESS(low)
#pragma once

#include <cstddef>
#include <intrin.h>

class NiCamera;
class NiNode;
class BSShaderProperty;
struct BSRenderPass;

extern __declspec(thread) unsigned int g_memoryContext_tls_0x768;
extern char g_renderer;

void* CreateOcclusionQuery(void* renderer);
void BeginOcclusionQuery(void* renderer, void* query);
void EndOcclusionQuery(void* renderer, void* query);
void ClearBSShaders(bool clearAll);

struct BSSpinLock
{
    unsigned long owningThread;
    long lockCount;
    void Unlock();
};

namespace BSGraphics
{
    struct State
    {
        void SetCameraData(NiCamera* camera, unsigned int flags);
    };

    BSSpinLock* GetThreadRenderContextLock();
}
extern BSGraphics::State g_renderState;

class RenderLockGuard
{
public:
    explicit RenderLockGuard(BSSpinLock* spinLock);
    ~RenderLockGuard();
private:
    BSSpinLock* lock;
};

struct NiTransform
{
    float rotate[3][3];
    float translate[3];
    float scale;
};

struct NiBound
{
    float center[3];
    float radius;
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    unsigned int refCount;
    unsigned int unrecovered0C;
};

class NiObject : public NiRefObject
{
};

class NiObjectNET : public NiObject
{
public:
    const char* name;
    void* controllers;
    void* extra;
    unsigned short extraDataSize;
    unsigned short maxSize;
};
static_assert(sizeof(NiObjectNET) == 0x30, "NiObjectNET layout");

class NiAVObject : public NiObjectNET
{
public:
    NiNode* parent;
    unsigned int parentIndex;
    unsigned int unrecovered3C;
    void* collisionObject;
    NiTransform local;
    NiTransform world;
    NiTransform previousWorld;
    NiBound worldBound;
    unsigned int flags;
    void* userData;
    float fadeAmount;
    unsigned int lastUpdatedFrameCounter;
    unsigned char lodMode;
    unsigned char flags02;
    unsigned short unrecovered10A;
    unsigned int unrecovered10C;
};
static_assert(sizeof(NiAVObject) == 0x110, "NiAVObject layout");

class BSGeometry : public NiAVObject
{
public:
    NiBound modelBound;
    void* alphaProperty;
    BSShaderProperty* shaderProperty;
};
static_assert(offsetof(BSGeometry, shaderProperty) == 0x128, "shaderProperty offset");

struct BSRenderPass
{
    static void ClearRenderPass(BSRenderPass* pass);
};

struct BSShader
{
    BSRenderPass* MakeRenderPass(BSShaderProperty* prop, BSGeometry* geometry, unsigned int passEnum, unsigned char numLights, void** lights);
};
extern BSShader* g_skyShader;

struct BSBatchRenderer
{
    static void SetupAndDrawPass(BSRenderPass* pass, unsigned int technique, bool alpha, unsigned int flags);
};

class NiAccumulator : public NiObject
{
public:
    NiCamera* camera;
};

struct GeometryList
{
    struct Node
    {
        Node* next;
        Node* previous;
        BSGeometry* item;
    };

    Node* head;
    Node* tail;
    unsigned int count;
};

class NiBackToFrontAccumulator : public NiAccumulator
{
public:
    GeometryList itemsList;
    int numItems;
    int maxItems;
    BSGeometry** items;
    float* depths;
    int currItem;
};

class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
public:
    bool observeNoSortHint;
    bool sortByClosestPoint;
    bool interfaceSort;
};

struct SunOcclusionTest
{
    void* occlusionQuery;
    float percentOccluded;
    unsigned int pixelCount;
    unsigned int frameCount;
    bool waiting;
};

class BSShaderAccumulator : public NiAlphaAccumulator
{
public:
    unsigned int unrecovered58;
    bool useEqualDepthTest;
    unsigned int sunPixelCount;
    bool waitingForSunQuery;
    float percentSunOccludedStored;
    SunOcclusionTest sunOcclusionTests[3];

    void IssueSunOcclusionQuery(BSGeometry* geometry, unsigned int index, NiCamera* cam);
};
static_assert(offsetof(BSShaderAccumulator, waitingForSunQuery) == 0x64, "waitingForSunQuery offset");
static_assert(offsetof(BSShaderAccumulator, sunOcclusionTests) == 0x70, "sunOcclusionTests offset");
