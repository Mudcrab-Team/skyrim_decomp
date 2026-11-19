// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only. The destructor body is empty; the image stores the vtable and frees the 0x20-byte object, which the compiler generates.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeae180 NiBinaryStream::tell
// 0xeae4a0 NiBinaryStream::~NiBinaryStream
// Adapted bodies: none
#include "NiBinaryStream.h"

NiBinaryStream::NiBinaryStream()
{
}

NiBinaryStream::~NiBinaryStream()
{
}

std::uint32_t NiBinaryStream::tell() const
{
    return _absoluteCurrentPos;
}
