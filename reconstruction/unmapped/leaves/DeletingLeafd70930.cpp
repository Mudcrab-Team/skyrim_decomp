// Source exposure: binary-analysis and pinned image listing.
// Code origin: original; the empty virtual destructor is inferred from the deleting destructor listing.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xd70930 DeletingLeafd70930::~DeletingLeafd70930
#include "DeletingLeafd70930.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
DeletingLeafd70930::DeletingLeafd70930()
{
}
