// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator: EXE_RTTI
// BSGeometry, NiCamera, camera, itemsList, numItems, maxItems, items, depths, currItem: CRASHLOGGER_PDB(59818@2026.10.24)
// RemoveHead, ReleaseBuffer, GeometryList, ms_totalObjects: GUESS(low)
#pragma once

#include "NiAccumulator_f1eda0.h"

class BSGeometry;

struct GeometryList
{
    struct Node
    {
        Node* next;
        Node* previous;
        BSGeometry* item;
    };

    GeometryList() : count(0)
    {
        head = nullptr;
        tail = nullptr;
    }

    ~GeometryList();
    void RemoveHead();

    Node* head;
    Node* tail;
    unsigned int count;
};

class NiBackToFrontAccumulator : public NiAccumulator
{
public:
    NiBackToFrontAccumulator();
    ~NiBackToFrontAccumulator() override;

    GeometryList itemsList;
    int numItems;
    int maxItems;
    BSGeometry** items;
    float* depths;
    int currItem;
};
