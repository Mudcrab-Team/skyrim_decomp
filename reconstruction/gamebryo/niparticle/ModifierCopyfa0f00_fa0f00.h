// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiPSysModifier, CopyMembers, NiCloningProcess: SIBLING(fo4-private@1b765c70, author-permission)
// NiPSysModifier layout: CRASHLOGGER_PDB(59818@2026.10.24)
// Stand-in names: GUESS(low); the original owner is unconfirmed
#pragma once
#include <cstdint>

struct NiCloningProcess;
struct ModifierCopyBase
{
    void CopyMembers(ModifierCopyBase* destination, NiCloningProcess& process);
    std::uint64_t state[2];
};
struct ModifierName
{
    ModifierName& operator=(const ModifierName& other);
    void* value;
};
struct ModifierCopyfa0f00 : ModifierCopyBase
{
    void CopyMembers(ModifierCopyfa0f00* destination, NiCloningProcess& process);
    ModifierName name;
    std::uint32_t order;
    std::uint32_t unknown1c;
    void* target;
    bool active;
};
