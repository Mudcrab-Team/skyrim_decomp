// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: RefPtr222980::~RefPtr222980, treated as adapted: shaped like NiPointer::~NiPointer (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:75, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x222980 Array222980::~Array222980
#include "Array222980.h"

// Destroys every smart-pointer element, deallocates storage, and resets size.
Array222980::~Array222980()
{
    RefPtr222980* current = data;
    if (current != nullptr) {
        std::uint32_t count = base.size;
        for (std::uint32_t i = 0; i < count; ++i) {
            current->~RefPtr222980();
            ++current;
        }
        Deallocate();
        base.size = 0;
    }
}
