// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSTempEffectDebris, BSTempEffectDebris::AddtoDebrisCounter: CRASHLOGGER_PDB(59818@2026.10.24)
// DebrisListNode, DebrisList, gDebrisList, AllocNode, AddTail, prev, next, element, tail, head, count: GUESS(low)
#pragma once

#include <cstdint>

class BSTempEffectDebris;

struct DebrisListNode
{
    DebrisListNode* prev;         // 00
    DebrisListNode* next;         // 08
    BSTempEffectDebris* element;  // 10
};

class DebrisList
{
public:
    virtual ~DebrisList();
    virtual DebrisListNode* AllocNode();  // slot 01 (+0x08)

    void AddTail(BSTempEffectDebris* a_item)
    {
        DebrisListNode* node = AllocNode();
        node->element = a_item;
        node->next = nullptr;
        node->prev = tail;

        if (tail) {
            tail->next = node;
        } else {
            head = node;
        }
        ++count;
        tail = node;
    }

    DebrisListNode* tail;  // 08
    DebrisListNode* head;  // 10
    std::uint32_t count;   // 18
};

extern DebrisList gDebrisList;

class BSTempEffectDebris
{
public:
    static void AddtoDebrisCounter(BSTempEffectDebris* a_debris);  // compared: 0x4aa870
};
