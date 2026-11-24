// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiColorData: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); used offsets observed on the target
#pragma once
#include <cstdint>

struct ColorKeyLeaf;
using ColorDelete = void (*)(ColorKeyLeaf*);
extern ColorDelete gColorDeleteTable[];
// volatile: the target updates the object counter atomically.
extern volatile long gColorObjectCount;
class ColorDataBase
{
public:
    virtual ~ColorDataBase();
    std::uint64_t state;
};
class ColorDataLeaff60ca0 : public ColorDataBase
{
public:
    ~ColorDataLeaff60ca0() override;
    std::uint64_t unknown10;
    ColorKeyLeaf* keys;
    std::int32_t type;
};
