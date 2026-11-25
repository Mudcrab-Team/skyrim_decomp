// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfb0500 NiPSysGravityFieldModifier::LoadBinary
#include "NiPSysGravityFieldModifier_fb0500.h"

void NiPSysGravityFieldModifier::LoadBinary(GravityStream& stream)
{
    GravityFieldBase::LoadBinary(stream);
    direction.LoadBinary(stream);
    SetDirection(direction);
}
