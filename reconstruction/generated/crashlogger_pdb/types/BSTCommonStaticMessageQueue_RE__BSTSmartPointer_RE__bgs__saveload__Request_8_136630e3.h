// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTCommonStaticMessageQueue<RE::BSTSmartPointer<RE::bgs::saveload::Request>, 8>; size 0x60
#pragma once

#include "BSTCommonMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_72f4fb18.h"
struct BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3 {
    BSTCommonMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_72f4fb18 _base;
    unsigned char queueBuffer[64];
    unsigned int numEntries;
    unsigned int pushIdx;
    unsigned int popIdx;
    unsigned char undefined_5c[4];
};
static_assert(sizeof(BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3) == 96, "BSTCommonStaticMessageQueue_RE__BSTSmartPointer_RE__bgs__saveload__Request_8_136630e3 layout differs from the PDB");
