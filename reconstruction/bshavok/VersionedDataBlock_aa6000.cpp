// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: VersionedDataBlock::ReadBytes.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/system/io/reader/hkstreamreader.cpp:16
// 0xaa6000 VersionedDataBlock::ReadBytes
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/common/base/system/io/reader/hkstreamreader.cpp:20
#include "VersionedDataBlock_aa6000.h"

int VersionedDataBlock::ReadBytes(int size)
{
    unsigned int buffer[128];
    int remaining = size;
    while (remaining)
    {
        int count = Read(buffer, remaining > 512 ? 512 : remaining);
        if (!count)
            break;
        remaining -= count;
    }
    return size - remaining;
}
