// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts for attached data and flags.
// TESObjectCELL, LOADED_CELL_DATA, ExtraDataList, ExtraSeenData, GetNorthRotation, cellFlags, cellGameFlags, extraList, worldSpace, loadedData, criticalQueuedRefCount, queuedRefCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CellFormVTable, SetSeenData, ClearSeenData, DecrementQueuedRefs, DecrementCriticalQueuedRefs, ResolveQueryNode, CellSurfaceQuery: GUESS(low)
// TESForm::RemoveChange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CellFormVTable::RemoveChange: STANDIN OBSERVED
#pragma once

#include <cstdint>

class TESObjectCELL;
class TESWorldSpace;
class ExtraSeenData;
class NiAVObject;
struct CellSurfaceQuery;

struct CellFormVTable
{
    void* unknown00[11];
    void (*RemoveChange)(TESObjectCELL*, std::uint32_t);
};

class ExtraDataList
{
public:
    float GetNorthRotation();
    void SetSeenData(ExtraSeenData* data);

private:
    std::uint8_t unknown00[0x20];
};

struct LOADED_CELL_DATA
{
    std::uint8_t unknown000[0x16c];
    long criticalQueuedRefCount;
    long queuedRefCount;
};

class TESObjectCELL
{
public:
    float GetNorthRotation();
    void ClearSeenData();
    void DecrementQueuedRefs();
    void DecrementCriticalQueuedRefs();
    NiAVObject* ResolveQueryNode(const CellSurfaceQuery& query);

private:
    const CellFormVTable* vtable;
    std::uint8_t unknown008[0x38];
    std::uint16_t cellFlags;
    std::uint16_t cellGameFlags;
    std::uint8_t unknown044[4];
    ExtraDataList extraList;
    std::uint8_t unknown068[0xc0];
    TESWorldSpace* worldSpace;
    LOADED_CELL_DATA* loadedData;
};
