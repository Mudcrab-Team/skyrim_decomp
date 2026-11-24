// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkMemoryStreamReader::Routine140BDE540.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/system/io/reader/memory/hkmemorystreamreader.cpp:207
// 0xcba5e0 hkMemoryStreamReader::Routine140BDE540
// CI hash: 0xcba5e0 ?Routine140BDE540@hkMemoryStreamReader@@QEAAHPEAXH@Z
#include "Globals_cba5e0.h"

int hkMemoryStreamReader::Routine140BDE540(void* destination, int count)
{
    unsigned char state;
    if (*checkState(&state))
    {
        int remaining = m_10 - m_0c;
        int copied = count < remaining ? count : remaining;
        Func00cb1260(destination, m_08 + m_0c, copied);
        m_0c += copied;
        if (copied == 0 && count != 0)
            m_0c = m_10 + 1;
        return copied;
    }
    return 0;
}
