// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// SetupCullingJobManager2_140D51AF0: CRASHLOGGER_PDB(59818@2026.10.24)
// CullJobManager, jobStorage, workerCount, Initialize: GUESS(low) STANDIN
#pragma once

struct CullJobManager {
    void Initialize(void* storage, unsigned int first, unsigned int capacity,
                    unsigned int limit, unsigned int groupCount, unsigned int workers,
                    bool background, void* allocator, bool delayed);
};
extern unsigned char jobStorage;
extern unsigned int workerCount;
