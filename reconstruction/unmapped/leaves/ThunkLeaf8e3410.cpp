// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x146720 (reconstruction/skyrim_shared/forms/TESFullName.cpp); no external declaration or body reused.
// 0x8e3410 ThunkLeaf8e3410::Forward
// CI hash: 0x8e3410 ?Forward@ThunkLeaf8e3410@@QEBAPEAXXZ
// Adapted bodies: none
#include "ThunkLeaf8e3410.h"

void* ThunkLeaf8e3410::Forward() const
{
    return field08.Get();
}
