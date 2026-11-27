// Source exposure: binary-analysis (class names from the image's RTTI; the destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// RVA 0xf6d700, 62 bytes: BSBlendTreadTransfInterpolator scalar deleting destructor; the inline destructor chains to the out-of-line base destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0xf6d700 ??_GBSBlendTreadTransfInterpolator@@UEAAPEAXI@Z
#include "BSBlendTreadTransfInterpolator_f6d700.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
BSBlendTreadTransfInterpolator::BSBlendTreadTransfInterpolator()
{
}
