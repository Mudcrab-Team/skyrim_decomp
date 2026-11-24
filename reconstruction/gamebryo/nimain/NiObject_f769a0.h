// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiBSplineBasisData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal stand-ins, only the slots and members this unit touches
// BSplineBasis: GUESS(low); template stand-in modelled on the PDB facts layout
// m_kBSplineBasis, m_iNumControlPoints, m_afWeights, m_fLastTime, m_iMinControlPoint, m_iMaxControlPoint: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// _refCount, _pad0C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiRefObject members, declared here instead of a base class
#pragma once

#include <cstdint>
#include <cstddef>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    volatile std::uint32_t _refCount;  // 08
    std::uint32_t          _pad0C;     // 0C
};
static_assert(sizeof(NiObject) == 0x10, "NiObject layout differs from the community header");

template <class T, int Degree>
class BSplineBasis
{
public:
    BSplineBasis() :
        m_iNumControlPoints(0),
        m_fLastTime(-1.0f),
        m_iMinControlPoint(0),
        m_iMaxControlPoint(Degree)
    {
    }

    std::int32_t m_iNumControlPoints;     // 00
    T            m_afWeights[Degree + 1];  // 04
    T            m_fLastTime;             // 14
    std::int32_t m_iMinControlPoint;      // 18
    std::int32_t m_iMaxControlPoint;      // 1C
};

class NiBSplineBasisData : public NiObject
{
public:
    NiBSplineBasisData();  // compared: 0xf769a0
    ~NiBSplineBasisData() override;

    BSplineBasis<float, 3> m_kBSplineBasis;  // 10
};
static_assert(sizeof(NiBSplineBasisData) == 0x30, "NiBSplineBasisData layout differs from the PDB facts");
