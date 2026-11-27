// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, BSBatchRenderer, GeometryGroup, SunOcclusionTest, NiCamera, BSGeometry, RenderBatches, SetCurrentAccumulator, ClearBSShaders, camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, useEqualDepthTest, sunPixelCount, waitingForSunQuery, percentSunOccludedStored, sunOcclusionTests, noFade, silhouetteColor, firstPerson, drawDecals, isShadowMapAccumulator, isDirectionalShadowMap, batchRenderer, currentPass, currentBucket, currentActive, currentFirstPass, currentLastPass, activePassIndexList, groupingAlphasCount, autoClearPasses, geometryGroups: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryList, Node, head, tail, count, refCount, unrecovered0C, unrecovered58, unrecoveredB8, unrecoveredBA, unrecoveredC0, unrecovered100, unrecovered108, unrecovered110, unrecovered114, unrecovered129, unrecovered12A, unrecovered12B, PassIndexNode, pass, nextNode, unrecovered08, StartBatchIteration, SkipBatch, RenderBatch, ClearPasses: GUESS(low)
#pragma once

#include <cstddef>

class NiCamera;
class BSGeometry;
struct BSBatchRenderer;

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

class NiAccumulator : public NiObject
{
public:
    NiCamera* camera;
};

struct GeometryList
{
    struct Node
    {
        Node* nextNode;
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

struct PassIndexNode
{
    unsigned int pass;
    PassIndexNode* nextNode;
};

struct GeometryGroup
{
    BSBatchRenderer* batchRenderer;
    void ClearPasses();
};

struct BSBatchRenderer
{
    virtual ~BSBatchRenderer();
    unsigned char unrecovered08[0x48];
    unsigned int currentFirstPass;
    unsigned int currentLastPass;
    PassIndexNode activePassIndexList;
    unsigned int groupingAlphasCount;
    bool autoClearPasses;
    GeometryGroup* geometryGroups[16];

    bool StartBatchIteration(unsigned int* pass, unsigned int* bucket, PassIndexNode** node);
    bool SkipBatch(unsigned int* pass, unsigned int* bucket, PassIndexNode** node);
    bool RenderBatch(unsigned int* pass, unsigned int* bucket, PassIndexNode** node, unsigned int flags);
};
static_assert(offsetof(BSBatchRenderer, currentFirstPass) == 0x50, "currentFirstPass offset");
static_assert(offsetof(BSBatchRenderer, activePassIndexList) == 0x58, "activePassIndexList offset");
static_assert(offsetof(BSBatchRenderer, geometryGroups) == 0x70, "geometryGroups offset");

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

    static void SetCurrentAccumulator(BSShaderAccumulator* accumulator);
    void RenderBatches(unsigned int first, unsigned int last, unsigned int flags, int group);
};
static_assert(offsetof(BSShaderAccumulator, firstPerson) == 0x128, "firstPerson offset");
static_assert(offsetof(BSShaderAccumulator, batchRenderer) == 0x130, "batchRenderer offset");
static_assert(offsetof(BSShaderAccumulator, currentActive) == 0x140, "currentActive offset");

void ClearBSShaders(bool clearAll);
