// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiTextKeyMatch: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target.
#pragma once
#include <cstdint>
// volatile: the target updates this counter atomically.
extern volatile long gTextKeyMatchCount;
struct TextMatchNamef5b560
{
    ~TextMatchNamef5b560();
    const char* value;
};
class TextMatchBasef5b560
{
public:
    virtual ~TextMatchBasef5b560();
    std::uint64_t state;
};
class TextKeyMatchLeaff5b560 : public TextMatchBasef5b560
{
public:
    TextKeyMatchLeaff5b560();
    ~TextKeyMatchLeaff5b560() override;
    TextMatchNamef5b560 first;
    TextMatchNamef5b560 second;
};
