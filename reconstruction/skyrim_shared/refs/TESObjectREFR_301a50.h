// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESObjectREFR, TESObjectREFR::Function301a50, ExtraDataList, ExtraDataList::Function16a760, TrackedPoint, PrimitiveData, gKindA, gKindB, gDefaultPoint: GUESS(low)
// ExtraDataList::GetPrimitive: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); declared here as a stand-in
#pragma once

#include <cstdint>
#include <cstddef>

struct Point3
{
    float x;
    float y;
    float z;
};

struct TrackedPoint
{
    std::uint8_t unk00[0x10];
    Point3 point;
};

struct PrimitiveData
{
    std::uint8_t unk00[0xC];
    Point3 point;
};

class ExtraDataList
{
public:
    TrackedPoint* Function16a760();
    PrimitiveData* GetPrimitive();
};

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x40];
    void* baseObject;
    std::uint8_t unk48[0x28];
    ExtraDataList extraList;
    Point3* Function301a50();
};

extern void* gKindA;
extern void* gKindB;
extern Point3 gDefaultPoint;
