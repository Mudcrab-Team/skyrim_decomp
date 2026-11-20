// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2f8ea0 BSHandleRefObject::~BSHandleRefObject
// Adapted bodies: none
#include "BSHandleRefObject_2f8ea0.h"

BSHandleRefObject::BSHandleRefObject() = default;
BSHandleRefObject::~BSHandleRefObject()
{
    refCount &= 0x3FF;
}
