// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12dc50 TagField12dc50::~TagField12dc50
// CI hash: 0x12dc50 ??1TagField12dc50@@UEAA@XZ
// Adapted bodies: none
#include "TagField12dc50.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// destructor that is compared (cookbook rule 14).
TagField12dc50::TagField12dc50()
{
}

// Clears the item vector and destroys base subobjects.
TagField12dc50::~TagField12dc50()
{
    items.clear();
}
