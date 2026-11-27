// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTextKeyMatch: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gTextKeyLeafCount;
struct TextKeyField
{
    ~TextKeyField();
    void* value;
};
class TextKeyLeafBase
{
public:
    virtual ~TextKeyLeafBase();
    std::uint64_t state;
};
class TextKeyLeaff5b190 : public TextKeyLeafBase
{
public:
    TextKeyLeaff5b190();
    ~TextKeyLeaff5b190() override;
    TextKeyField first;
    TextKeyField second;
};
