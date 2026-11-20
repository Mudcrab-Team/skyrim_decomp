// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpTypedBroadPhaseDispatcher; size 0x218
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkpNullBroadPhaseListener.h"
struct hkpBroadPhaseListener;
struct hkpTypedBroadPhaseDispatcher {
    hkpBroadPhaseListener* m_broadPhaseListeners_0[8][8];
    hkpNullBroadPhaseListener m_nullBroadPhaseListener_200;
};
static_assert(sizeof(hkpTypedBroadPhaseDispatcher) == 536, "hkpTypedBroadPhaseDispatcher layout differs from the PDB");
