// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysEmitterCtlr: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct EmitterRefTargetf9b820;
struct EmitterRefTablef9b820 { void* unused; void (*destroy)(EmitterRefTargetf9b820*); };
struct EmitterRefTargetf9b820
{
    EmitterRefTablef9b820* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct EmitterControllerLeaff9b820
{
    void SetInterpolator(EmitterRefTargetf9b820* value, std::uint16_t index);
    std::uint8_t unknown00[0x48];
    EmitterRefTargetf9b820* first;
    std::uint8_t unknown50[0x10];
    EmitterRefTargetf9b820* second;
};
