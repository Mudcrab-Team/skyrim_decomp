// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysModifierCtlr: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); offsets observed on the target.
#pragma once
#include <cstdint>
void operator delete(void*, unsigned __int64) noexcept;
struct ModifierRefTargetfa0df0;
struct ModifierRefTablefa0df0 { void* unused; void (*destroy)(ModifierRefTargetfa0df0*); };
struct ModifierRefTargetfa0df0
{
    ModifierRefTablefa0df0* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct ModifierRefPtrfa0df0
{
    ~ModifierRefPtrfa0df0();
    ModifierRefTargetfa0df0* value;
};
struct ModifierNamefa0df0
{
    ~ModifierNamefa0df0();
    void* value;
};
class ModifierBasefa0df0
{
public:
    virtual ~ModifierBasefa0df0();
    std::uint8_t state[0x40];
};
class ModifierControllerDtorLeaffa0df0 : public ModifierBasefa0df0
{
public:
    ModifierControllerDtorLeaffa0df0();
    ~ModifierControllerDtorLeaffa0df0() override;
    ModifierRefPtrfa0df0 reference;
    ModifierNamefa0df0 name;
    std::uint64_t unknown58;
};
