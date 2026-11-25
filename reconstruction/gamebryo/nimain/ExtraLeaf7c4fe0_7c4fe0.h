// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low)
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gExtraLeafCount7c4fe0;

struct ExtraStringField7c4fe0
{
    ~ExtraStringField7c4fe0();
    const char* value;
};
class ExtraLeafBase7c4fe0
{
public:
    virtual ~ExtraLeafBase7c4fe0();
    std::uint64_t state;
};
class ExtraLeaf7c4fe0 : public ExtraLeafBase7c4fe0
{
public:
    ExtraLeaf7c4fe0();
    ~ExtraLeaf7c4fe0() override;
    ExtraStringField7c4fe0 name;
    std::uint8_t unknown18[0x18];
};
