// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// RegionData2556f0, RegionDataList2556f0, Region2556f0, Node2556f0, ListOwner2556f0, Obj2556f0, IsValid, FindByType, HasRegionData, dataList, item, next, head: GUESS(low)
#pragma once

#include <cstdint>

struct RegionData2556f0
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual bool IsValid();  // 38
};

struct RegionDataList2556f0
{
    RegionData2556f0* FindByType(std::uint32_t type);
};

struct Region2556f0
{
    std::uint8_t unk00[0x20];        // 00
    RegionDataList2556f0* dataList;  // 20
};

struct Node2556f0
{
    Region2556f0* item;  // 00
    Node2556f0* next;    // 08
};

struct ListOwner2556f0
{
    std::uint64_t unk00;  // 00
    Node2556f0 head;      // 08
};

class Obj2556f0
{
public:
    static bool HasRegionData(ListOwner2556f0* owner, std::uint32_t type, bool requireValid);
};
