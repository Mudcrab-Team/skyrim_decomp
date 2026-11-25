// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysAgeDeathModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
struct AgeNamefa6770
{
    explicit AgeNamefa6770(const char* value);
    ~AgeNamefa6770();
    void* data;
};
class AgeBasefa6770
{
public:
    AgeBasefa6770(const AgeNamefa6770& name, bool enabled);
    virtual ~AgeBasefa6770();
    std::uint8_t state[0x28];
};
class AgeCtorLeaffa6770 : public AgeBasefa6770
{
public:
    AgeCtorLeaffa6770(const char* name, bool enabled, void* spawn);
    bool active;
    void* spawn;
};
