// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbVariableBindingSet; size 0x28
#pragma once

#include "hkArray_RE__hkbVariableBindingSet__Binding_b26569b9.h"
#include "hkReferencedObject.h"
struct hkbVariableBindingSet {
    hkReferencedObject _base;
    hkArray_RE__hkbVariableBindingSet__Binding_b26569b9 bindings;
    int indexOfActivationBinding;
    bool needsValueAtActivation;
    unsigned char unk25[3];
};
static_assert(sizeof(hkbVariableBindingSet) == 40, "hkbVariableBindingSet layout differs from the PDB");
