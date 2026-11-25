// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiRefObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low); object size is observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gCount71d300;

class LeafBase71d300
{
public:
    virtual ~LeafBase71d300();
    std::uint64_t objectState;
};
class RefLeaf71d300 : public LeafBase71d300
{
public:
    RefLeaf71d300();
    ~RefLeaf71d300() override;
};
