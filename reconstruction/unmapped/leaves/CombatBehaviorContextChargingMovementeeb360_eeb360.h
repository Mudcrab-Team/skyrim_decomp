// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorChargingMovement.cpp:207
// CombatObject, spChargeTargetLocation, SetChargeTargetLocation: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// DeleteThis: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatBehaviorContextChargingMovementeeb360, m_uiRefCount, unk00: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class CombatObject
{
public:
    virtual ~CombatObject();
    virtual void DeleteThis();
    
    std::uint32_t m_uiRefCount;
};

class CombatBehaviorContextChargingMovementeeb360
{
public:
    void SetChargeTargetLocation(CombatObject* a_location);  // compared: 0xeeb360

    // Smart-pointer assignment: retain the new object, release the old one, delete at zero.
    void AssignChargeTargetLocation(CombatObject* a_new)
    {
        CombatObject* old = spChargeTargetLocation;
        if (old != a_new) {
            if (a_new) {
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&a_new->m_uiRefCount));  // atomic: refcounts are shared across threads
            }
            spChargeTargetLocation = a_new;
            if (old && !_InterlockedDecrement(reinterpret_cast<volatile long*>(&old->m_uiRefCount))) {  // atomic: refcounts are shared across threads
                old->DeleteThis();
            }
        }
    }

    std::uint8_t unk00[0x18];
    CombatObject* spChargeTargetLocation;
};
