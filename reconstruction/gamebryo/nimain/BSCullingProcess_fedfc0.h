// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// BSCullingProcess layout, AppendVirtual, AppendNonAccum, PopFreeQueueEntry and PushQueueEntry: CRASHLOGGER_PDB(59818@2026.10.24)
// CullEntry, CullQueue, pending and freeEntries: GUESS(low) STANDIN
#pragma once

struct BSGeometry;
struct BSCullingProcess;
struct CullEntry {
    BSGeometry* geometry;
    unsigned int argument;
    unsigned int group;
};
struct CullQueue {
    CullEntry* PopFreeQueueEntry();
    void PushQueueEntry(CullEntry* entry);
};
struct CullingMethods {
    void* preceding[25];
    void (*AppendNonAccum)(BSCullingProcess*, BSGeometry*, unsigned int);
};
struct BSCullingProcess {
    CullingMethods* methods;
    unsigned char unknown08[0x10138];
    CullQueue pending;
    unsigned char unknown10141[0x1000F];
    CullQueue freeEntries;
    unsigned char unknown20151[0x10084];
    bool isGroupingAlphas;
    unsigned char unknown301D6[0x1E];
    unsigned int alphaGroupStopIndex;
    void AppendVirtual(BSGeometry* geometry, unsigned int argument);
};
