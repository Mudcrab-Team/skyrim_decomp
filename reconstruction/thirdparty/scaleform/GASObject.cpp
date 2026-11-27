// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xd14810 GASObjectInterface::ToASCharacter
// 0xd12890 GASObject::GASObjectInterface_04
// Adapted bodies: none
#include "GASObject.h"
#include "GFxASCharacter.h"

// Returns this object as a character when its type says it is one, otherwise null.
GFxASCharacter* GASObjectInterface::ToASCharacter()
{
    return GetObjectType() == kObject_ASCharacter ? static_cast<GFxASCharacter*>(this) : nullptr;
}

// CommonLib's slot name; the CrashLogger PDB spells the same slot with a Func prefix.
void GASObject::GASObjectInterface_04(GASEnvironment* a_env, const GASString& a_name, GASValue* a_value)
{
    // The environment form forwards to the string-context form.
    GASObjectInterface_0B(&a_env->stringContext, a_name, a_value);
}
