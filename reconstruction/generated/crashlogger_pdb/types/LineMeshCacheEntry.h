// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LineMeshCacheEntry; size 0x20
#pragma once

struct LineMeshContainer;
struct LineMeshCacheEntry {
    void* next;
    void* prev;
    LineMeshContainer* container;
    void* owner;
};
static_assert(sizeof(LineMeshCacheEntry) == 32, "LineMeshCacheEntry layout differs from the PDB");
