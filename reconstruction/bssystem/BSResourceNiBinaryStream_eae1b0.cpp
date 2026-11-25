// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: BSResourceNiBinaryStream::Routine140C25690.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nisystem/console/nifile_console.cpp:37
// 0xeae1b0 BSResourceNiBinaryStream::Routine140C25690
// CI hash: 0xeae1b0 ?Routine140C25690@BSResourceNiBinaryStream@@QEAAIPEADI@Z
#include "BSResourceNiBinaryStream_eae1b0.h"

unsigned int BSResourceNiBinaryStream::Routine140C25690(char* buffer, unsigned int maxChars)
{
    unsigned int total = 0;
    unsigned int position = 0;
    while (position + 1 < maxChars)
    {
        char ch;
        unsigned int size = 1;
        unsigned int read = m_pfnRead(this, &ch, 1, &size, 1);
        m_uiStreamFlags += read;
        total += read;
        if (read == 1)
        {
            if (ch == '\n')
                break;
            if (ch != '\r')
                buffer[position++] = ch;
        }
        else
            break;
    }
    buffer[position] = 0;
    return total;
}
