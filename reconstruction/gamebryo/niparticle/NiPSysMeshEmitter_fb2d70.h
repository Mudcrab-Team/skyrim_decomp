// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiPSysMeshEmitter: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysMeshEmitter::LoadBinary_140D1A750: CRASHLOGGER_PDB(59818@2026.10.24)
// vslot_0_, padding_8_, padding_0_: GUESS(low); placeholder name
#pragma once

struct NiBinaryStreamC1E;
struct NiStreamC1E;

class NiBinaryStreamC1E
{
  public:
    typedef unsigned int(* ReadFunc)(NiBinaryStreamC1E* pkThis, void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    virtual ~NiBinaryStreamC1E();
    unsigned int m_uiStreamFlags;
    ReadFunc m_pfnRead;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class NiStreamC1E
{
  public:
    char padding_0_[664];
    NiBinaryStreamC1E *m_pUnderlyingStream;
    void Func00a64670();
};

struct LoadableC1E
{
    void Func00a59be0(NiStreamC1E& kStream);
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class NiPSysMeshEmitter
{
  public:
    virtual void vslot_0_();
    char padding_8_[152];
    unsigned int m_uiValue74;
    unsigned int m_uiValue78;
    LoadableC1E m_kMember7C;
    void Func00c223b0(NiStreamC1E& kStream);
    void LoadBinary_140D1A750(NiStreamC1E& kStream);
};

template <class T>
inline unsigned int NiBinaryStreamLoad(NiBinaryStreamC1E& kBinStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int auiComponentSizes[1] = {sizeof(T)};
    return kBinStream.BinaryRead(pValue, uiNumEls * sizeof(T), auiComponentSizes, 1);
}

template <class T> inline T ReadC1E(NiBinaryStreamC1E& s)
{
    T v;
    NiBinaryStreamLoad(s, &v, 1);
    return v;
}
