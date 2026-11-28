// Source exposure: binary-analysis (the pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: BinaryStreamf601e0::Load, treated as adapted: shaped like NiBinaryStream::binary_read (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:23, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf601e0 Targetf601e0::LoadBinary
#include "Targetf601e0.h"

// Reads a single 4-byte field from the binary stream and advances its position counter.
void Targetf601e0::LoadBinary(StreamHolderf601e0& a_stream)
{
    a_stream.binaryStream->Load(&value, sizeof(value), sizeof(value));
}
