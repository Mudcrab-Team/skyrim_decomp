// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObject, NiObject, NiObjectNET, NiAVObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, NiAlphaProperty, NiProperty, NiShadeProperty, BSShaderAccumulator, BSBatchRenderer, BSShaderProperty, BSRenderPass, BSGeometry, RenderPassArray, SunOcclusionTest, ShadowSceneNode, NiCamera, NiNode, NiRTTI, NiTransform, NiBound, FinishAccumulatingAppendPasses, AppendPassToGeometryGroup, camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, useEqualDepthTest, sunPixelCount, waitingForSunQuery, percentSunOccludedStored, sunOcclusionTests, noFade, silhouetteColor, firstPerson, drawDecals, isShadowMapAccumulator, isDirectionalShadowMap, batchRenderer, currentPass, currentBucket, currentActive, activeShadowSceneNode, renderMode, shader, shaderProperty, geometry, passEnum, accumulationHint, extraParam, numLights, numShadowLights, next, passGroupNext, sceneLights, cachePoolId, alpha, lastRenderPassState, flags, renderPassList, debugRenderPassList, fadeNode, effectData, lightData, material, lastAccumulatedFrameCount, modelBound, alphaProperty, parent, parentIndex, collisionObject, local, world, previousWorld, worldBound, userData, fadeAmount, lastUpdatedFrameCounter, lodMode, flags02: CRASHLOGGER_PDB(59818@2026.10.24)
// name, controllers, extra, extraDataSize, maxSize, rotate, translate, scale, center, radius, head, alphaFlags, GetRenderPasses: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GeometryList, Node, tail, count, refCount, threshold, unrecovered08, unrecovered0C, unrecovered3C, unrecovered58, unrecoveredB8, unrecoveredBA, unrecoveredC0, unrecovered100, unrecovered108, unrecovered110, unrecovered114, unrecovered129, unrecovered12A, unrecovered12B, unrecovered10A, unrecovered10C, lodModeByte, unrecovered21, unrecovered22, unrecovered24, g_frameCount, RegisterPassGeometryGroup, Slot00, Slot01, Slot02, Slot03, Slot04, Slot05, Slot06, Slot07, Slot08, Slot09, Slot10, Slot11, Slot12, Slot13, Slot14, Slot15, Slot16, Slot17, Slot18, Slot19, Slot20, Slot21, Slot22, Slot23, Slot24, Slot25, Slot26, Slot27, Slot28, Slot29, Slot30, Slot31, Slot32, Slot33, Slot34, Slot35, Slot36, Slot37, Slot38, Slot39, Slot40, Slot41, Slot42: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiCamera;
class NiNode;
class NiRTTI;
class BSGeometry;
class BSShaderProperty;
class BSShaderAccumulator;
struct ShadowSceneNode;
struct BSRenderPass;

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

class NiProperty : public NiObjectNET
{
};

class NiAlphaProperty : public NiProperty
{
public:
    unsigned short alphaFlags;
    unsigned char threshold;
};
static_assert(offsetof(NiAlphaProperty, alphaFlags) == 0x30, "alphaFlags offset");

class NiShadeProperty : public NiProperty
{
};

struct RenderPassArray
{
    BSRenderPass* head;
    unsigned long long unrecovered08;
};

struct BSRenderPass
{
    void* shader;
    BSShaderProperty* shaderProperty;
    BSGeometry* geometry;
    unsigned int passEnum;
    unsigned char accumulationHint;
    unsigned char extraParam;
    unsigned char lodModeByte;
    unsigned char numLights;
    unsigned char numShadowLights;
    unsigned char unrecovered21;
    unsigned short unrecovered22;
    unsigned int unrecovered24;
    BSRenderPass* next;
    BSRenderPass* passGroupNext;
    void** sceneLights;
    unsigned int cachePoolId;
};
static_assert(offsetof(BSRenderPass, passEnum) == 0x18, "passEnum offset");
static_assert(offsetof(BSRenderPass, accumulationHint) == 0x1C, "accumulationHint offset");
static_assert(offsetof(BSRenderPass, next) == 0x28, "next offset");

class BSShaderProperty : public NiShadeProperty
{
public:
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual RenderPassArray* GetRenderPasses(BSGeometry* geometry, unsigned int renderMode, BSShaderAccumulator* accumulator);

    float alpha;
    int lastRenderPassState;
    std::uint64_t flags;
    RenderPassArray renderPassList;
    RenderPassArray debugRenderPassList;
    void* fadeNode;
    void* effectData;
    void* lightData;
    void* material;
    unsigned int lastAccumulatedFrameCount;
};
static_assert(offsetof(BSShaderProperty, flags) == 0x38, "flags offset");
static_assert(offsetof(BSShaderProperty, lastAccumulatedFrameCount) == 0x80, "lastAccumulatedFrameCount offset");

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
    NiAlphaProperty* alphaProperty;
    BSShaderProperty* shaderProperty;
};
static_assert(offsetof(BSGeometry, alphaProperty) == 0x120, "alphaProperty offset");

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

struct BSBatchRenderer
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void RegisterPassGeometryGroup(BSRenderPass* pass, unsigned int passEnum);
    void AppendPassToGeometryGroup(BSRenderPass* pass, unsigned int group, bool flag);
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
    bool unrecoveredB8;
    bool noFade;
    bool unrecoveredBA;
    unsigned char unrecoveredC0[0x40];
    void* unrecovered100;
    NiRefObject* unrecovered108;
    unsigned int unrecovered110;
    bool unrecovered114;
    float silhouetteColor[4];
    bool firstPerson;
    bool unrecovered129;
    bool unrecovered12A;
    bool unrecovered12B;
    bool drawDecals;
    bool isShadowMapAccumulator;
    bool isDirectionalShadowMap;
    BSBatchRenderer* batchRenderer;
    unsigned int currentPass;
    unsigned int currentBucket;
    bool currentActive;
    ShadowSceneNode* activeShadowSceneNode;
    unsigned int renderMode;

    bool FinishAccumulatingAppendPasses(BSGeometry* geometry, BSShaderProperty* shaderProperty);
};
static_assert(offsetof(BSShaderAccumulator, drawDecals) == 0x12C, "drawDecals offset");
static_assert(offsetof(BSShaderAccumulator, batchRenderer) == 0x130, "batchRenderer offset");
static_assert(offsetof(BSShaderAccumulator, renderMode) == 0x150, "renderMode offset");

extern unsigned int g_frameCount;
