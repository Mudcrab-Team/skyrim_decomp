// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpMoppBvTreeShape: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpMoppBvTreeShape::Func2_140A62F10: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_1_, padding_30_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

class hkClassD543;

extern const hkClassD543 Data01269c8c;

class hkStatisticsCollectorD543
{
  public:
    virtual ~hkStatisticsCollectorD543() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpShapeD543
{
  public:
    void Func00c90360(hkStatisticsCollectorD543* pkCollector, const hkClassD543* pkClass) const;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpMoppBvTreeShape : hkpShapeD543
{
  public:
    char padding_1_[39];
    const void *m_pMoppCode;
    char padding_30_[40];
    const void *m_pContainedShape;
    void Func2_140A62F10(hkStatisticsCollectorD543* pkCollector, const hkClassD543* pkClass) const;
};

struct Globals
{
};
