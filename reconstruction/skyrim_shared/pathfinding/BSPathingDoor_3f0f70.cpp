// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0x3f0f70 BSPathingDoor::Unk_02
#include "BSPathingDoor_3f0f70.h"

// Notifies the incoming target of any previously stored target, then replaces it.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BSPathingDoor::Unk_02(PathingTarget3f0f70* next)
{
    if (unk58)
    {
        next->Unk_04(unk58);
    }
    unk58 = next;
}
