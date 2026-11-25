// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// HavokFileStreambufReader, HavokFileStreambufReader::~HavokFileStreambufReader: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

namespace f3m_0056b360 {


struct hkBaseObject
{
    virtual ~hkBaseObject() {}
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
};

struct HavokFileStreambufReader : hkBaseObject
{
    hkBaseObject* m_pObject;   // +0x08
    bool m_bOwnObject;         // +0x0c
    virtual ~HavokFileStreambufReader();
};

}
