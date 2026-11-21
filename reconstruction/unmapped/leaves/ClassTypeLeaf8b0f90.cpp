// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: CC0-1.0
// 0x8b0f90 ClassTypeLeaf8b0f90::QClassType
// Adapted bodies: none
#include "ClassTypeLeaf8b0f90.h"

// Return the lazily initialised class-type object; the compiler emits its guarded local static.
StaticType8b0f90* ClassTypeLeaf8b0f90::QClassType()
{
    static StaticType8b0f90 instance = globalSource8b0f90;
    return &instance;
}
