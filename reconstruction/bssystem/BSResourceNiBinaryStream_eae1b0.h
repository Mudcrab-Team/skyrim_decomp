// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSResourceNiBinaryStream: CRASHLOGGER_PDB(59818@2026.10.24)
// BSResourceNiBinaryStream::Routine140C25690: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

class BSResourceNiBinaryStream
{
  public:
    typedef unsigned int(* READFUNC)(BSResourceNiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    typedef unsigned int(* WRITEFUNC)(BSResourceNiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    virtual ~BSResourceNiBinaryStream();
    unsigned int m_uiStreamFlags;
    READFUNC m_pfnRead;
    WRITEFUNC m_pfnWrite;
    unsigned int Routine140C25690(char* buffer, unsigned int maxChars);
};
