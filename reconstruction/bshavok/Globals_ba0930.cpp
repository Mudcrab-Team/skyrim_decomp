// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ahkpCharacterProxy::Routine140AC2340.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/utilities/charactercontrol/characterproxy/hkpcharacterproxy.cpp:136
// 0xba0930 ahkpCharacterProxy::Routine140AC2340
#include "Globals_ba0930.h"

void ahkpCharacterProxy::Routine140AC2340(void* data)
{
    for (int i = m_numListeners - 1; i >= 0; i--)
        m_kListeners[i]->notify(this, data);
}
