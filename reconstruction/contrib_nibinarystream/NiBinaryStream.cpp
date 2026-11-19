// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations. The three bodies below are trivial and match the community ones.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeae180 NiBinaryStream::tell
// 0xeae4a0 NiBinaryStream::~NiBinaryStream
// Adapted bodies: NiBinaryStream::NiBinaryStream, NiBinaryStream::~NiBinaryStream and NiBinaryStream::tell (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp, MIT; empty bodies and a one-line getter, notice in the SPDX line above).
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
