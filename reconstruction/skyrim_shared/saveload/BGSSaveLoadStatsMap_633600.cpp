// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x633600 BGSSaveLoadStatsMap::CloseFile
// Adapted bodies: none
#include "BGSSaveLoadStatsMap_633600.h"

// Deletes and clears the open stats file if present.
void BGSSaveLoadStatsMap::CloseFile()
{
    delete file;
    file = nullptr;
}
