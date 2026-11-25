// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// A3D370LoadEnum: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_: GUESS(low); placeholder name
// NiControllerSequence: GUESS(low); placeholder name
#pragma once

struct A3D370BinaryStream;
struct A3D370Stream;

class A3D370BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(* m_pfnRead)(A3D370BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class A3D370Stream
{
  public:
    char padding_0_[664];
    A3D370BinaryStream *m_pUnderlyingStream;
};



template <class T> inline void A3D370BinaryStreamLoad(A3D370BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A3D370LoadBinary(A3D370Stream& kStream, T& value)
{
    A3D370BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

struct NiControllerSequence
{
};
