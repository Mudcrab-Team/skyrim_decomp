// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf8cf30 BSTreadTransfInterpolator::BSTreadTransfInterpolator
// Adapted bodies: none
#include "BSTreadTransfInterpolator_f8cf30.h"
#include <intrin.h>

BSTreadTransfInterpolator::BSTreadTransfInterpolator(uint32_t a_value, void* a_data, RefObj* a_ref)
    : unk18(a_data), unk20(a_value), unk24(0), unk28(0), unk2C(0), unk30(a_ref)
{
    if (a_ref) {
        // reference counts are shared across threads, so the increment is atomic
        _InterlockedIncrement(&a_ref->refCount);
    }
}
