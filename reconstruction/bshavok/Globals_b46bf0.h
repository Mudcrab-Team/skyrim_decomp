// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpSingleShapeContainerCF58: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// hkpSingleShapeContainerCF58::AddChildShapeToCollector: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_1_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

class hkClassCF58;

extern const hkClassCF58 Data01268910;

class hkStatisticsCollectorCF58
{
  public:
    virtual ~hkStatisticsCollectorCF58() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpShapeCF58
{
  public:
    void Func00c90360(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
class hkpSingleShapeContainerCF58 : hkpShapeCF58
{
  public:
    char padding_1_[39];
    const void *m_pContainedShape;
    void AddChildShapeToCollector(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const;
};

struct Globals
{
};
