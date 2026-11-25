// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiFloatsExtraDataController, IsEqual: SIBLING(fo4-private@1b765c70, author-permission)
// Stand-in types and fields: GUESS(low); only the used member offset is represented
#pragma once
#include <cstdint>

struct ControllerObject { std::uint8_t state[0x60]; };
struct FloatsControllerBase : ControllerObject
{
    bool IsEqual(ControllerObject* other);
};
struct NiFloatsExtraDataController : FloatsControllerBase
{
    bool IsEqual(ControllerObject* other);
    std::uint32_t index;
};
