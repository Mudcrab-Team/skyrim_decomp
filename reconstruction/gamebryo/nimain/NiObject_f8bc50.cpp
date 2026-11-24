// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf8bc50 BSLookIKNote::BSLookIKNote
// Adapted bodies: none
#include "NiObject_f8bc50.h"

BSLookIKNote::BSLookIKNote(float a_time) :
    BSAnimNote(a_time)
{
    m_eType = 2;
    m_fDistanceScale = 0.0f;
    eState = 0;
}
