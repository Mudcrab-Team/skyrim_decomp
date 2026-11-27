// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: destructor and list helpers from the project unit NiBackToFrontAccumulator_f1e7c0.
// NiBackToFrontAccumulator, itemsList, items, depths: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseBuffer, RemoveHead: GUESS(low)
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
