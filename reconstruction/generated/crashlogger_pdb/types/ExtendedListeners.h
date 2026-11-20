// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtendedListeners; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4_c7370492.h"
#include "hkSmallArray_RE__hkpEntityListener_3222427a_990a0274.h"
struct ExtendedListeners {
    hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4_c7370492 activationListeners;
    hkSmallArray_RE__hkpEntityListener_3222427a_990a0274 entityListeners;
};
static_assert(sizeof(ExtendedListeners) == 32, "ExtendedListeners layout differs from the PDB");
