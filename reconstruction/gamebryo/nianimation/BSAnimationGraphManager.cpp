// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0xbc0fb0 BSAnimationGraphManager::Functionbc0fb0
// 0xbc0e60 BSAnimationGraphManager::Functionbc0e60
// Adapted bodies: none
#include "BSAnimationGraphManager.h"

// Functionbc2df0, Functionbc1d80: GUESS(low); tail-called targets, no public names
void Functionbc2df0(BSAnimationGraphManager*, void*, void*);
void Functionbc1d80(BSAnimationGraphManager*, void*, void*, void*);

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSAnimationGraphManager::BSAnimationGraphManager()
{
}

// RVA 0xbc3c30, 52 bytes: the destructor is declared in the header only. The target calls the
// complete base destructor first, then tests bit 0 of the flag argument before freeing the object.

void BSAnimationGraphManager::Functionbc0fb0(void* a_arg)
{
    return Functionbc2df0(this, a_arg, reinterpret_cast<char*>(this) + 0x10);
}

void BSAnimationGraphManager::Functionbc0e60(void* a_arg1, void* a_arg2)
{
    return Functionbc1d80(this, a_arg1, a_arg2, reinterpret_cast<char*>(this) + 0x10);
}
