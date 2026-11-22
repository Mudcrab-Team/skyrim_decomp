// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction of rotation lookup, seen data clearing, and queue decrements.
// 0x2c85c0 TESObjectCELL::GetNorthRotation
// 0x2c86e0 TESObjectCELL::ClearSeenData
// 0x2c9760 TESObjectCELL::DecrementQueuedRefs
// 0x2c9800 TESObjectCELL::DecrementCriticalQueuedRefs
#include "TESObjectCELL_2c85c0.h"
#include "TESWorldSpace_30db20.h"

#include <intrin.h>

float TESObjectCELL::GetNorthRotation()
{
    if (cellFlags & 1u) {
        return extraList.GetNorthRotation();
    }
    return worldSpace->northRotation;
}

void TESObjectCELL::ClearSeenData()
{
    extraList.SetSeenData(nullptr);
    cellGameFlags &= 0xfffeu;
    vtable->RemoveChange(this, 0x80000000u);
}

void TESObjectCELL::DecrementQueuedRefs()
{
    if (loadedData) {
        // Atomically decrement the queued reference count.
        _InterlockedDecrement(&loadedData->queuedRefCount);
        if (loadedData->queuedRefCount < 0) {
            loadedData->queuedRefCount = 0;
        }
    }
}

void TESObjectCELL::DecrementCriticalQueuedRefs()
{
    if (loadedData) {
        // Atomically decrement the critical queued reference count.
        _InterlockedDecrement(&loadedData->criticalQueuedRefCount);
        if (loadedData->criticalQueuedRefCount < 0) {
            loadedData->criticalQueuedRefCount = 0;
        }
    }
}
