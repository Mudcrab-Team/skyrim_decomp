// Source exposure: mixed (pinned image and community PDB destructor identification).
// Code origin: original representation of the deleting wrapper from the conditional deallocator generator.
// Adapted bodies: none
// BGSSaveLoadStatsMap: EXE_RTTI
// Complete destructor: CRASHLOGGER_PDB(59818@2026.10.24)
// storage: STANDIN OBSERVED; only the 60-byte sized-delete argument is known.
// Destroy, releaseStorage: GUESS(low)
#pragma once

struct BGSSaveLoadStatsMap
{
    ~BGSSaveLoadStatsMap();
    static void* Destroy(BGSSaveLoadStatsMap* object, unsigned int flags);

    unsigned char storage[60];
};
