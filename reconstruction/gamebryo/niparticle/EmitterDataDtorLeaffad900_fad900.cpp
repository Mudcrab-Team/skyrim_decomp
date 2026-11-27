// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xfad900 EmitterDataDtorLeaffad900::~EmitterDataDtorLeaffad900
#include "EmitterDataDtorLeaffad900_fad900.h"
#include <intrin.h>

EmitterDataBasefad900::~EmitterDataBasefad900()
{
    // The reference-object counter is updated atomically.
    // The reference-object counter is updated atomically.
    _InterlockedDecrement(&gEmitterDataCountfad900);
}
EmitterDataDtorLeaffad900::~EmitterDataDtorLeaffad900()
{
    if (first) {
        gEmitterKeyDestroyersfad900[firstType](first);
    }
    if (second) {
        (gEmitterKeyDestroyersfad900 + 30)[secondType](second);
    }
}
