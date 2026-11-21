// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original; the pinned image listing and the matched static-accessor shape only
// 0x462720 ClassTypeLeaf462720::QClassType
// Adapted bodies: none
// ClassTypeLeaf462720, ClassTypeLeaf462720::QClassType: GUESS(low)
// BSFixedString: STANDIN GUESS(low)
#include "ClassTypeLeaf462720.h"

const BSFixedString& ClassTypeLeaf462720::QClassType()
{
    static BSFixedString typeString("ClassTypeLeaf462720");
    return typeString;
}
