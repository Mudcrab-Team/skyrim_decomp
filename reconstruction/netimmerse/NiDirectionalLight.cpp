// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none
// 0xf046d0 NiDirectionalLight::~NiDirectionalLight
// 0xf045c0 NiDirectionalLight::UpdateWorldData
// 0xf04710 NiDirectionalLight::GetRTTI
#include "NiDirectionalLight.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
NiDirectionalLight::NiDirectionalLight()
{
}

// UpdateWorldData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
void NiDirectionalLight::UpdateWorldData()
{
    BaseUpdateWorldData();
    copyA = lightA;
    copyB = lightB;
    copyC = lightC;
}

// GetRTTI: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
const NiRTTI* NiDirectionalLight::GetRTTI() const
{
    return &NiRTTI_NiDirectionalLight;
}
