// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf1d380 NiAGDDataBlock::FreeBuffer
#include "NiAGDDataBlock.h"

extern void ReleaseGeometryBuffer(void*);

void NiAGDDataBlock::FreeBuffer()
{
    if (buffer.data != nullptr && ownsData != 0) {
        ReleaseGeometryBuffer(buffer.data);
    }
    buffer.data = nullptr;
    buffer.size = 0;
    flags = 0;
    ownsData = 0;
}
