// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiControllerManager, PostLinkObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offsets observed on the target
#pragma once
#include <cstdint>

struct ManagerStream;
struct ManagerSequence { void SetTarget(void* target); };
struct ManagerPostLinkBase
{
    void PostLinkObject(ManagerStream& stream);
    std::uint8_t state[0x38];
};
struct ManagerPostLinkLeaff527f0 : ManagerPostLinkBase
{
    void PostLinkObject(ManagerStream& stream);
    void* target;
    std::uint8_t unknown40[0x10];
    ManagerSequence** sequences;
    std::uint16_t capacity;
    std::uint16_t count;
};
