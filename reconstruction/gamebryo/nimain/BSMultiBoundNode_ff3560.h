// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryStreamLoad: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_, padding_c_: GUESS(low); placeholder name
// BSMultiBoundNode: GUESS(low); placeholder name
#pragma once

struct NiBinaryStream;
struct NiStream;


// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct NiBinaryStream
{
  public:
    char padding_0_[8];
    unsigned int m_uiBytesRead;
    char padding_c_[12];
    int(* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, int);
};

struct NiStream
{
    unsigned int m_uiUnknown;
    unsigned int version;
    unsigned char m_ucPadding[0x244];
    NiBinaryStream* m_pUnderlyingStream;

    void ResetStreamState();
};

struct Helper
{
    void Func00b70260(NiStream& stream);
};

struct BSMultiBoundNode
{
};
