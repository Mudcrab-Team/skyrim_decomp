// Source exposure: mixed (pinned image and community PDB destructor identification).
// Code origin: original representation of the deleting wrapper from the conditional deallocator generator.
// Adapted bodies: none
// BGSSaveLoadStatsMap: EXE_RTTI
// Complete destructor: CRASHLOGGER_PDB(59818@2026.10.24)
// storage: STANDIN OBSERVED; only the 60-byte sized-delete argument is known.
// Destroy, releaseStorage: GUESS(low)
// 0x636b80 BGSSaveLoadStatsMap::Destroy
// CI hash: 0x636b80 ?Destroy@BGSSaveLoadStatsMap@@SAPEAXPEAU1@I@Z
#include "BGSSaveLoadStatsMap_636b80.h"
#include <new>

void* BGSSaveLoadStatsMap::Destroy(BGSSaveLoadStatsMap* object, unsigned int flags)
{
    constexpr unsigned int releaseStorage = 0x1;
    object->~BGSSaveLoadStatsMap();
    if (flags & releaseStorage) {
        ::operator delete(object, sizeof(*object));
    }
    return object;
}
