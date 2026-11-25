// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiRefObject: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low); object size is observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gCountf009d0;

class LeafBasef009d0
{
public:
    virtual ~LeafBasef009d0();
    std::uint64_t objectState;
};
class RefLeaff009d0 : public LeafBasef009d0
{
public:
    RefLeaff009d0();
    ~RefLeaff009d0() override;
};
