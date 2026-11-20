// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTObjectArena<RE::BSResource::RHandleType<RE::BSResource::Entry<RE::NiPointer<RE::NiNode>, RE::BSResource::EntryDBTraits<RE::BSModelDB::DBTraits, RE::BSResource::EntryDB<RE::BSModelDB::DBTraits>>::CArgs>, RE::BSResource::EntryDB<RE::BSModelDB::DBTraits>>, RE::BSTObjectArenaHeapAlloc, 16>; size 0x38
#pragma once

#include "BSTObjectArenaHeapAlloc.h"
struct BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc {
    BSTObjectArenaHeapAlloc _base;
    unsigned char undefined_1[7];
    char32_t** _next;
    unsigned char _tail_raw[8];
    unsigned char _free_raw[8];
    unsigned char* _end;
    unsigned char* _begin;
    unsigned int _size;
    unsigned char undefined_34[4];
};
static_assert(sizeof(BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc) == 56, "BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc layout differs from the PDB");
