// Source exposure: binary-analysis
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr121620::Assign, treated as adapted: shaped like NiPointer::operator= (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x121620 RefPtr121620::Assign
#include "RefPtr121620.h"

// Retains the source reference, releases the current reference, and assigns the pointer.
RefPtr121620& RefPtr121620::Assign(const RefPtr121620& a_rhs)
{
    if (a_rhs.ptr != nullptr)
    {
        a_rhs.ptr->AddRef();
    }

    if (ptr != nullptr)
    {
        ptr->Release();
    }

    ptr = a_rhs.ptr;
    return *this;
}
