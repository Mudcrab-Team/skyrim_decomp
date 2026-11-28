// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xd380d0 GFxASCharacter::GASObjectInterface_Func10
#include "GFxASCharacter_d380d0.h"

// Forwards the object-interface operation using the character's ActionScript environment.
bool GFxASCharacter::GASObjectInterface_Func10(GASEnvironment*, void* arg1, void* arg2, void* arg3)
{
    return ForwardMember(GetASEnvironment(), arg1, arg2, arg3);
}
