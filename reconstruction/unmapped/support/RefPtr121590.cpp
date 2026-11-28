// Source exposure: binary-analysis
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr121590::Assign, treated as adapted: shaped like NiPointer::operator= (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x121590 RefPtr121590::Assign
#include "RefPtr121590.h"

// Releases the current pointer and replaces it with the new object pointer.
RefPtr121590& RefPtr121590::Assign(RefObject121590* a_ptr)
{
    if (ptr != nullptr)
    {
        ptr->Release();
    }

    ptr = a_ptr;
    return *this;
}
