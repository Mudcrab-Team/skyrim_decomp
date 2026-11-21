// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x146720 (reconstruction/skyrim_shared/forms/TESFullName.cpp); no external declaration or body reused.
// 0x4d3090 ThunkLeaf4d3090::Forward
// CI hash: 0x4d3090 ?Forward@ThunkLeaf4d3090@@QEBAPEAXXZ
// Adapted bodies: none
#include "ThunkLeaf4d3090.h"

void* ThunkLeaf4d3090::Forward() const
{
    return field08.Get();
}
