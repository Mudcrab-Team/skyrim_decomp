// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj309f90::RemoveAll and the inline destructor, treated as adapted: shaped like BSSimpleList<T>::RemoveAll and the same loop in BSSimpleList in the sibling source cited below (CC0-1.0); the callback branch has the same shape as the repository unit bscore/BSSimpleList_14c550.h.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bscore/bssimplelist.inl:62
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// SPDX-License-Identifier: CC0-1.0
// 0x309f90 Obj309f90::RemoveAll
#include "Obj309f90.h"

// Guess: iteratively unlink and destroy all tail nodes of the singly linked list.
void Obj309f90::RemoveAll(FreeFn a_freeFn, void* a_context)
{
    while (m_next)
    {
        Obj309f90* next = m_next->m_next;
        m_next->m_next = nullptr;
        if (a_freeFn)
        {
            a_freeFn(m_next, a_context);
        }
        else
        {
            delete m_next;
        }
        m_next = next;
    }
    m_item = nullptr;
}
