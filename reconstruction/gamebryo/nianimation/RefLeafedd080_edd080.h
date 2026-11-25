// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiRefObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low); object size is observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gCountedd080;

class LeafBaseedd080
{
public:
    virtual ~LeafBaseedd080();
    std::uint64_t objectState;
};
class RefLeafedd080 : public LeafBaseedd080
{
public:
    RefLeafedd080();
    ~RefLeafedd080() override;
};
