// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfc21d0 NiPSysCollider::NiPSysCollider
// Adapted bodies: none
#include "NiObject_fc21d0.h"

NiPSysCollider::NiPSysCollider() :
    m_fBounceFactor(1.0f),
    m_bSpawnOnCollision(false),
    m_bDieOnCollision(false),
    m_pSpawnModifier(nullptr),
    m_kCollisionPosition(NiPoint3::ZERO),
    m_fSpawnRate(0.0f),
    m_pColliderManager(nullptr),
    m_spNextController(nullptr)
{
}
