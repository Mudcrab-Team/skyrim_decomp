// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, BSBatchRenderer, GeometryGroup, SunOcclusionTest, NiCamera, BSGeometry, FinishAccumulatingSharedModes, RenderBatches, RenderDecalPassesAlt, UpdateWorldCameraProjection, camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort, useEqualDepthTest, sunPixelCount, waitingForSunQuery, percentSunOccludedStored, sunOcclusionTests, noFade, silhouetteColor, firstPerson, drawDecals, isShadowMapAccumulator, isDirectionalShadowMap, batchRenderer, geometryGroups, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryList, Node, head, tail, count, refCount, unrecovered0C, unrecovered58, unrecoveredB8, unrecoveredBA, unrecoveredC0, unrecovered100, unrecovered108, unrecovered110, unrecovered114, unrecovered129, unrecovered12A, unrecovered12B, unrecovered00, RenderGeometryGroup, RenderGroup, SaveWorldCameraProjection, g_renderStateFlags, g_depthWriteMode: GUESS(low)
#pragma once

#include <cstddef>

class NiCamera;
class BSGeometry;

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

struct GeometryGroup
{
    unsigned char unrecovered00[0x26];
    unsigned char flags;
    void RenderGroup(unsigned int renderFlags);
};

struct BSBatchRenderer
{
    unsigned char unrecovered00[0x70];
    GeometryGroup* geometryGroups[16];
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

    void RenderBatches(unsigned int first, unsigned int last, unsigned int flags, int group);
    void RenderDecalPassesAlt(unsigned int renderFlags);
    void RenderGeometryGroup(int index, unsigned int renderFlags);
    void FinishAccumulatingSharedModes(unsigned int renderFlags);
};
static_assert(offsetof(BSShaderAccumulator, batchRenderer) == 0x130, "batchRenderer offset");

void SaveWorldCameraProjection();
void UpdateWorldCameraProjection();
extern unsigned int g_renderStateFlags;
extern unsigned int g_depthWriteMode;
