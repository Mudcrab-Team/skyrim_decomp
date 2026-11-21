// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: CC0-1.0
// 0x122bed0 ClassTypeLeaf122bed0::QClassType
// Adapted bodies: none
#include "ClassTypeLeaf122bed0.h"

// Return the lazily initialised class-type object; the compiler emits its guarded local static.
StaticType122bed0* ClassTypeLeaf122bed0::QClassType()
{
    static StaticType122bed0 instance = globalSource122bed0;
    return &instance;
}
