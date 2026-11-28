// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// IsFavoriteVisitor242390: CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraList242390, ExtraListNode242390, Entry242390, Visit, HasHotkey, extraList, next, object, extraLists, targetForm, isFavorite: GUESS(low)
#pragma once

#include <cstdint>

struct ExtraList242390
{
    bool HasHotkey() const;
};

struct ExtraListNode242390
{
    ExtraList242390* extraList;  // 00
    ExtraListNode242390* next;   // 08
};

struct Entry242390
{
    void* object;                     // 00
    ExtraListNode242390* extraLists;  // 08
};

class IsFavoriteVisitor242390
{
public:
    virtual ~IsFavoriteVisitor242390();
    virtual std::uint32_t Visit(Entry242390* entry);

    void* targetForm;  // 08
    bool isFavorite;   // 10
};
