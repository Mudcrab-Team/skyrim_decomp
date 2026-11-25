// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfbba00 NiPSysTurbulenceFieldModifier::NiPSysTurbulenceFieldModifier
#include "NiPSysTurbulenceFieldModifier_fbba00.h"
#include <cfloat>

NiPSysTurbulenceFieldModifier::NiPSysTurbulenceFieldModifier()
    : frequency(0.0f)
{
    lastTime = -FLT_MAX;
    interval = 10000.0f;
}
