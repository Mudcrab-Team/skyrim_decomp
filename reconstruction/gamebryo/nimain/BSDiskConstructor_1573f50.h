// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSDiskConstructor, BSDiskConstructor::~BSDiskConstructor: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

struct ShadowSceneLight;

class BSDiskConstructor
{
  public:
    virtual ~BSDiskConstructor();
    ShadowSceneLight** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    BSDiskConstructor();
};
