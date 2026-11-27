// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorExtraData, NiColorA: SIBLING(fo4-private@1b765c70, author-permission)
// NiExtraData layout: CRASHLOGGER_PDB(59818@2026.10.24)
// Member names: GUESS(low); stand-ins for the observed fields
#pragma once
#include <cstdint>

struct NiColorA { float red, green, blue, alpha; };
class NiExtraData
{
public:
    NiExtraData();
    virtual ~NiExtraData();
    std::uint64_t state[2];
};
class NiColorExtraData : public NiExtraData
{
public:
    explicit NiColorExtraData(NiColorA color);
    NiColorA value;
};
