// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPoint3, BSPathingCell, BSNavmeshInfo, BSPathingLocation: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3::x, NiPoint3::y, NiPoint3::z, BSPathingLocation::location, BSPathingLocation::navMeshInfo, BSPathingLocation::navMeshInfoArray, BSPathingLocation::pathingCell, BSPathingLocation::triangle, BSPathingLocation::flags, BSPathingLocation::clientData: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingCell::unk00, BSPathingCell::refCount, BSPathingCell::IncRef, BSTSmartPointer, BSTSmartPointer::_ptr, BSNavmeshInfo::unk00, BSNavmeshInfo::pathingCell, BSPathingLocation::unk0C, BSPathingLocation::unk2C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

struct NiPoint3
{
    NiPoint3(const NiPoint3& a_rhs) :
        x(a_rhs.x),
        y(a_rhs.y),
        z(a_rhs.z)
    {}

    float x;
    float y;
    float z;
};

class BSPathingCell
{
public:
    void IncRef()
    {
        // atomic reference count increment required by intrusive smart pointers
        _InterlockedIncrement(&refCount);
    }

    std::uint64_t unk00;
    long refCount;
};

template <class T>
struct BSTSmartPointer
{
    BSTSmartPointer(const BSTSmartPointer& a_rhs) :
        _ptr(a_rhs._ptr)
    {
        if (a_rhs._ptr) {
            a_rhs._ptr->IncRef();
        }
    }

    T* _ptr;
};

struct BSNavmeshInfo
{
    std::uint8_t unk00[0x38];
    BSTSmartPointer<BSPathingCell> pathingCell;
};
static_assert(offsetof(BSNavmeshInfo, pathingCell) == 0x38, "pathingCell offset");

class BSPathingLocation
{
public:
    BSPathingLocation(const NiPoint3& a_location, BSNavmeshInfo* a_navMeshInfo);

    NiPoint3 location;
    std::uint32_t unk0C;
    BSNavmeshInfo* navMeshInfo;
    void* navMeshInfoArray;
    BSTSmartPointer<BSPathingCell> pathingCell;
    std::uint16_t triangle;
    std::uint8_t flags;
    std::uint8_t clientData;
    std::uint32_t unk2C;
};
static_assert(offsetof(BSPathingLocation, navMeshInfo) == 0x10, "navMeshInfo offset");
static_assert(offsetof(BSPathingLocation, pathingCell) == 0x20, "pathingCell offset");
static_assert(offsetof(BSPathingLocation, triangle) == 0x28, "triangle offset");
static_assert(sizeof(BSPathingLocation) == 0x30, "BSPathingLocation size");
