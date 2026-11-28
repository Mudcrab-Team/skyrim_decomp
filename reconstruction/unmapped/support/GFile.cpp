// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x120d10 GFile::dtor
// CI hash: 0x120d10 ??_GGFile@@UEAAPEAXI@Z
// Adapted bodies: none
#include "GFile.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
GFile::GFile()
{
}
