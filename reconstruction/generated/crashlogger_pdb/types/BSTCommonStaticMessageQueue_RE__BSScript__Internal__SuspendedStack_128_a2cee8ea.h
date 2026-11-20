// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTCommonStaticMessageQueue<RE::BSScript::Internal::SuspendedStack, 128>; size 0x820
#pragma once

#include "BSTCommonMessageQueue_RE__BSScript__Internal__SuspendedStack_d5aadb0c.h"
struct BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea {
    BSTCommonMessageQueue_RE__BSScript__Internal__SuspendedStack_d5aadb0c _base;
    unsigned char queueBuffer[2048];
    unsigned int numEntries;
    unsigned int pushIdx;
    unsigned int popIdx;
    unsigned char undefined_81c[4];
};
static_assert(sizeof(BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea) == 2080, "BSTCommonStaticMessageQueue_RE__BSScript__Internal__SuspendedStack_128_a2cee8ea layout differs from the PDB");
