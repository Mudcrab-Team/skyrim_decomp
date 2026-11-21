// Source exposure: binary-analysis (the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; drafted from the pinned image listing
// 0x8cfc20 ClassTypeLeaf8cfc20::QClassType
// Adapted bodies: none
#include "ClassTypeLeaf8cfc20.h"

ClassTypeLeaf8cfc20::StaticValue* ClassTypeLeaf8cfc20::QClassType()
{
    static StaticValue value("standin");
    return &value;
}
