// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: StreamBufferD27210::FlushToDestination.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/system/io/writer/buffered/hkbufferedstreamwriter.cpp:180
// 0xaaccf0 StreamBufferD27210::FlushToDestination
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/common/base/system/io/writer/buffered/hkbufferedstreamwriter.cpp:171
#include "StreamBufferD27210_aaccf0.h"

int StreamBufferD27210::FlushToDestination()
{
    if (m_destination != 0)
    {
        int written = 0;
        int remaining = m_vContactPosition;
        while (written < remaining)
        {
            int count = m_destination->Write(m_buffer + written, remaining - written);
            written += count;
            if (count == 0)
                return written;
        }
        m_vContactPosition = 0;
        return written;
    }
    return 0;
}
