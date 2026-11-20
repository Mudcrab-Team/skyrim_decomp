// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactImpulseLimitBreachedListenerInfo__ListenerData; size 0x20
#pragma once

#include "hkpContactImpulseLimitBreachedListenerInfo__SingleImpulseElem.h"
#include "hkpImpulseLimitBreachedElem.h"
union hkpContactImpulseLimitBreachedListenerInfo__ListenerData {
    hkpImpulseLimitBreachedElem m_solver_0;
    hkpContactImpulseLimitBreachedListenerInfo__SingleImpulseElem m_single_0;
};
static_assert(sizeof(hkpContactImpulseLimitBreachedListenerInfo__ListenerData) == 32, "hkpContactImpulseLimitBreachedListenerInfo__ListenerData layout differs from the PDB");
