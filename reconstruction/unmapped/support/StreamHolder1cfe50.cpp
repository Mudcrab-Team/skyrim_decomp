// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: StreamHolder1cfe50::WriteBlock1cfe50, treated as adapted: shaped like NiBinaryStream::binary_write (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:32, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1cfe50 StreamHolder1cfe50::WriteBlock1cfe50
#include "StreamHolder1cfe50.h"

// Writes a byte block through the backing binary stream and updates errorCode.
// A short write calls _errno, discards the pointer and records error 10.
std::uint32_t StreamHolder1cfe50::WriteBlock1cfe50(const void* a_data, std::uint32_t a_size)
{
    if (!a_data) {
        errorCode = 0;
        return 0;
    }

    BinaryStream1cfe50* targetStream = stream;
    std::uint32_t elementSize = 1;
    std::uint32_t written = targetStream->writeFn(targetStream, a_data, a_size, &elementSize, 1);
    targetStream->position += written;
    if (written < a_size) {
        _errno();
        errorCode = 10;
        return 10;
    }

    errorCode = 0;
    return 0;
}
