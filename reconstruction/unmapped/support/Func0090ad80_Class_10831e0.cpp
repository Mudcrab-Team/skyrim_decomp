// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: f3m_0090ad80::task0983::Func0090ad80_Class::Func0090ad80.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00900000_o2.cpp:8067
// 0x10831e0 f3m_0090ad80::task0983::Func0090ad80_Class::Func0090ad80
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectrefr_o2_variant.cpp:1481
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00900000_o2.cpp:8017
// Adapted helpers: GetAction
// CI hash: 0x10831e0 ?Func0090ad80@Func0090ad80_Class@task0983@f3m_0090ad80@@QEAA_NXZ
#include "Func0090ad80_Class_10831e0.h"

namespace f3m_0090ad80 {
namespace task0983 {
bool Func0090ad80_Class::Func0090ad80()
{
    bool result = false;
    LinkedObject* linked = ResolveLinkedObject();
    PhysicsAction* action = linked ? linked->GetAction() : 0;
    if (action)
        result = action->Func008d5fe0(handle);
    return result;
}
}
}
