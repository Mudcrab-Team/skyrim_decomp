// Source exposure: mixed
// Adapted bodies: none
// Code origin: handwritten from local target observations; community declarations only.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiLookAtInterpolator, GetSequenceInterpolator: CRASHLOGGER_PDB(59818@2026.10.24)
// Cookbook: 0xf80f90 5
// 0xf80f90 NiLookAtInterpolator::GetSequenceInterpolator
#include "NiLookAtInterpolator_f80f90.h"

// Extract the time interval for every populated component interpolator.
NiInterpolator* NiLookAtInterpolator::GetSequenceInterpolator(float start, float end)
{
    NiLookAtInterpolator* result = static_cast<NiLookAtInterpolator*>(NiInterpolator::GetSequenceInterpolator(start, end));
    for (unsigned int i = 0; i < 3; ++i)
    {
        if (m_aspInterpolators[i])
        {
            NiInterpolator* replacement = m_aspInterpolators[i]->GetSequenceInterpolator(start, end);
            NiInterpolator* old = result->m_aspInterpolators[i];
            if (old != replacement)
            {
                if (replacement)
                {
                    // Shared intrusive ownership requires an atomic reference count.
                    _InterlockedIncrement(&replacement->_refCount);
                }
                result->m_aspInterpolators[i] = replacement;
                if (old)
                {
                    // Shared intrusive ownership releases the final reference atomically.
                    if (_InterlockedDecrement(&old->_refCount) == 0)
                    {
                        old->DeleteThis();
                    }
                }
            }
        }
    }
    return result;
}
