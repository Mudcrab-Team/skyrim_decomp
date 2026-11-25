// Source exposure: mixed (community declarations; pinned image observations).
// Code origin: original declarations adapted from the labelled community layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiRefObject, NiObject, NiTimeController, DeleteThis, _refCount, flags, frequency, phase, loKeyTime, hiKeyTime, startTime, lastTime, weightedLastTime, scaledTime, target, next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// totalObjectCount: STANDIN OBSERVED
// NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// heldController: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <intrin.h>

class NiRefObject
{
public:
    // Thread-safe accounting tracks live objects across ownership threads.
    virtual ~NiRefObject() { _InterlockedDecrement(&totalObjectCount); }
    virtual void DeleteThis();

    volatile long _refCount;  // volatile: shared reference ownership is updated atomically.
    static volatile long totalObjectCount;  // volatile: observed global live-object accounting.
};

class NiObject : public NiRefObject
{};

class NiObjectNET;

template <class T>
class NiPointer
{
public:
    ~NiPointer()
    {
        T* object = heldController;
        // Thread-safe reference ownership releases the object at zero.
        if (object && _InterlockedDecrement(&object->_refCount) == 0) {
            object->DeleteThis();
        }
    }

    T* heldController;
};

class NiTimeController : public NiObject
{
public:
    ~NiTimeController() override;

    std::uint16_t flags;
    float frequency;
    float phase;
    float loKeyTime;
    float hiKeyTime;
    float startTime;
    float lastTime;
    float weightedLastTime;
    float scaledTime;
    NiObjectNET* target;
    NiPointer<NiTimeController> next;
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");
