// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1558e0 Func_1558e0::CopyFrom
// Adapted bodies: none
#include "Func_1558e0.h"

// Copies nine data fields from other when non-null and matching formType.
void Func_1558e0::CopyFrom(const Func_1558e0* other)
{
    if (other != nullptr && other->formType == formType)
    {
        fieldC0 = other->fieldC0;
        fieldC4 = other->fieldC4;
        fieldC8 = other->fieldC8;
        fieldD0 = other->fieldD0;
        fieldCC = other->fieldCC;
        fieldD4 = other->fieldD4;
        fieldD8 = other->fieldD8;
        fieldDC = other->fieldDC;
        fieldE0 = other->fieldE0;
    }
}
