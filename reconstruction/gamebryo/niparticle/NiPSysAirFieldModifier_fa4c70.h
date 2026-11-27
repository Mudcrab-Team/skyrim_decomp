// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiPSysAirFieldModifier: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysAirFieldModifier::SaveBinary_140D0D7A0: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_1_, padding_6c_, padding_83_, padding_0_: GUESS(low); placeholder name
#pragma once

struct NiBinaryStream;
struct NiStream;

struct NiBinaryStream
{
    typedef unsigned int(* WriteFn)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* unk08;
    WriteFn m_pfnWrite;

    unsigned int BinaryWrite(const void* pv, unsigned int uiBytes, unsigned int* puiSizes, unsigned int uiElementCount)
    {
        unsigned int uiWritten = m_pfnWrite(this, pv, uiBytes, puiSizes, uiElementCount);
        m_uiStreamFlags += uiWritten;
        return uiWritten;
    }
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiStream
{
  public:
    char padding_0_[672];
    NiBinaryStream *m_pBackingStream;
};


struct NiColor
{
    float r, g, b;
    void SaveBinary(NiStream& stream);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiPSysFieldModifierBase
{
  public:
    void SaveBinary(NiStream& stream);
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiPSysAirFieldModifier : NiPSysFieldModifierBase
{
  public:
    char padding_1_[95];
    NiColor m_kFogTint;
    char padding_6c_[12];
    float m_f58;
    float m_f5C;
    bool m_b60;
    bool m_b61;
    bool m_b62;
    char padding_83_[1];
    float m_f64;
    void SaveBinary_140D0D7A0(NiStream& stream);
};


template <class T> inline void SerializeValue(NiBinaryStream* pkStr, const T& value)
{
    unsigned int uiSize = sizeof(T);
    pkStr->BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
