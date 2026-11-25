// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf8e5f0 NiBezPosKey::LoadBinary
#include "NiBezPosKey_f8e5f0.h"

void NiBezPosKey::LoadBinary(NiStream& stream)
{
    NiPosKey::LoadBinary(stream);
    incoming.LoadBinary(stream);
    outgoing.LoadBinary(stream);
}
