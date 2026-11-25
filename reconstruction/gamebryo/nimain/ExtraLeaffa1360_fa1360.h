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
class ExtraLeaffa1360 : public ExtraLeafBase
{
public:
    ExtraLeaffa1360();
    ~ExtraLeaffa1360() override;
    ExtraStringField name;
};
