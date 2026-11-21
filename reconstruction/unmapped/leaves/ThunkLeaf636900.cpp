// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x146720 (reconstruction/skyrim_shared/forms/TESFullName.cpp); no external declaration or body reused.
// 0x636900 ThunkLeaf636900::Forward
// CI hash: 0x636900 ?Forward@ThunkLeaf636900@@QEBAPEAXXZ
// Adapted bodies: none
#include "ThunkLeaf636900.h"

void* ThunkLeaf636900::Forward() const
{
    return field08.Get();
}
