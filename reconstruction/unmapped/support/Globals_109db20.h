// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// bhkRagdollTemplate: CRASHLOGGER_PDB(59818@2026.10.24)
// bhkRagdollTemplate::SaveBinary_140DF5050: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_1_, padding_20_, vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_, vslot_9_, vslot_10_, vslot_11_, padding_8_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct BCB9F60BinaryStream;
struct BCB9F60Stream;

class BCB9F60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(* m_pfnRead)(BCB9F60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(* m_pfnWrite)(BCB9F60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class BCB9F60Stream
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void vslot_2_();
    virtual void vslot_3_();
    virtual void vslot_4_();
    virtual void vslot_5_();
    virtual void vslot_6_();
    virtual void vslot_7_();
    virtual void vslot_8_();
    virtual void vslot_9_();
    virtual void vslot_10_();
    virtual void vslot_11_();
    virtual void SaveLinkID(void* pkObject);
    char padding_8_[664];
    BCB9F60BinaryStream *m_pBackingStream;
};


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class BCB9F60ExtraData
{
  public:
    void SaveBinary(BCB9F60Stream& kStream);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class bhkRagdollTemplate : BCB9F60ExtraData
{
  public:
    char padding_1_[23];
    void **m_ppkObjects;
    char padding_20_[8];
    unsigned int m_uiCount;
    void SaveBinary_140DF5050(BCB9F60Stream& kStream);
};


template <class T>
inline void BCB9F60BinaryStreamSave(BCB9F60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BCB9F60SaveBinary(BCB9F60Stream& kStream, const T& value)
{
    BCB9F60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

struct Globals
{
};
