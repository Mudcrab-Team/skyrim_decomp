// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfa13a0 ModifierDtorLeaffa13a0::~ModifierDtorLeaffa13a0
#include "ModifierDtorLeaffa13a0_fa13a0.h"
#include <intrin.h>


ModifierDtorBasefa13a0::~ModifierDtorBasefa13a0()
{
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gModifierDtorCountfa13a0);
}

ModifierDtorLeaffa13a0::ModifierDtorLeaffa13a0() = default;
ModifierDtorLeaffa13a0::~ModifierDtorLeaffa13a0() = default;
