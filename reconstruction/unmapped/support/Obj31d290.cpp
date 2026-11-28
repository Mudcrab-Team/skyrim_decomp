// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj31d290::~Obj31d290, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x31d290 Obj31d290::~Obj31d290
#include "Obj31d290.h"

// Guess: deallocate array elements when present and clear size before base destruction.
Obj31d290::~Obj31d290()
{
    if (m_data)
    {
        Deallocate();
        m_size = 0;
    }
}
