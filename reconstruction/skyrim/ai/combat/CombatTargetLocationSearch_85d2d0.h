// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// CombatTargetLocationSearch, CombatObject, array1, array2: CRASHLOGGER_PDB(59818@2026.10.24)
// SearchArrayAllocator, SearchArrayBase, SearchArray, FreeData, unknown08, result, rest: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class SearchArrayAllocator
{
public:
    ~SearchArrayAllocator();
    void FreeData();

    void* data;
    std::uint32_t capacity;
    std::uint32_t reserved0C;
};

class SearchArrayBase
{
public:
    ~SearchArrayBase();

    std::uint32_t size;
};

class SearchArray : public SearchArrayAllocator, public SearchArrayBase
{
public:
    ~SearchArray()
    {
        if (data) {
            FreeData();
            size = 0;
        }
    }
};
static_assert(sizeof(SearchArray) == 0x18, "SearchArray size");

class CombatObject
{
public:
    virtual ~CombatObject();

    std::uint64_t unknown08;
};
static_assert(sizeof(CombatObject) == 0x10, "CombatObject size");

class CombatTargetLocationSearch : public CombatObject
{
public:
    CombatTargetLocationSearch();  // implicit deleting dtor compared: 0x85d2d0

    void* result;             // 10
    SearchArray array1;       // 18
    SearchArray array2;       // 30
    std::uint8_t rest[0x30];  // 48
};
static_assert(sizeof(CombatTargetLocationSearch) == 0x78, "CombatTargetLocationSearch size");
static_assert(offsetof(CombatTargetLocationSearch, array1) == 0x18, "array1 offset");
static_assert(offsetof(CombatTargetLocationSearch, array2) == 0x30, "array2 offset");
