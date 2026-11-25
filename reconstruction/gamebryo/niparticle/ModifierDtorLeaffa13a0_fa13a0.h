// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysModifier: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in names: GUESS(low)
#pragma once
#include <cstdint>

// volatile: the target updates this counter atomically.
extern volatile long gModifierDtorCountfa13a0;

struct ModifierNamefa13a0
{
    ~ModifierNamefa13a0();
    const char* value;
};
class ModifierDtorBasefa13a0
{
public:
    virtual ~ModifierDtorBasefa13a0();
    std::uint64_t state;
};
class ModifierDtorLeaffa13a0 : public ModifierDtorBasefa13a0
{
public:
    ModifierDtorLeaffa13a0();
    ~ModifierDtorLeaffa13a0() override;
    ModifierNamefa13a0 name;
    std::uint8_t remaining[0x18];
};
