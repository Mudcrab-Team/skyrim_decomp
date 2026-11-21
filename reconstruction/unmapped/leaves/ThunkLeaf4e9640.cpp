// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x146720 (reconstruction/skyrim_shared/forms/TESFullName.cpp); no external declaration or body reused.
// 0x4e9640 ThunkLeaf4e9640::Forward
// CI hash: 0x4e9640 ?Forward@ThunkLeaf4e9640@@QEBAPEAXXZ
// Adapted bodies: none
#include "ThunkLeaf4e9640.h"

void* ThunkLeaf4e9640::Forward() const
{
    return field08.Get();
}
