// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x1218160 MovementMessageWarpToMultiple::Func2_1411040B0
#include "MovementMessageWarpToMultiple_1218160.h"

// Writes the entry count and serializes each warp entry through the writer interface.
void MovementMessageWarpToMultiple::Func2_1411040B0(MovementStreamWriter* writer)
{
    std::uint32_t count = size;
    writer->WriteCount(count);
    for (std::uint32_t i = 0; i < count; ++i)
    {
        MovementWarpEntry* entry = &entries[i];
        entry->WriteEntry(writer);
    }
}
