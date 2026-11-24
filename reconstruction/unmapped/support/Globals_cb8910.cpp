// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkaCGSolver_float_CopyNegative.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00e40000_o2_rtm_variant.cpp:3599
// 0xcb8910 hkaCGSolver_float_CopyNegative
#include "Globals_cb8910.h"

void hkaCGSolver_float_CopyNegative(Func00e587b0_Class* p, Func00e58880_Class* q)
{
    int count = EvaluateValue_00e58890(p);
    for (int i = 0; i < count; ++i)
    {
        float* dst = reinterpret_cast<float*>(p->GetElementAddress_00e587b0(i));
        *dst = -q->GetIndexedValue_00e58880(i);
    }
}
