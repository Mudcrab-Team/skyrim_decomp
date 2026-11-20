// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LinkerProcessor; size 0x90
#pragma once

#include "BSTArray_RE__detail__BSFixedString_char_RE__BSScrapArrayAllocator_0f80ae1e.h"
#include "IObjectProcessor.h"
struct BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_18371206;
struct ErrorLogger;
struct ILoader;
struct IVirtualMachine;
struct LinkerProcessor {
    IObjectProcessor _base;
    IVirtualMachine* vm;
    ErrorLogger* errorHandler;
    ILoader* loader;
    bool allowRelinking;
    unsigned char undefined_21[7];
    BSTArray_RE__detail__BSFixedString_char_RE__BSScrapArrayAllocator_0f80ae1e loadedParents;
    BSTArray_RE__detail__BSFixedString_char_RE__BSScrapArrayAllocator_0f80ae1e objectsToTypecheck;
    BSTArray_RE__detail__BSFixedString_char_RE__BSScrapArrayAllocator_0f80ae1e processQueue;
    BSTScatterTable_RE__BSCRC32_RE__detail__BSFixedString_char_std__equal_to_RE__detail__BS_18371206* classMap;
};
static_assert(sizeof(LinkerProcessor) == 144, "LinkerProcessor layout differs from the PDB");
