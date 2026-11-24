// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiPoint3, NiPSysCollider, NiPSysSpawnModifier, NiPSysColliderManager: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal stand-ins, only what this unit touches
// _refCount, _pad0C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiRefObject members, declared here instead of a base class
// x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_fBounceFactor, m_bSpawnOnCollision, m_bDieOnCollision, m_pSpawnModifier, m_kCollisionPosition, m_fSpawnRate, m_pColliderManager, m_spNextController: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// ZERO: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); the three floats the constructor copies from one global point
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

class NiPoint3
{
public:
    NiPoint3(const NiPoint3& a_rhs) :
        x(a_rhs.x),
        y(a_rhs.y),
        z(a_rhs.z)
    {
    }

    static const NiPoint3 ZERO;

    float x;  // 00
    float y;  // 04
    float z;  // 08
};

class NiPSysSpawnModifier;
class NiPSysColliderManager;

class NiPSysCollider : public NiObject
{
public:
    NiPSysCollider();  // compared: 0xfc21d0
    ~NiPSysCollider() override;

    float                  m_fBounceFactor;       // 10
    bool                   m_bSpawnOnCollision;   // 14
    bool                   m_bDieOnCollision;     // 15
    NiPSysSpawnModifier*   m_pSpawnModifier;      // 18
    NiPoint3               m_kCollisionPosition;  // 20
    float                  m_fSpawnRate;          // 2C
    NiPSysColliderManager* m_pColliderManager;    // 30
    NiPSysCollider*        m_spNextController;    // 38; a smart pointer in the sibling, a plain pointer here
};
static_assert(sizeof(NiPSysCollider) == 0x40, "NiPSysCollider size differs from the observed layout");
