// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSPortalGraphEntry, ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd92c0 BSPortalGraphEntry::BSPortalGraphEntry
#include "BSPortalGraphEntry_fd92c0.h"

BSPortalGraphEntry::BSPortalGraphEntry() :
    visibleUnboundSpace(true), enableAccumulation(true)
{
    portalGraph = nullptr;
    cellId = 0;
}
