// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiRefObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low); object size is observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gCount71d190;

class LeafBase71d190
{
public:
    virtual ~LeafBase71d190();
    std::uint64_t objectState;
};
class RefLeaf71d190 : public LeafBase71d190
{
public:
    RefLeaf71d190();
    ~RefLeaf71d190() override;
};
