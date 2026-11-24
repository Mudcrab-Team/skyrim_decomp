// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysEmitter, CopyMembers: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct EmitterCloneProcessf9fdc0;
struct EmitterCopyBasef9fdc0
{
    void CopyMembers(EmitterCopyBasef9fdc0* destination, EmitterCloneProcessf9fdc0& process);
    std::uint8_t state[0x34];
};
struct EmitterCopyLeaff9fdc0 : EmitterCopyBasef9fdc0
{
    void CopyMembers(EmitterCopyLeaff9fdc0* destination, EmitterCloneProcessf9fdc0& process);
    std::uint32_t value34;
    std::uint32_t value38;
    std::uint32_t value3c;
    std::uint32_t value40;
    std::uint32_t value44;
    std::uint32_t value48;
    struct Values { std::uint32_t words[4]; } values;
    std::uint32_t value5c;
    std::uint32_t value60;
    std::uint32_t value64;
    std::uint32_t value68;
};
