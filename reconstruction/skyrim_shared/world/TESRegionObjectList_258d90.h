// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionObjectList.cpp:287
// TESRegionObjectList, TESRegionObjectList::Copy, TESRegionObjectList::Add, TESRegionObjectList::bOwnsTESRegionObjectMemory, TESRegionObjectList::iCount: SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionObject, TESRegionObject::Copy: STANDIN SIBLING(fo4-private@1b765c70, author-permission); reduced to the members the body calls
// RegionObjectNode, m_item, m_pkNext: STANDIN GUESS(low); the BSSimpleList node base of the object list
// MemMgrGuard_369ac98, MemMgrInst_369a810, MemMgrEnsure_cde810, MemMgrAlloc_cde250: GUESS(low); the memory manager singleton guard, instance, init and allocation callees, named by address
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
}

class TESRegionObject
{
public:
    virtual ~TESRegionObject();

    TESRegionObject* Copy(bool a_flag, void* a_arg2);
};

struct RegionObjectNode
{
    RegionObjectNode() : m_item(nullptr), m_pkNext(nullptr) {}

    TESRegionObject* m_item;       // 00
    RegionObjectNode* m_pkNext;    // 08
};

class TESRegionObjectList : public RegionObjectNode
{
public:
    explicit TESRegionObjectList(bool abOwnsTESRegionObjectMemory) : RegionObjectNode()
    {
        bOwnsTESRegionObjectMemory = abOwnsTESRegionObjectMemory;
        iCount = 0;
    }
    virtual ~TESRegionObjectList();

    // The allocation goes through the memory manager singleton, initialised on first use.
    static void* operator new(std::size_t size) throw()
    {
        if (MemMgrGuard_369ac98 != 2u)
            MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
        return MemMgrAlloc_cde250(MemMgrInst_369a810, size, 0u, false);
    }

    TESRegionObjectList* Copy(TESRegionObjectList* apCopyInto);
    bool Add(TESRegionObject* apObject);

    bool bOwnsTESRegionObjectMemory;  // 18
    std::uint32_t iCount;             // 1C
};
