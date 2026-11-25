// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfbeff0 BSPSysRecycleBoundModifier::LoadBinary
#include "BSPSysRecycleBoundModifier_fbeff0.h"

void BSPSysRecycleBoundModifier::LoadBinary(RecycleStream& stream)
{
    RecycleModifierBase::LoadBinary(stream);
    offset.LoadBinary(stream);
    extents.LoadBinary(stream);
    stream.ReadLinkID();
}
