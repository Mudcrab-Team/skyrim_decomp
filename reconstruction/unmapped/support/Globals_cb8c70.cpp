// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkaCGSolver_float_ScaleAdd_00e58960.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00e40000_o2_rtm_variant.cpp:3582
// 0xcb8c70 hkaCGSolver_float_ScaleAdd_00e58960
#include "Globals_cb8c70.h"

void hkaCGSolver_float_ScaleAdd_00e58960(
    Func00e587b0_Class* obj,
    float* factor,
    Func00e58880_Class* values)
{
    int count = reinterpret_cast<Func00e58890_Class*>(obj)->EvaluateValue_00e58890();
    for (int i = 0; i < count; ++i) {
        float* destination =
            reinterpret_cast<float*>(obj->GetElementAddress_00e587b0(i));
        *destination = values->GetIndexedValue_00e58880(i) * *factor + *destination;
    }
}
