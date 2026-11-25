// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiObject, NiBSplineBasisData, CopyMembers, IsEqual, NiCloningProcess: SIBLING(fo4-private@1b765c70, author-permission)
// NiBSplineBasisData size: CRASHLOGGER_PDB(59818@2026.10.24); name lead, identity unproven
// Storage names: GUESS(low)
// BasisEqualLeaff76750, BasisEqualBase: GUESS(low); stand-in names
#pragma once

#include <cstdint>

struct NiCloningProcess;
struct BasisEqualBase
{
    void CopyMembers(BasisEqualBase* destination, NiCloningProcess& process);
    bool IsEqual(BasisEqualBase* other);
    std::uint64_t objectStorage[2];
};

struct BasisEqualLeaff76750 : BasisEqualBase
{
    void CopyMembers(BasisEqualLeaff76750* destination, NiCloningProcess& process);
    bool IsEqual(BasisEqualBase* other);
    struct BasisStorage
    {
        std::int32_t count;
        float weights[4];
        float lastTime;
        std::int32_t first, last;
    } basis;
};
