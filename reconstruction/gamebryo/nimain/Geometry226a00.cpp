// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: PropPtr226a00::operator= and Property226a00::DecRefCount, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x226a00 Geometry226a00::SetProperty
#include "Geometry226a00.h"

// Attach a property to this geometry and store a reference-counted pointer to it.
void Geometry226a00::SetProperty(Property226a00* prop)
{
    if (prop)
    {
        prop->Attach(this);
    }
    property128 = prop;
}
