// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, ResetAccumulatorState, NiCamera, BSGeometry, camera, itemsList, numItems, maxItems, items, depths, currItem, observeNoSortHint, sortByClosestPoint, interfaceSort: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryList, Node, head, tail, count, refCount, unk0C: GUESS(low)
#pragma once

class NiCamera;
class BSGeometry;

class NiRefObject
{
public:
    virtual ~NiRefObject();
    unsigned int refCount;
    unsigned int unk0C;
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

class BSShaderAccumulator : public NiAlphaAccumulator
{
public:
    void ResetAccumulatorState();
};
