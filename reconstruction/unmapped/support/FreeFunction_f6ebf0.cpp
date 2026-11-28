// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Functionf6ebf0, treated as adapted: shaped like NiBinaryStream::binary_write (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:32, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf6ebf0 Functionf6ebf0
#include "FreeFunction_f6ebf0.h"

// Saves the payload prefix via helper call, then writes its 4-byte value to the binary stream.
void Functionf6ebf0(StreamHolderf6ebf0* a_stream, const Payloadf6ebf0* a_payload)
{
    SaveHeaderf6ebf0(a_stream, a_payload);
    BinaryStreamf6ebf0* stream = a_stream->writeStream;
    std::uint32_t componentSize = 4;
    stream->currentPos += stream->writeFn(stream, &a_payload->value, 4, &componentSize, 1);
}
