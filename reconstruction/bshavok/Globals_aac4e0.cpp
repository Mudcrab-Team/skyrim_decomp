// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkBufferedStreamReader::isOk.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/system/io/reader/buffered/hkbufferedstreamreader.cpp:317
// 0xaac4e0 hkBufferedStreamReader::isOk
#include "Globals_aac4e0.h"

hkBool hkBufferedStreamReader::isOk()
{
    unsigned char byte;
    return hkBool(pos != end || *reader->v3(&byte) != 0);
}
