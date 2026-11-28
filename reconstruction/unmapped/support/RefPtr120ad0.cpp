// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr120ad0::~RefPtr120ad0, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x120ad0 RefPtr120ad0::~RefPtr120ad0
#include "RefPtr120ad0.h"

// Releases the owned reference-counted object if non-null.
RefPtr120ad0::~RefPtr120ad0()
{
    if (ptr != nullptr)
    {
        ptr->Release();
    }
}
