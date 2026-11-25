// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkDefaultMemoryTracker: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionabeb00: GUESS(low); provisional member name
// 0xabeb00 hkDefaultMemoryTracker::Functionabeb00
// CI hash: 0xabeb00 ?Functionabeb00@hkDefaultMemoryTracker@@QEAAPEAXPEAX@Z
#include "hkDefaultMemoryTracker_abeb00.h"

// Guess: Look up a memory-tracker entry under its critical section.
void* hkDefaultMemoryTracker::Functionabeb00(void* key)
{
    EnterTrackerLock(&lock);
    void* result = table.Find(key, 0);
    LeaveTrackerLock(&lock);
    return result;
}
