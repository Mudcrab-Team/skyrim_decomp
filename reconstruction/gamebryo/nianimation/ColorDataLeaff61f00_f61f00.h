// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offsets observed on the target
#pragma once
#include <cstdint>

struct ColorKeyLeaff61f00;
using ColorDeletef61f00 = void (*)(ColorKeyLeaff61f00*);
extern ColorDeletef61f00 gColorDeletef61f00Table[];
// volatile: the target updates the object counter atomically.
extern volatile long gColorObjectCountf61f00;
class ColorDataBasef61f00
{
public:
    virtual ~ColorDataBasef61f00();
    std::uint64_t state;
};
class ColorDataLeaff61f00 : public ColorDataBasef61f00
{
public:
    ~ColorDataLeaff61f00() override;
    std::uint64_t unknown10;
    ColorKeyLeaff61f00* keys;
    std::int32_t type;
};
