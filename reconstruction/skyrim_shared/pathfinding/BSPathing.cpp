// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x11c52e0 BSPathing::~BSPathing
// Adapted bodies: none
#include "BSPathing.h"

void* BSPathingFilter::instance = nullptr;

// Not compared: the subobject's teardown. The target emits its vftable store at +0x08 and the
// global clear before the deleting test, which is where this destructor's work lands.
BSPathingFilter::~BSPathingFilter()
{
    instance = nullptr;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BSPathing::BSPathing()
{
}

// The body is empty; the member destructor carries the clear.
BSPathing::~BSPathing()
{
}
