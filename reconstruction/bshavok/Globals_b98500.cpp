// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpCharacterStateManager::Routine140AB9F10.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp:19
// 0xb98500 hkpCharacterStateManager::Routine140AB9F10
#include "Globals_b98500.h"

void hkpCharacterStateManager::Routine140AB9F10(hkReferencedObject* object, int index)
{
    object->RetainReference();
    if (m_states[index])
        m_states[index]->removeReference();
    m_states[index] = object;
}
