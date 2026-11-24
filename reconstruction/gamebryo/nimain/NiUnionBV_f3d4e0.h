// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiUnionBV: CRASHLOGGER_PDB(59818@2026.10.24)
// NiUnionBV::Func1_140CA6860: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_: GUESS(low); placeholder name
#pragma once

struct NiBinaryStream;
struct NiSavable;
struct NiStream;

class NiBinaryStream
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NIBINARYSTREAM_WRITEFN m_pfnWrite;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class NiStream
{
  public:
    char padding_0_[672];
    NiBinaryStream *m_pBackingStream;
};


class NiSavable
{
  public:
    virtual void v0();
    virtual void SaveBinary(NiStream& kStream);
};

class NiUnionBV
{
  public:
    void* m_pvVtbl;
    int unk04;
    NiSavable** m_ppSavableObjects;
    unsigned short unk0c;
    unsigned short m_usElementCount;

    void SaveValueToStream(NiStream& kStream);
    void Func1_140CA6860(NiStream& kStream);
};


template <class T> inline void SerializeValue(NiBinaryStream& kStream, const T& tValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&tValue, sizeof(T), &uiSize, 1);
}
