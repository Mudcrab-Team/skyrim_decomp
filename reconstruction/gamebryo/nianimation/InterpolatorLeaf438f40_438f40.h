// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiInterpolator: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low); object size is observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gCount438f40;

class LeafBase438f40
{
public:
    virtual ~LeafBase438f40();
    std::uint64_t objectState;
};
class InterpolatorLeaf438f40 : public LeafBase438f40
{
public:
    InterpolatorLeaf438f40();
    ~InterpolatorLeaf438f40() override;
    std::uint64_t storage[1];
};
