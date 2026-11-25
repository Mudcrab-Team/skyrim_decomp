// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController, IsEqual: SIBLING(fo4-private@1b765c70, author-permission)
// Stand-in types and fields: GUESS(low); only the used member offset is represented
#pragma once
#include <cstdint>

struct ControllerObjectf7cf50 { std::uint8_t state[0x60]; };
struct FloatsControllerBasef7cf50 : ControllerObjectf7cf50
{
    bool IsEqual(ControllerObjectf7cf50* other);
};
struct FloatsControllerLeaff7cf50 : FloatsControllerBasef7cf50
{
    bool IsEqual(ControllerObjectf7cf50* other);
    std::uint32_t index;
};
