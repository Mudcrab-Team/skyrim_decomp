// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpCollisionDispatcher::Routine140B25D00.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/dispatch/hkpcollisiondispatcher.cpp:173
// 0xb35290 hkpCollisionDispatcher::Routine140B25D00
#include "Globals_b35290.h"

void hkpCollisionDispatcher::Routine140B25D00(CFB240ContactMgrFactory* apFactory, int aiResponseIndex)
{
    for (int i = 0; i < 8; i++)
    {
        apFactory->RetainReference();
        m_apContactMgrFactoriesByResponsePair[i][aiResponseIndex]->removeReference();
        m_apContactMgrFactoriesByResponsePair[i][aiResponseIndex] = apFactory;

        apFactory->RetainReference();
        m_apContactMgrFactoriesByResponsePair[aiResponseIndex][i]->removeReference();
        m_apContactMgrFactoriesByResponsePair[aiResponseIndex][i] = apFactory;
    }
}
