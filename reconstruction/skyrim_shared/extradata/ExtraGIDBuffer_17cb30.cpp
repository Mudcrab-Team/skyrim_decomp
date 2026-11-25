// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x17cb30 ExtraGIDBuffer::~ExtraGIDBuffer (scalar deleting destructor)
#include "ExtraGIDBuffer_17cb30.h"
ExtraGIDBuffer::ExtraGIDBuffer() : buffer(nullptr), opaque18(0) { next = nullptr; }
ExtraGIDBuffer::~ExtraGIDBuffer()
{
    ::operator delete(buffer, 1);
}
