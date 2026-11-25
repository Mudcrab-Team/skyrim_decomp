// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiExtraData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// NiExtraData layout: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in names: GUESS(low)
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gExtraLeafCount;

struct ExtraStringField
{
    ~ExtraStringField();
    const char* value;
};
class ExtraLeafBase
{
public:
    virtual ~ExtraLeafBase();
    std::uint64_t state;
};
class ExtraLeaf7c4da0 : public ExtraLeafBase
{
public:
    ExtraLeaf7c4da0();
    ~ExtraLeaf7c4da0() override;
    ExtraStringField name;
};
