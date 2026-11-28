// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x12dcd0 TagField::dtor_deleting
// CI hash: 0x12dcd0 ??_GTagField@@UEAAPEAXI@Z
// Adapted bodies: none
#include "TagField.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TagField::TagField()
{
}

// Clears the item vector and destroys base subobjects.
TagField::~TagField()
{
    items.clear();
}
