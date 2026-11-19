// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// BSPathing, BSPathing::~BSPathing, BSPathing::GetPotentialNavMeshInfoForLocation, BSPathing::GetAllLoadedNavmeshes1, BSPathing::GetAllLoadedNavmeshes2, BSPathing::GetAllLoadedNavmeshes3, BSPathing::GetAllLoadedNavmeshes4, BSPathing::GetAllLoadedNavmeshes5, BSPathing::GetSelectedDebugRef, BSPathing::GetPathingDoorFromCollision: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// BSNavmeshInfo, PathingCell, NiAVObject: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); forward declarations only
// BSTSingletonExplicit: STANDIN GUESS(low)
// BSTArray, BSScrapArray, BSTSmartPointer, BSTScrapHashMap, BSNavmesh, BSPathingDoor: GUESS(low); forward declarations only
// BSPathingFilter, BSPathingFilter::instance, BSPathing::filter, unknown08, unknown0c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSNavmeshInfo;
class PathingCell;
class NiAVObject;
class BSNavmesh;
class BSPathingDoor;

template <class T>
class BSTArray;
template <class T>
class BSScrapArray;
template <class T>
class BSTSmartPointer;
template <class K, class V>
class BSTScrapHashMap;

class BSTSingletonExplicit
{
};

// Polymorphic subobject at offset 0x08. Its destructor clears one global qword, which the target
// stores after the vftable store at 0x08, so the clear belongs to this subobject's teardown.
class BSPathingFilter
{
public:
    virtual ~BSPathingFilter();  // 00
    static void* instance;       // cleared by the destructor; meaning unknown

    std::uint32_t unknown08;  // 08
    std::uint32_t unknown0c;  // 0C
};
static_assert(sizeof(BSPathingFilter) == 0x10, "BSPathingFilter size");

class BSPathing : public BSTSingletonExplicit
{
public:
    virtual ~BSPathing();  // compared: 0x11c52e0  // slot 00
    virtual BSTArray<BSNavmeshInfo*> GetPotentialNavMeshInfoForLocation(PathingCell* a_cell) = 0;  // 01
    virtual bool GetAllLoadedNavmeshes1(BSTScrapHashMap<std::uint32_t, BSTSmartPointer<BSNavmesh>>& a_retNavMeshes) = 0;  // 02
    virtual bool GetAllLoadedNavmeshes2(BSScrapArray<BSNavmeshInfo*>& a_retNavMeshes) = 0;  // 03
    virtual bool GetAllLoadedNavmeshes3(BSTArray<BSNavmeshInfo*>& a_retNavMeshes) = 0;  // 04
    virtual bool GetAllLoadedNavmeshes4(BSScrapArray<BSTSmartPointer<BSNavmesh>>& a_retNavMeshes) = 0;  // 05
    virtual bool GetAllLoadedNavmeshes5(BSTArray<BSTSmartPointer<BSNavmesh>>& a_retNavMeshes) = 0;  // 06
    virtual std::uint32_t GetSelectedDebugRef() = 0;  // 07
    virtual bool GetPathingDoorFromCollision(NiAVObject* a_object, BSTSmartPointer<BSPathingDoor>& a_retDoor) = 0;  // 08
    BSPathing();

    BSPathingFilter filter;  // 08
};
static_assert(sizeof(BSPathing) == 0x18, "BSPathing size");
