// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xf261c0 NiOBBRoot::Func1_140CA81B0
#include "NiOBBRoot_f261c0.h"

// Delegates OBB collision testing against another root to the underlying tree node.
bool NiOBBRoot::Func1_140CA81B0(
    NiOBBRoot* a_other,
    void* a_arg2,
    void* a_arg3,
    std::uint32_t a_arg4,
    std::uint32_t a_arg5)
{
    if (this == a_other)
    {
        return false;
    }

    return rootNode->TestCollision(
        a_other->rootNode,
        a_arg2,
        a_arg3,
        a_arg4,
        a_arg5,
        deltaTime,
        a_other->deltaTime);
}
