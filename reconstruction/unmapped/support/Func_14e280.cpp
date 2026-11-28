// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x14e280 Func_14e280::CopyFieldsFrom
// Adapted bodies: none
#include "Func_14e280.h"

// Copies the payload fields from other when non-null and matching typeTag.
void Func_14e280::CopyFieldsFrom(const Func_14e280* other)
{
    if (!other || other->typeTag != typeTag)
    {
        return;
    }
    field90 = other->field90;
    field94 = other->field94;
    fieldA4 = other->fieldA4;
    field98 = other->field98;
    field9C = other->field9C;
    fieldA0 = other->fieldA0;
    fieldA8 = other->fieldA8;
    fieldB0 = other->fieldB0;
    fieldB8 = other->fieldB8;
}
