// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00d86100: GUESS(low); placeholder name
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct DataD861;
struct NiBinaryStreamD861;
struct NiStreamD861;

struct NiBinaryStreamD861 {
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    unsigned int (* m_pfnWrite)(NiBinaryStreamD861* pkStream, const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiStreamD861
{
  public:
    char padding_0_[664];
    NiBinaryStreamD861 *m_pBackingStream;
};


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct DataD861
{
  public:
    char padding_0_[24];
    unsigned int m_0c;
    unsigned int m_10;
};


template <class T>
inline void NiStreamSaveBinaryD861(NiBinaryStreamD861& kStream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}

struct Globals
{
};
