// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysModifierCtlr: SIBLING(fo4-private@1b765c70, author-permission); name lead, identity unproven
// Stand-in types and fields: GUESS(low); member offsets observed on the target
#pragma once
#include <cstdint>

struct ModifierRef;
struct ModifierRefTable
{
    void* unknown00;
    void (*destroy)(ModifierRef*);
};
struct ModifierRef
{
    ModifierRefTable* table;
    // volatile: the target updates the reference count atomically.
    volatile long count;
};
struct ModifierRefPtr
{
    ~ModifierRefPtr();
    ModifierRef* value;
};
struct ModifierCtlrName
{
    ~ModifierCtlrName();
    void* value;
};
class ModifierCtlrBase
{
public:
    virtual ~ModifierCtlrBase();
    std::uint8_t state[0x40];
};
class RotAccumLeaffa0ab0 : public ModifierCtlrBase
{
public:
    ~RotAccumLeaffa0ab0() override;
    ModifierRefPtr reference;
    ModifierCtlrName name;
};
