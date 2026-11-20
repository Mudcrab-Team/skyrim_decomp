// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original bodies written from the local listing; declarations from CommonLibSSE-NG.
// Adapted bodies: none
// 0x1576a90 BSLight::Function1576a90
// 0x1578880 BSLight::Unk_03
// 0x1578840 BSLight::~BSLight
#include <intrin.h>

#include "BSLight.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSLight::BSLight()
{
}

// Unk_03: the listing returns false.
bool BSLight::Unk_03()
{
    return false;
}

// The destructor is declared only in the header: the target calls the complete destructor and then
// tests the delete flag, so attempt binds that call to its RVA (cookbook rule 18).

void BSLight::Function1576a90()
{
    RefCountedStandIn* ref = sharedLightRef;
    if (ref) {
        sharedLightRef = nullptr;
        // intrusive release: the count is shared across threads
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&ref->refCount), -1) == 1) {
            ref->DeleteThis();
        }
    }
}
