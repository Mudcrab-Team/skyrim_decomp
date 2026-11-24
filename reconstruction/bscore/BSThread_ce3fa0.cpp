// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: BSThread::ctor.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/console/bsthread_console.cpp:48
// 0xce3fa0 BSThread::ctor
#include "BSThread_ce3fa0.h"

ctor::ctor()
{
    BSThreadCriticalSectionPC* criticalSection = &CriticalSection;
    Data00fdf054(criticalSection);
    m_pThreadHandle = 0;
    m_pCurrentThreadHandle = 0;
    m_uiCreatedThreadId = 0;
    m_uiCurrentThreadId = 0;
    m_bThreadStarted = false;
}
