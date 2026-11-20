// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtendedListeners; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4.h"
#include "hkSmallArray_RE__hkpEntityListener_3222427a.h"
struct ExtendedListeners_9c17781f {
    hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4 activationListeners;
    hkSmallArray_RE__hkpEntityListener_3222427a entityListeners;
};
static_assert(sizeof(ExtendedListeners_9c17781f) == 32, "ExtendedListeners_9c17781f layout differs from the PDB");
