// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ReadableStringTable; size 0x18
#pragma once

struct RE__BSTArray_RE__BSScript__ReadableStringTable__StringEntry_RE__BSScrapArrayAllocator_fbf43e9d;
struct ReadableStringTable {
    void* unk00;
    RE__BSTArray_RE__BSScript__ReadableStringTable__StringEntry_RE__BSScrapArrayAllocator_fbf43e9d* entries;
    unsigned char indexSize_raw[8];
};
static_assert(sizeof(ReadableStringTable) == 24, "ReadableStringTable layout differs from the PDB");
