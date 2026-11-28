// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr1215e0::Clear, treated as adapted: shaped like NiPointer::TryDetach (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:182, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1215e0 RefPtr1215e0::Clear
#include "RefPtr1215e0.h"

// Releases the owned reference-counted object and clears the pointer.
RefPtr1215e0& RefPtr1215e0::Clear()
{
    if (ptr != nullptr)
    {
        ptr->Release();
    }

    ptr = nullptr;
    return *this;
}
