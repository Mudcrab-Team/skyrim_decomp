// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbVariableValueSet; size 0x40
#pragma once

#include "hkArray_RE__hkRefVariant_9938e2d5.h"
#include "hkArray_RE__hkVector4_8268593c.h"
#include "hkArray_RE__hkbVariableValue_c4bff312.h"
#include "hkReferencedObject.h"
struct hkbVariableValueSet {
    hkReferencedObject _base;
    hkArray_RE__hkbVariableValue_c4bff312 m_wordVariableValues;
    hkArray_RE__hkVector4_8268593c m_quadVariableValues;
    hkArray_RE__hkRefVariant_9938e2d5 m_variantVariableValues;
};
static_assert(sizeof(hkbVariableValueSet) == 64, "hkbVariableValueSet layout differs from the PDB");
