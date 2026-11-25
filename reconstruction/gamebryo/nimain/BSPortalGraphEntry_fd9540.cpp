// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSPortalGraphEntry, ClearRoomAccumList: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd9540 BSPortalGraphEntry::ClearRoomAccumList
#include "BSPortalGraphEntry_fd9540.h"

void BSPortalGraphEntry::ClearRoomAccumList()
{
    auto* ref = multiBoundRoomAccumList.data;
    if (ref) {
        const auto count = multiBoundRoomAccumList.size;
        if (count) {
            size_t remaining = count;
            do {
                ref->~RoomReference();
                ++ref;
            } while (--remaining);
        }
        multiBoundRoomAccumList.size = 0;
    }
}
