// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12a7d0 Function12a7d0
// Adapted bodies: none
#include "FreeFunction_12a7d0.h"

// Clones the source callable implementation into destination storage if non-null.
void Function12a7d0(FuncStorage12a7d0* a_dst, const FuncStorage12a7d0* a_src)
{
    if (a_src->impl != nullptr)
    {
        a_dst->impl = a_src->impl->Copy(a_dst);
    }
}
