// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSPortalGraphEntry, FindVisibility: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd9900 BSPortalGraphEntry::FindVisibility
#include "BSPortalGraphEntry_fd9900.h"

BSCompoundFrustum* BSPortalGraphEntry::FindVisibility(NiNode* node) const
{
    BSReadLockGuard guard(portalVisibilityLock);
    BSCompoundFrustum* result = nullptr;
    unsigned int hash;
    CRC32Calculator::SizeOf64(hash, reinterpret_cast<std::uint64_t>(node));
    if (visibilityMap.entries) {
        auto* entry = &visibilityMap.entries[(visibilityMap.capacity - 1) & hash];
        if (entry->next) {
            do {
                if (entry->key == node) {
                    result = entry->value;
                    break;
                }
                entry = entry->next;
            } while (entry != visibilityMap.sentinel);
        }
    }
    return result;
}
