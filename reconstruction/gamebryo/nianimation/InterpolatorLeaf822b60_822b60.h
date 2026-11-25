// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low); object size is observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gCount822b60;

class LeafBase822b60
{
public:
    virtual ~LeafBase822b60();
    std::uint64_t objectState;
};
class InterpolatorLeaf822b60 : public LeafBase822b60
{
public:
    InterpolatorLeaf822b60();
    ~InterpolatorLeaf822b60() override;
    std::uint64_t storage[1];
};
