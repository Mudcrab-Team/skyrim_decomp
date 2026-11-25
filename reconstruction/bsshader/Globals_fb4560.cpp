// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiBinaryStreamLoad.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsshaderpplightingproperty.cpp:573
// 0xfb4560 NiBinaryStreamLoad
#include "Globals_fb4560.h"

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& stream, T& value)
{
    unsigned int uiSize = sizeof(T);
    int iBytesRead = stream.m_pfnRead(&stream, &value, uiSize, &uiSize, 1);
    stream.m_uiBytesRead += iBytesRead;
}

template void NiBinaryStreamLoad<int>(struct NiBinaryStream &, int &);
